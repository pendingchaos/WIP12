#ifndef PARSER_H
#define PARSER_H

#include "scripting/parser/ast.h"
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

ASTNode *parse(const String& source);
}

#endif // PARSER_H
