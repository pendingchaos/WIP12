#ifndef BYTECODEGEN_H
#define BYTECODEGEN_H

#include "scripting/parser.h"
#include "containers/resizabledata.h"

namespace scripting
{
class ByteCodeGenException : public Exception
{
    public:
        ByteCodeGenException(const char *file_,
                             size_t line_,
                             const char *function_,
                             const char *message) : Exception(file_, line_, function_),
                                                    message(message) {}

        virtual const char *getString() const
        {
            return "Failed to generate bytecode from an AST.";
        }

        const char *message;

        //TODO
        //size_t scriptLine;
        //size_t scriptColumn;
};

ResizableData generateBytecode(ASTNode *ast);
};

#endif // BYTECODEGEN_H
