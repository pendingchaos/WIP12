#ifndef AST_H
#define AST_H

#include "memory.h"
#include "error.h"
#include "containers/string.h"
#include "scripting/parser/tokenizer.h"

namespace scripting
{
    class ParseException : public Exception
    {
        public:
            ParseException(const char *file_,
                           size_t line_,
                           const char *function_,
                           const char *message,
                           size_t scriptLine_,
                           size_t scriptColumn) : Exception(file_, line_, function_),
                                                  message(message),
                                                  scriptLine(scriptLine_),
                                                  scriptColumn(scriptColumn) {}

            virtual const char *getString() const
            {
                return "Failed to parse a script.";
            }

            const char *message;
            size_t scriptLine;
            size_t scriptColumn;
    };

    class ASTNode
    {
        public:
            enum Type
            {
                Call, //CallNode
                GetMember, //LROpNode
                GetMethod, //LROpNode
                Assign, //LROpNode
                Comma, //LROpNode
                Add, //LROpNode
                Subtract, //LROpNode
                Multiply, //LROpNode
                Divide, //LROpNode
                Modulo, //LROpNode
                Negate, //SingleOperandNode
                Less, //LROpNode
                Greater, //LROpNode
                Equal, //LROpNode
                NotEqual, //LROpNode
                LessEqual, //LROpNode
                GreaterEqual, //LROpNode
                BoolAnd, //LROpNode
                BoolOr, //LROpNode
                BoolNot, //SingleOperandNode
                BitAnd, //LROpNode
                BitOr, //LROpNode
                BitNot, //SingleOperandNode
                BitXOr, //LROpNode
                LeftShift, //LROpNode
                RightShift, //LROpNode
                Function, //FunctionNode
                Class, //SingleOperandNode
                Throw, //SingleOperandNode
                TryExcept, //TryExceptNode
                If, //IfNode
                While, //WhileNode
                Return, //SingleOperandNode
                Identifier, //IdentifierNode
                Integer, //IntegerNode
                Float, //FloatNode
                String, //StringNode
                True, //ASTNode
                False, //ASTNode
                Nil, //ASTNode
                Statements, //StatementsNode
                StatementSplit //LROpNode
            };

            ASTNode(Type type_) : parent(nullptr), type(type_) {}
            virtual ~ASTNode() {}

            ASTNode *parent;
            const Type type;
    };

    class FloatNode : public ASTNode
    {
        public:
            FloatNode(double value_) : ASTNode(ASTNode::Float), value(value_) {}

            double value;
    };

    class IntegerNode : public ASTNode
    {
        public:
            IntegerNode(int64_t value_) : ASTNode(ASTNode::Integer), value(value_) {}

            int64_t value;
    };

    class LROpNode : public ASTNode
    {
        public:
            LROpNode(Type type_,
                     ASTNode *left_,
                     ASTNode *right_) : ASTNode(type_),
                                        left(left_),
                                        right(right_)
            {
                left->parent = this;
                right->parent = this;
            }

            virtual ~LROpNode()
            {
                DELETE(left);
                DELETE(right);
            }

            ASTNode *left;
            ASTNode *right;
    };

    class IdentifierNode : public ASTNode
    {
        public:
            IdentifierNode(::Str name_) : ASTNode(ASTNode::Identifier), name(name_) {}

            const ::Str name;
    };

    class SingleOperandNode : public ASTNode
    {
        public:
            SingleOperandNode(Type type_,
                              ASTNode *operand_) : ASTNode(type_),
                                                   operand(operand_)
            {
                operand->parent = this;
            }

            virtual ~SingleOperandNode()
            {
                DELETE(operand);
            }

            ASTNode *operand;
    };

    class StatementsNode : public ASTNode
    {
        public:
            StatementsNode() : ASTNode(ASTNode::Statements) {}

            virtual ~StatementsNode()
            {
                for (size_t i = 0; i < statements.getCount(); ++i)
                {
                    DELETE(statements[i]);
                }
            }

            inline void addStatement(ASTNode *node)
            {
                node->parent = this;

                statements.append(node);
            }

            List<ASTNode *> statements;
    };

    class ObjectNode : public ASTNode
    {
        public:
            ObjectNode() : ASTNode(ASTNode::Statements) {}

            virtual ~ObjectNode()
            {
                for (size_t i = 0; i < members.getCount(); ++i)
                {
                    DELETE(members[i]);
                }
            }

            inline void addMember(ASTNode *node)
            {
                node->parent = this;

                members.append(node);
            }

            List<ASTNode *> members;
    };

    class StringNode : public ASTNode
    {
        public:
            StringNode(const ::Str& content_) : ASTNode(ASTNode::String), content(content_) {}

            const ::Str content;
    };

    class IfNode : public ASTNode
    {
        public:
            IfNode(ASTNode *ifCond_, ASTNode *if__) : ASTNode(ASTNode::If), ifCond(ifCond_), if_(if__), else_(nullptr)
            {
                ifCond->parent = this;
                if_->parent = this;
            }

            virtual ~IfNode()
            {
                DELETE(ifCond);
                DELETE(if_);
                DELETE(else_);

                for (size_t i = 0; i < elifs.getCount(); ++i)
                {
                    DELETE(elifs[i]);
                    DELETE(elifConds[i]);
                }
            }

            inline void setElse(ASTNode *newElse)
            {
                if (else_ != nullptr) {DELETE(else_);}
                else_ = newElse;
                if (else_ != nullptr) {else_->parent = this;}
            }

            inline void addElif(ASTNode *cond, ASTNode *node)
            {
                cond->parent = this;
                node->parent = this;

                elifs.append(node);
                elifConds.append(cond);
            }

            ASTNode *ifCond;
            ASTNode *if_;
            ASTNode *else_;
            List<ASTNode *> elifs;
            List<ASTNode *> elifConds;
    };

    class TryExceptNode : public ASTNode
    {
        public:
            TryExceptNode(ASTNode *try__, ASTNode *except_) : ASTNode(ASTNode::TryExcept), try_(try__), except(except_)
            {
                try_->parent = this;
                if (except != nullptr) {except->parent = this;}
            }

            virtual ~TryExceptNode()
            {
                DELETE(try_);
                DELETE(except);
            }

            inline void setExcept(ASTNode *node)
            {
                if (except != nullptr) {DELETE(except);}
                except = node;
                if (except != nullptr) {except->parent = this;}
            }

            ASTNode *try_;
            ASTNode *except;
    };

    class WhileNode : public ASTNode
    {
        public:
            WhileNode(ASTNode *cond_, ASTNode *block_) : ASTNode(ASTNode::While), cond(cond_), block(block_)
            {
                cond->parent = this;
                block->parent = this;
            }

            virtual ~WhileNode()
            {
                DELETE(cond);
                DELETE(block);
            }

            ASTNode *cond;
            ASTNode *block;
    };

    class FunctionNode : public ASTNode
    {
        public:
            FunctionNode(ASTNode *body_) : ASTNode(ASTNode::Function), body(body_)
            {
                body->parent = this;
            }

            virtual ~FunctionNode()
            {
                DELETE(body);
            }

            ASTNode *body;
            ::List<::Str> args;
    };

    class CallNode : public ASTNode
    {
        public:
            CallNode(ASTNode *callable_) : ASTNode(ASTNode::Call),
                                           callable(callable_)
            {
                callable->parent = this;
            }

            virtual ~CallNode()
            {
                DELETE(callable);

                for (size_t i = 0; i < args.getCount(); ++i)
                {
                    DELETE(args[i]);
                }
            }

            inline void addArg(ASTNode *node)
            {
                node->parent = this;

                args.append(node);
            }

            ASTNode *callable;
            List<ASTNode *> args;
    };

    ASTNode *parse(const List<Token>& tokens);
    ASTNode *parse(const Str& source);
};

#endif // AST_H
