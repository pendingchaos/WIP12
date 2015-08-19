#include "scripting/parser/ast.h"

#include "scripting/parser/tokenizer.h"
#include <cassert>

#include <iostream> //TODO: Get rid of this.

namespace scripting
{
    Token getToken(const List<Token>& tokens, size_t offset)
    {
        if (offset >= tokens.getCount())
        {
            //TODO: Error
        }

        return tokens[offset];
    }

    int getPrecedence(Token tok)
    {
        switch (tok.type)
        {
        case Token::With:
        {
            return 0;
        }
        case Token::Dot:
        {
            return 1;
        }
        case Token::BoolNot:
        case Token::BitNot:
        case Token::Multiply:
        case Token::Divide:
        case Token::Modulo:
        {
            return 3;
        }
        case Token::Add:
        case Token::Subtract:
        {
            return 4;
        }
        case Token::LeftShift:
        case Token::RightShift:
        {
            return 5;
        }
        case Token::Less:
        case Token::LessEqual:
        case Token::Greater:
        case Token::GreaterEqual:
        {
            return 6;
        }
        case Token::Equal:
        case Token::NotEqual:
        {
            return 7;
        }
        case Token::BitAnd:
        case Token::BitXOr:
        case Token::BitOr:
        case Token::BoolAnd:
        case Token::BoolOr:
        {
            return 8;
        }
        case Token::Assign:
        case Token::RefAssign:
        {
            return 9;
        }
        default:
        {
            return -1;
        }
        }
    }

    bool isRightAssociative(Token tok)
    {
        switch (tok.type)
        {
        case Token::BoolNot:
        case Token::BitNot:
        case Token::Assign:
        case Token::RefAssign:
        {
            return true;
        }
        default:
        {
            return false;
        }
        }
    }

    ASTNode *parsePrimary(const List<Token>& tokens, size_t *offset)
    {
        switch (tokens[*offset].type)
        {
        case Token::LeftParen:
        {
            //TODO
        }
        case Token::LeftBrace:
        {
            //TODO
        }
        case Token::Function:
        {
            //TODO
        }
        case Token::Class:
        {
            //TODO
        }
        case Token::Identifier:
        {
            return (ASTNode *)NEW(IdentifierNode, tokens[*offset].str);
        }
        case Token::Integer:
        {
            int64_t v = strtoll(tokens[*offset].str.getData(), nullptr, 10);

            return (ASTNode *)NEW(IntegerNode, v);
        }
        case Token::BinInteger:
        {
            int64_t v = strtoll(tokens[*offset].str.getData()+2, nullptr, 2);

            return (ASTNode *)NEW(IntegerNode, v);
        }
        case Token::HexInteger:
        {
            int64_t v = strtoll(tokens[*offset].str.getData()+2, nullptr, 16);

            return (ASTNode *)NEW(IntegerNode, v);
        }
        case Token::String:
        {
            //TODO
        }
        case Token::True:
        {
            return NEW(ASTNode, ASTNode::True);
        }
        case Token::False:
        {
            return NEW(ASTNode, ASTNode::False);
        }
        case Token::Nil:
        {
            return NEW(ASTNode, ASTNode::Nil);
        }
        default:
        {
            //TODO: Error
        }
        }

        assert(false);

        return nullptr;
    }

    ASTNode *createOp(Token op, ASTNode *lhs, ASTNode *rhs)
    {
        switch (op.type)
        {
        case Token::With:
        {
            //TODO
        }
        case Token::Dot:
        {
            return (ASTNode *)NEW(LROpNode, ASTNode::GetMember, lhs, rhs);
        }
        case Token::Multiply:
        {
            return (ASTNode *)NEW(LROpNode, ASTNode::Multiply, lhs, rhs);
        }
        case Token::Divide:
        {
            return (ASTNode *)NEW(LROpNode, ASTNode::Divide, lhs, rhs);
        }
        case Token::Modulo:
        {
            return (ASTNode *)NEW(LROpNode, ASTNode::Modulo, lhs, rhs);
        }
        case Token::Add:
        {
            return (ASTNode *)NEW(LROpNode, ASTNode::Add, lhs, rhs);
        }
        case Token::Subtract:
        {
            return (ASTNode *)NEW(LROpNode, ASTNode::Subtract, lhs, rhs);
        }
        case Token::LeftShift:
        {
            return (ASTNode *)NEW(LROpNode, ASTNode::LeftShift, lhs, rhs);
        }
        case Token::RightShift:
        {
            return (ASTNode *)NEW(LROpNode, ASTNode::RightShift, lhs, rhs);
        }
        case Token::Less:
        {
            return (ASTNode *)NEW(LROpNode, ASTNode::Less, lhs, rhs);
        }
        case Token::LessEqual:
        {
            return (ASTNode *)NEW(LROpNode, ASTNode::LessEqual, lhs, rhs);
        }
        case Token::Greater:
        {
            return (ASTNode *)NEW(LROpNode, ASTNode::Greater, lhs, rhs);
        }
        case Token::GreaterEqual:
        {
            return (ASTNode *)NEW(LROpNode, ASTNode::GreaterEqual, lhs, rhs);
        }
        case Token::Equal:
        {
            return (ASTNode *)NEW(LROpNode, ASTNode::Equal, lhs, rhs);
        }
        case Token::NotEqual:
        {
            return (ASTNode *)NEW(LROpNode, ASTNode::NotEqual, lhs, rhs);
        }
        case Token::BitAnd:
        {
            return (ASTNode *)NEW(LROpNode, ASTNode::BitAnd, lhs, rhs);
        }
        case Token::BitXOr:
        {
            return (ASTNode *)NEW(LROpNode, ASTNode::BitXOr, lhs, rhs);
        }
        case Token::BitOr:
        {
            return (ASTNode *)NEW(LROpNode, ASTNode::BitOr, lhs, rhs);
        }
        case Token::BoolAnd:
        {
            return (ASTNode *)NEW(LROpNode, ASTNode::BoolAnd, lhs, rhs);
        }
        case Token::BoolOr:
        {
            return (ASTNode *)NEW(LROpNode, ASTNode::BoolOr, lhs, rhs);
        }
        case Token::Assign:
        {
            return (ASTNode *)NEW(LROpNode, ASTNode::Assign, lhs, rhs);
        }
        case Token::RefAssign:
        {
            return (ASTNode *)NEW(LROpNode, ASTNode::RefAssign, lhs, rhs);
        }
        default:
        {
            assert(false);
        }
        }

        assert(false);

        return nullptr;
    }

    //TODO: ( and )
    //TODO: Unary operators?
    ASTNode *_createAST(const List<Token>& tokens, ASTNode *lhs, size_t *offset, int minPrecedence)
    {
        Token lookAhead = getToken(tokens, *offset);

        while (getPrecedence(lookAhead) >= minPrecedence)
        {
            Token op = lookAhead;
            ++*offset;
            ASTNode *rhs;

            if (op.type == Token::With)
            {
                //TODO
            } else
            {
                rhs = parsePrimary(tokens, offset);
                ++*offset;
            }

            if (*offset >= tokens.getCount())
            {
                return createOp(op, lhs, rhs);
            }

            lookAhead = getToken(tokens, *offset);

            int laPrec = getPrecedence(lookAhead);
            int opPrec = getPrecedence(op);

            while ((laPrec > opPrec) or
                   (isRightAssociative(lookAhead) and laPrec == opPrec))
            {
                rhs = _createAST(tokens, rhs, offset, laPrec);

                lookAhead = getToken(tokens, *offset);
                laPrec = getPrecedence(lookAhead);
            }

            lhs = createOp(op, lhs, rhs);
        }

        return lhs;
    }

    //TODO: Make this word with something other than a expression.
    ASTNode *createAST(const List<Token>& tokens)
    {
        size_t offset = 0;

        ASTNode *primary = parsePrimary(tokens, &offset);

        ++offset;

        return _createAST(tokens, primary, &offset, 0);
    }
};
