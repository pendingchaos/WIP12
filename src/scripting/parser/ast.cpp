#include "scripting/parser/ast.h"

//TODO: ...args
//TODO: scope {...}
//TODO: function() {...} with x, y->z, z->y
//- Make this a method? (function() {}):with("x", x):with("y", z):with("z": y)
namespace scripting
{
    static void getArgs(LROpNode *args, CallNode *call)
    {
        if (args->left->type == ASTNode::Comma)
        {
            getArgs((LROpNode *)args->left, call);
        } else
        {
            call->addArg(args->left);
        }

        if (args->right->type == ASTNode::Comma)
        {
            getArgs((LROpNode *)args->right, call);
        } else
        {
            call->addArg(args->right);
        }

        operator delete(args); //Mwahahahaha
    }

    static void getFuncArgs(LROpNode *args, FunctionNode *func)
    {
        if (args->left->type == ASTNode::Comma)
        {
            getFuncArgs((LROpNode *)args->left, func);
        } else if (args->left->type == ASTNode::Identifier)
        {
            func->args.append(((IdentifierNode *)args->left)->name);
            DELETE(args->left);
        } else
        {
            THROW(ParseException, "Invalid argument name.", 0, 0); //TODO: More info
        }

        if (args->right->type == ASTNode::Identifier)
        {
            func->args.append(((IdentifierNode *)args->right)->name);
            DELETE(args->right);
        } else
        {
            THROW(ParseException, "Invalid argument name.", 0, 0); //TODO: More info
        }

        operator delete(args); //Mwahahahaha
    }

    static void getStatements(LROpNode *node, StatementsNode *statements)
    {
        if (node->left->type == ASTNode::StatementSplit)
        {
            getStatements((LROpNode *)node->left, statements);
        } else
        {
            statements->addStatement(node->left);
        }

        if (node->right->type == ASTNode::StatementSplit)
        {
            getStatements((LROpNode *)node->right, statements);
        } else
        {
            statements->addStatement(node->right);
        }

        operator delete(node); //Mwahahahaha
    }

    class Parser;

    static StatementsNode *getStatements(Parser *parser);

    static int getPrecedence(Token::Type type, size_t line, size_t column)
    {
        switch (type)
        {
        case Token::Dot:
        case Token::Colon:
        {
            return 10;
        }
        case Token::Assign:
        {
            return 4;
        }
        case Token::Add:
        case Token::Subtract:
        case Token::BoolAnd:
        case Token::BoolOr:
        case Token::BitAnd:
        case Token::BitOr:
        case Token::BitXOr:
        {
            return 8;
        }
        case Token::Multiply:
        case Token::Divide:
        case Token::Modulo:
        {
            return 9;
        }
        case Token::Less:
        case Token::Greater:
        {
            return 6;
        }
        case Token::Equal:
        case Token::NotEqual:
        {
            return 5;
        }
        case Token::LessEqual:
        case Token::GreaterEqual:
        {
            return 6;
        }
        case Token::LeftShift:
        case Token::RightShift:
        {
            return 7;
        }
        case Token::Comma:
        {
            return 2;
        }
        case Token::LeftParen:
        case Token::LeftBracket:
        {
            return 10;
        }
        case Token::EndStatement:
        {
            return 1;
        }
        case Token::RightParen:
        case Token::RightBrace:
        case Token::RightBracket:
        case Token::LeftBrace:
        {
            return 0;
        }
        default:
        {
            THROW(ParseException, "Unexpected token.", line, column);
        }
        }
    }

    static int getPrecedence(const Token& token)
    {
        return getPrecedence(token.type, token.line, token.column);
    }

    static int getUnaryPrecedence(Token::Type type, size_t line, size_t column)
    {
        switch (type)
        {
        case Token::Add:
        case Token::Subtract:
        case Token::BoolNot:
        case Token::BitNot:
        {
            return 9;
        }
        case Token::Return:
        case Token::Throw:
        {
            return 3;
        }
        default:
        {
            THROW(ParseException, "Unexpected token.", line, column);
        }
        }
    }

    class Parser
    {
        public:
            Parser(const List<Token>& tokens_) : tokens(tokens_), offset(0) {}

            const Token& peek() const
            {
                return tokens[offset];
            }

            const Token& get()
            {
                return tokens[offset++];
            }

            inline bool atEnd() const
            {
                return offset == tokens.getCount();
            }

            ASTNode *parse(int precedence=-1)
            {
                ASTNode *left = parsePrefix(get());

                while (atEnd() ?
                       false :
                       precedence < getPrecedence(peek()))
                {
                    left = parseInfix(left, get());
                }

                return left;
            }
        private:
            List<Token> tokens;
            size_t offset;

            ASTNode *parsePrefix(const Token& token)
            {
                ASTNode *result = nullptr;

                switch (token.type)
                {
                case Token::Identifier:
                {
                    result = NEW(IdentifierNode, token.str);
                    break;
                }
                case Token::Integer:
                {
                    int64_t v = strtoll(token.str.getData(), nullptr, 10);
                    result = NEW(IntegerNode, v);
                    break;
                }
                case Token::BinInteger:
                {
                    int64_t v = strtoll(token.str.getData()+2, nullptr, 2);
                    result = NEW(IntegerNode, v);
                    break;
                }
                case Token::HexInteger:
                {
                    int64_t v = strtoll(token.str.getData()+2, nullptr, 16);
                    result = NEW(IntegerNode, v);
                    break;
                }
                case Token::Float:
                case Token::ScientificFloat:
                {
                    double v = strtod(token.str.getData(), nullptr);
                    result = NEW(FloatNode, v);
                    break;
                }
                case Token::String:
                {
                    result = NEW(StringNode, token.str.subStr(1, token.str.getLength()-2));
                    break;
                }
                case Token::True:
                {
                    result = NEW(ASTNode, ASTNode::True);
                    break;
                }
                case Token::False:
                {
                    result = NEW(ASTNode, ASTNode::False);
                    break;
                }
                case Token::Nil:
                {
                    result = NEW(ASTNode, ASTNode::Nil);
                    break;
                }
                case Token::LeftParen:
                {
                    result = parse(getPrecedence(Token::RightParen, 0, 0));
                    get(); //Skip ')'
                    break;
                }
                case Token::Subtract:
                {
                    result = NEW(SingleOperandNode,
                                 ASTNode::Negate,
                                 parse(getUnaryPrecedence(Token::Subtract, 0, 0)));
                    break;
                }
                case Token::Return:
                {
                    result = NEW(SingleOperandNode,
                                 ASTNode::Return,
                                 parse(getUnaryPrecedence(Token::Return, 0, 0)));
                    break;
                }
                case Token::BoolNot:
                {
                    result = NEW(SingleOperandNode,
                                 ASTNode::BoolNot,
                                 parse(getUnaryPrecedence(Token::BoolNot, 0, 0)));
                    break;
                }
                case Token::BitNot:
                {
                    result = NEW(SingleOperandNode,
                                 ASTNode::BitNot,
                                 parse(getUnaryPrecedence(Token::BitNot, 0, 0)));
                    break;
                }
                case Token::Throw:
                {
                    result = NEW(SingleOperandNode,
                                 ASTNode::Throw,
                                 parse(getUnaryPrecedence(Token::Throw, 0, 0)));
                    break;
                }
                case Token::Try:
                {
                    if (peek().type != Token::LeftBrace)
                    {
                        THROW(ParseException, "Expected '{'.", token.line, token.column);
                    }

                    ASTNode *tryBlock = getStatements(this);

                    if (peek().type != Token::Except)
                    {
                        THROW(ParseException, "Expected 'except'.", peek().line, peek().column);
                    }
                    get(); //Skip the 'except'

                    if (peek().type != Token::LeftBrace)
                    {
                        THROW(ParseException, "Expected '{'.", token.line, token.column);
                    }

                    ASTNode *exceptBlock = getStatements(this);

                    result = NEW(TryExceptNode, tryBlock, exceptBlock);
                    break;
                }
                case Token::While:
                {
                    ASTNode *cond = parse(getPrecedence(Token::LeftBrace, 0, 0));

                    if (peek().type != Token::LeftBrace)
                    {
                        THROW(ParseException, "Expected '{'.", token.line, token.column);
                    }

                    result = NEW(WhileNode, cond, getStatements(this));
                    break;
                }
                case Token::Class:
                {
                    if (peek().type != Token::LeftBrace)
                    {
                        THROW(ParseException, "Expected '{'.", token.line, token.column);
                    }

                    result = NEW(SingleOperandNode, ASTNode::Class, getStatements(this));
                    break;
                }
                case Token::Function:
                {
                    if (peek().type != Token::LeftParen)
                    {
                        THROW(ParseException, "Expected '('.", token.line, token.column);
                    }

                    ASTNode *args = nullptr;
                    get(); //Skip the '('
                    if (peek().type != Token::RightParen)
                    {
                        args = parse(getPrecedence(Token::RightParen, 0, 0));
                    }
                    get(); //Skip the ')'

                    if (peek().type != Token::LeftBrace)
                    {
                        THROW(ParseException, "Expected '{'.", token.line, token.column);
                    }

                    FunctionNode *func = NEW(FunctionNode, getStatements(this));

                    if (args == nullptr)
                    {
                    } else if (args->type == ASTNode::Comma)
                    {
                        getFuncArgs((LROpNode *)args, func);
                    } else if (args->type == ASTNode::Identifier)
                    {
                        func->args.append(((IdentifierNode *)args)->name);

                        DELETE(args);
                    } else
                    {
                        THROW(ParseException, "Invalid argument name.", 0, 0); //TODO: More info
                    }

                    result = func;
                    break;
                }
                case Token::If:
                {
                    ASTNode *ifCond = parse(getPrecedence(Token::LeftBrace, 0, 0));

                    if (peek().type != Token::LeftBrace)
                    {
                        THROW(ParseException, "Expected '{'.", token.line, token.column);
                    }

                    IfNode *ifNode = NEW(IfNode, ifCond, getStatements(this));

                    while (atEnd() ? false : peek().type == Token::Elif)
                    {
                        get(); //Skip the 'elif'

                        ASTNode *cond = parse(getPrecedence(Token::LeftBrace, 0, 0));

                        if (peek().type != Token::LeftBrace)
                        {
                            THROW(ParseException, "Expected '{'.", token.line, token.column);
                        }

                        ifNode->addElif(cond, getStatements(this));
                    }

                    if (atEnd() ? false : peek().type == Token::Else)
                    {
                        get(); //Skip the 'else'
                        ifNode->setElse(getStatements(this));
                    }

                    result = ifNode;
                    break;
                }
                default:
                {
                    THROW(ParseException,
                          "Unexpected token.",
                          token.line,
                          token.column);
                }
                }

                return result;
            }

            ASTNode *parseInfix(ASTNode *left, const Token& token)
            {
                int precedence = getPrecedence(token.type, token.line, token.column);

                switch (token.type)
                {
                case Token::Dot:
                {
                    return NEW(LROpNode, ASTNode::GetMember, left, parse(precedence));
                }
                case Token::Colon:
                {
                    return NEW(LROpNode, ASTNode::GetMethod, left, parse(precedence));
                }
                case Token::Assign:
                {
                    //TODO: Make this right associative
                    return NEW(LROpNode, ASTNode::Assign, left, parse(precedence));
                }
                case Token::Add:
                {
                    return NEW(LROpNode, ASTNode::Add, left, parse(precedence));
                }
                case Token::Subtract:
                {
                    return NEW(LROpNode, ASTNode::Subtract, left, parse(precedence));
                }
                case Token::Multiply:
                {
                    return NEW(LROpNode, ASTNode::Multiply, left, parse(precedence));
                }
                case Token::Divide:
                {
                    return NEW(LROpNode, ASTNode::Divide, left, parse(precedence));
                }
                case Token::Modulo:
                {
                    return NEW(LROpNode, ASTNode::Modulo, left, parse(precedence));
                }
                case Token::Less:
                {
                    return NEW(LROpNode, ASTNode::Less, left, parse(precedence));
                }
                case Token::Greater:
                {
                    return NEW(LROpNode, ASTNode::Greater, left, parse(precedence));
                }
                case Token::Equal:
                {
                    return NEW(LROpNode, ASTNode::Equal, left, parse(precedence));
                }
                case Token::NotEqual:
                {
                    return NEW(LROpNode, ASTNode::NotEqual, left, parse(precedence));
                }
                case Token::LessEqual:
                {
                    return NEW(LROpNode, ASTNode::LessEqual, left, parse(precedence));
                }
                case Token::GreaterEqual:
                {
                    return NEW(LROpNode, ASTNode::GreaterEqual, left, parse(precedence));
                }
                case Token::BoolAnd:
                {
                    return NEW(LROpNode, ASTNode::BoolAnd, left, parse(precedence));
                }
                case Token::BoolOr:
                {
                    return NEW(LROpNode, ASTNode::BoolOr, left, parse(precedence));
                }
                case Token::BitAnd:
                {
                    return NEW(LROpNode, ASTNode::BitAnd, left, parse(precedence));
                }
                case Token::BitOr:
                {
                    return NEW(LROpNode, ASTNode::BitOr, left, parse(precedence));
                }
                case Token::BitXOr:
                {
                    return NEW(LROpNode, ASTNode::BitXOr, left, parse(precedence));
                }
                case Token::LeftShift:
                {
                    return NEW(LROpNode, ASTNode::LeftShift, left, parse(precedence));
                }
                case Token::RightShift:
                {
                    return NEW(LROpNode, ASTNode::RightShift, left, parse(precedence));
                }
                case Token::Comma:
                {
                    return NEW(LROpNode, ASTNode::Comma, left, parse(precedence));
                }
                case Token::LeftParen:
                {
                    if (peek().type == Token::RightParen)
                    {
                        get();
                        return NEW(CallNode, left);
                    } else
                    {
                        ASTNode *args = parse(getPrecedence(Token::RightParen, 0, 0));
                        get(); //Skip the ')'

                        CallNode *call = NEW(CallNode, left);

                        if (args->type == ASTNode::Comma)
                        {
                            getArgs((LROpNode *)args, call);
                        } else
                        {
                            call->addArg(args);
                        }

                        return call;
                    }
                }
                case Token::LeftBracket:
                {
                    ASTNode *right = parse(getPrecedence(Token::RightBracket, 0, 0));
                    get(); //Skip the ']'

                    return NEW(LROpNode, ASTNode::GetMember, left, right);
                }
                case Token::EndStatement:
                {
                    if (atEnd())
                    {
                        return left;
                    } else if (peek().type == Token::RightBrace)
                    {
                        return left;
                    } else
                    {
                        return NEW(LROpNode, ASTNode::StatementSplit, left, parse(precedence));
                    }
                }
                default:
                {
                    THROW(ParseException, "Unexpected token.", token.line, token.column);
                }
                }
            }
    };

    ASTNode *parse(const List<Token>& tokens)
    {
        ASTNode *ast = Parser(tokens).parse();

        StatementsNode *statements = NEW(StatementsNode);

        if (ast->type == ASTNode::StatementSplit)
        {
            getStatements((LROpNode *)ast, statements);
        } else
        {
            statements->addStatement(ast);
        }

        return statements;
    }

    ASTNode *parse(const Str& source)
    {
        try
        {
            return parse(tokenize(source));
        } catch (TokenException& e)
        {
            THROW(ParseException, e.message, e.scriptLine, e.scriptColumn);
        }
    }

    static StatementsNode *getStatements(Parser *parser)
    {
        parser->get(); //Skip the '{'

        if (parser->peek().type == Token::RightBrace)
        {
            parser->get(); //Skip the '}'

            return NEW(StatementsNode);
        } else
        {
            ASTNode *node = parser->parse(getPrecedence(Token::RightBrace, 0, 0));
            parser->get(); //Skip the '}'

            StatementsNode *statements = NEW(StatementsNode);

            if (node->type == ASTNode::StatementSplit)
            {
                getStatements((LROpNode *)node, statements);
            } else
            {
                statements->addStatement(node);
            }

            return statements;
        }
    }
}
