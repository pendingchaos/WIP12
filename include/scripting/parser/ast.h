#ifndef AST_H
#define AST_H

#include "memory.h"
#include "containers/string.h"

namespace scripting
{
    class ASTNode
    {
        public:
            enum Type
            {
                Call,
                Identifier, //Can be "true", "false" or "nil"
                Integer,
                Float,
                String,
                Statements
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

    class IdentifierNode : public ASTNode
    {
        public:
            IdentifierNode(const List<::String>& names_) : ASTNode(ASTNode::Identifier), names(names_) {}

            const List<::String> names; //["obj", "member"] for obj.member
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
