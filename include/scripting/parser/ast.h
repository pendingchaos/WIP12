#ifndef AST_H
#define AST_H

#include "memory.h"
#include "containers/string.h"

namespace scripting
{
    class ASTNode
    {
        public:
            //TODO: 40 * 2 - 1 does not work
            //TODO: 5 does not work
            enum Type
            {
                Call, //CallNode //Unimplemented
                GetMember, //LROpNode
                Assign, //LROpNode
                RefAssign, //LROpNode
                Add, //LROpNode //Works
                Subtract, //LROpNode //Works
                Multiply, //LROpNode //Works
                Divide, //LROpNode //Works
                Modulo, //LROpNode //Works
                Less, //LROpNode //Works
                Greater, //LROpNode //Works
                Equal, //LROpNode //Works
                NotEqual, //LROpNode //Works
                LessEqual, //LROpNode //Works
                GreaterEqual, //LROpNode //Works
                BoolAnd, //LROpNode //Works
                BoolOr, //LROpNode //Works
                BoolNot, //SingleOperandNode //Does not work
                BitAnd, //LROpNode //Works
                BitOr, //LROpNode //Works
                BitNot, //SingleOperandNode //Does not work
                BitXOr, //LROpNode //Works
                LeftShift, //LROpNode //Does not works
                RightShift, //LROpNode //Works
                Function, //FunctionNode //Unimplemented
                Class, //SingleOperandNode //Unimplemented
                FuncWith, //FuncWithNode //Unimplemented
                Throw, //SingleOperandNode //Unimplemented
                TryExcept, //TryExceptNode //Unimplemented
                If, //IfNode //Unimplemented
                DeleteVar, //SingleOperandNode //Unimplemented
                Scope, //SingleOperandNode //Unimplemented
                Return, //SingleOperandNode //Unimplemented
                Identifier, //IdentifierNode //Does not work
                Integer, //IntegerNode //Works
                Float, //FloatNode //Unimplemented
                String, //StringNode //Unimplemented
                True, //ASTNode //Works
                False, //ASTNode //Works
                Nil, //ASTNode //Works
                Object, //StatementsNode //Unimplemented
                Statements //StatementsNode //Unimplemented
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
                DELETE(ASTNode, left);
                DELETE(ASTNode, right);
            }

            ASTNode *left;
            ASTNode *right;
    };

    class IdentifierNode : public ASTNode
    {
        public:
            IdentifierNode(const ::String& name_) : ASTNode(ASTNode::Identifier), name(name_) {}

            const ::String name;
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
                DELETE(ASTNode, operand);
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
                    DELETE(ASTNode, statements[i]);
                }
            }

            inline void addStatement(ASTNode *node)
            {
                node->parent = this;

                statements.append(node);
            }

            List<ASTNode *> statements;
    };

    class StringNode : public ASTNode
    {
        public:
            StringNode(const ::String& content_) : ASTNode(ASTNode::String), content(content_) {}

            const ::String content;
    };

    class IfNode : public ASTNode
    {
        public:
            IfNode(ASTNode *if__, ASTNode *else__) : ASTNode(ASTNode::If), if_(if__), else_(else__)
            {
                if_->parent = this;
                if (else_ != nullptr) {else_->parent = this;}
            }

            virtual ~IfNode()
            {
                DELETE(ASTNode, if_);
                DELETE(ASTNode, else_);

                for (size_t i = 0; i < elifs.getCount(); ++i)
                {
                    DELETE(ASTNode, elifs[i]);
                }
            }

            inline void setElse(ASTNode *newElse)
            {
                if (else_ != nullptr) {DELETE(ASTNode, else_);}
                else_ = newElse;
                if (else_ != nullptr) {else_->parent = this;}
            }

            inline void addElif(ASTNode *node)
            {
                node->parent = this;

                elifs.append(node);
            }

            ASTNode *if_;
            ASTNode *else_;
            List<ASTNode *> elifs;
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
                DELETE(ASTNode, try_);
                DELETE(ASTNode, except);
            }

            inline void setExcept(ASTNode *node)
            {
                if (except != nullptr) {DELETE(ASTNode, except);}
                except = node;
                if (except != nullptr) {except->parent = this;}
            }

            ASTNode *try_;
            ASTNode *except;
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
                DELETE(ASTNode, body);
            }

            ASTNode *body;
            ::List<::String> args;
    };

    class FuncWithNode : public ASTNode
    {
        public:
            FuncWithNode(ASTNode *func_,
                         const ::String& var_,
                         const ::String& as_) : ASTNode(ASTNode::FuncWith),
                                                func(func_),
                                                var(var_),
                                                as(as_)
            {
                func->parent = this;
            }

            virtual ~FuncWithNode()
            {
                DELETE(ASTNode, func);
            }

            ASTNode *func;
            ::String var;
            ::String as;
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
                DELETE(ASTNode, callable);

                for (size_t i = 0; i < args.getCount(); ++i)
                {
                    DELETE(ASTNode, args[i]);
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
};

#endif // AST_H
