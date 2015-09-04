#ifndef PARSER_H
#define PARSER_H

#include "containers/string.h"

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
            Call,
            Identifier, //Can be "true", "false" or "nil"
            Integer,
            Float,
            String,
            Statements
        };

        ASTNode(Type type_) : type(type_) {}
        virtual ~ASTNode() {}

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
                DELETE(statements[i]);
            }
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
        CallNode(List<ASTNode *> nodes_) : ASTNode(ASTNode::Call),
                                           nodes(nodes_) {}

        virtual ~CallNode()
        {
            for (size_t i = 0; i < nodes.getCount(); ++i)
            {
                DELETE(nodes[i]);
            }
        }

        List<ASTNode *> nodes;
};

ASTNode *parse(const String& source);
}

#endif // PARSER_H
