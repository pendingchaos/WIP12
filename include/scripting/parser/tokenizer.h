#ifndef TOKENIZER_H
#define TOKENIZER_H

#include "containers/string.h"
#include "containers/list.h"
#include "error.h"

namespace scripting
{
class TokenException : public Exception
{
    public:
        TokenException(const char *file_,
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
            return "Failed to tokenize a script.";
        }

        const char *message;
        size_t scriptLine;
        size_t scriptColumn;
};

struct Token
{
    enum Type
    {
        LeftParen, //'('
        RightParen, //')'
        LeftBrace, //'{'
        RightBrace, //'}'
        LeftBracket, //'['
        RightBracket, //']'
        Ellipsis, //'...'
        Dot, //'.'
        Colon, //':'
        Comma, //','
        Assign, //'='
        Add, //'+'
        Subtract, //'-'
        Multiply, //'*'
        Divide, //'/'
        Modulo, //'%'
        Less, //'<'
        Greater, //'>'
        Equal, //'=='
        NotEqual, //'!='
        LessEqual, //'<='
        GreaterEqual, //'>='
        BoolAnd, //'and'
        BoolOr, //'or'
        BoolNot, //'not'
        BitAnd, //'&'
        BitOr, //'|'
        BitNot, //'~'
        BitXOr, //'^'
        LeftShift, //'<<'
        RightShift, //'>>'
        Function, //'function'
        Class, //'class'
        Throw, //'throw'
        Try, //'try'
        Except, //'except'
        If, //'if'
        Elif, //'elif'
        Else, //'else'
        While, //'while'
        Return, //'return'
        //Identifiers (variables, members, ...) can contain a-z, A-Z, '_' and 0-9 with the follow rules:
        //1. 0-9 must not be at the beginning.
        //2. It must not be a keyword.
        Identifier,
        //Integers can be prefixed with '0b', '0x'. If it is prefixed with '0b', it is binary, if '0x', it is hexadecimal.
        Integer,
        BinInteger,
        HexInteger,
        //Floats can be in the way sane people write them or like this: 3.1415e+5, 3.1415e5(the same as 3.1415e+5) or 3.1415e-5.
        //The 'e' can be uppercase.
        Float,
        ScientificFloat,
        //Starts with '"' and ends with '"'. Escapes:
        //\n, \t, \\, \", \x<some hexadecimal number with 2 digits>
        String,
        True, //'true'
        False, //'false'
        Nil, //'nil'
        EndStatement //';'
    };
    Type type;
    ::String str;
    size_t line;
    size_t column;
};

List<Token> tokenize(const String& input);
}

#endif // TOKENIZER_H
