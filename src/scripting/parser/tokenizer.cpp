#include "scripting/parser/tokenizer.h"

#define TOKEN(str_, type_) else if (input.startsWith(str_, offset))\
{\
offset += (sizeof str_) - 1;\
Token tok;\
tok.type = type_;\
tok.str = str_;\
tokens.append(tok);\
}

#define TOKEN_KW(str_, type_) else if (input.startsWith(str_, offset))\
{\
offset += (sizeof str_) - 1;\
if (offset < input.getLength())\
{\
    char c = input[offset+1];\
    \
    if (c >= 'a' and c <= 'z')\
    {\
        int TODO_Error;\
    } else if (c >= 'A' and c <= 'Z')\
    {\
    } else if (c == '_')\
    {\
    } else\
    {\
        int TODO_Error;\
    }\
}\
Token tok;\
tok.type = type_;\
tok.str = str_;\
tokens.append(tok);\
}

#define COLUMN (offset - lastLineOffset)

namespace scripting
{
List<Token> tokenize(const String& input)
{
    List<Token> tokens;
    size_t offset = 0;

    size_t line = 1;
    size_t lastLineOffset = 0;

    while (offset < input.getLength())
    {
        if (input[offset] == '\n')
        {
            ++line;
            lastLineOffset = offset;
        }

        if (input[offset] == ' ')
        {
            ++offset;
        } else if (input[offset] == '\t')
        {
            ++offset;
        }
        TOKEN("(", Token::LeftParen)
        TOKEN(")", Token::RightParen)
        TOKEN("{", Token::LeftBrace)
        TOKEN("}", Token::RightBrace)
        TOKEN("[", Token::LeftBracket)
        TOKEN("]", Token::RightBracket)
        TOKEN("...", Token::Ellipsis)
        TOKEN(".", Token::Dot)
        TOKEN(",", Token::Comma)
        TOKEN("==", Token::Equal) //It is important that this is before Assign. (same with a few others)
        TOKEN("=", Token::Assign)
        TOKEN(":=", Token::RefAssign)
        TOKEN("+", Token::Add)
        TOKEN("->", Token::WithAs)
        TOKEN("-", Token::Subtract)
        TOKEN("*", Token::Multiply)
        TOKEN("/", Token::Divide)
        TOKEN("%", Token::Modulo)
        TOKEN("<=", Token::LessEqual)
        TOKEN("<", Token::Less)
        TOKEN("<<", Token::LeftShift)
        TOKEN(">=", Token::GreaterEqual)
        TOKEN(">>", Token::RightShift)
        TOKEN(">", Token::Greater)
        TOKEN("!=", Token::NotEqual)
        TOKEN_KW("and", Token::BoolAnd)
        TOKEN_KW("or", Token::BoolOr)
        TOKEN_KW("not", Token::BoolNot)
        TOKEN("&", Token::BitAnd)
        TOKEN("|", Token::BitOr)
        TOKEN("~", Token::BitNot)
        TOKEN("^", Token::BitXOr)
        TOKEN_KW("function", Token::Function)
        TOKEN_KW("class", Token::Class)
        TOKEN_KW("with", Token::With)
        TOKEN_KW("throw", Token::Throw)
        TOKEN_KW("try", Token::Try)
        TOKEN_KW("except", Token::Except)
        TOKEN_KW("if", Token::If)
        TOKEN_KW("elif", Token::Elif)
        TOKEN_KW("else", Token::Else)
        TOKEN_KW("delvar", Token::DeleteVar)
        TOKEN_KW("scope", Token::Scope)
        TOKEN_KW("return", Token::Return)
        TOKEN_KW("true", Token::True)
        TOKEN_KW("false", Token::False)
        TOKEN_KW("nil", Token::Nil)
        TOKEN("\n", Token::NewLine)
        TOKEN(";", Token::EndStatement)
        else if (input.startsWith("0x", offset))
        {
            String str = "0x";

            offset += 2;

            for (; offset < input.getLength(); ++offset)
            {
                char c = input[offset];

                if (c >= '0' and c <= '9')
                {
                } else if (c >= 'a' and c <= 'f')
                {
                } else if (c >= 'A' and c <= 'F')
                {
                } else if (c == ' ' or c == '\n' or c == '\t')
                {
                    break;
                } else
                {
                    THROW(TokenException, "Invalid character in hexadecimal literal.", line, COLUMN);
                }

                str.append(c);
            }

            Token tok;
            tok.type = Token::HexInteger;
            tok.str = str;

            tokens.append(tok);
        } else if (input.startsWith("0b", offset))
        {
            offset += 2;

            String str = "0b";

            for (; offset < input.getLength(); ++offset)
            {
                char c = input[offset];

                if (c == '0' or c == '1')
                {
                    str.append(c);
                } else if (c == ' ' or c == '\n' or c == '\t')
                {
                    break;
                } else
                {
                    THROW(TokenException, "Invalid character in binary literal.", line, COLUMN);
                }
            }

            Token tok;
            tok.type = Token::BinInteger;
            tok.str = str;

            tokens.append(tok);
        } else if (input[offset] >= '0' and input[offset] <= '9')
        {
            String str = input[offset++];

            bool hasFractional = false;
            bool scientific = false;
            bool addMinus = false;

            for (; offset < input.getLength(); ++offset)
            {
                char c = input[offset];

                if (c == '.')
                {
                    if (hasFractional)
                    {
                        THROW(TokenException, "A float literal can not contain two '.'s.", line, COLUMN);
                    } else
                    {
                        hasFractional = true;
                    }
                } else if (c == 'e')
                {
                    if (scientific)
                    {
                        THROW(TokenException, "A scientific float literal can not contain two 'e's.", line, COLUMN);
                    } else
                    {
                        scientific = true;
                    }
                } else if (c == '+' or c == '-')
                {
                    if (scientific)
                    {
                        if (addMinus)
                        {
                            THROW(TokenException, "A scientific float literal can not contain two '+'s or '-'s.", line, COLUMN);
                        } else
                        {
                            addMinus = true;
                        }
                    } else
                    {
                        break;
                    }
                } else if (c >= '0' and c <= '9')
                {
                } else if (c >= 'a' and c <= 'z')
                {
                        THROW(TokenException, "A number literal can not contain letters like that.", line, COLUMN);
                } else if (c >= 'A' and c <= 'Z')
                {
                        THROW(TokenException, "A number literal can not contain letters like that.", line, COLUMN);
                } else if (c == '_')
                {
                        THROW(TokenException, "A number literal can not contain underscores.", line, COLUMN);
                } else
                {
                    break;
                }

                str.append(input[offset]);
            }

            Token tok;
            tok.type = scientific ? Token::ScientificFloat : (hasFractional ? Token::Float : Token::Integer);
            tok.str = str;

            tokens.append(tok);
        } else if (input[offset] == '"')
        {
            ++offset;

            String str = '"';

            bool success = false;

            for (; offset < input.getLength(); ++offset)
            {
                char c = input[offset];

                if (c == '\\')
                {
                    ++offset;

                    if (offset <= input.getLength())
                    {
                        THROW(TokenException, "Expected character after '\\'.", line, COLUMN);
                    }

                    str.append('\\');

                    char ec = input[offset];

                    if (ec == 'n' or ec == 't' or ec == '\\' or ec == 'x')
                    {
                        str.append(ec);
                    } else
                    {
                        THROW(TokenException, "Invalid escape code.", line, COLUMN);
                    }
                } else if (c == '"')
                {
                    ++offset;
                    str.append(c);
                    success = true;
                    break;
                } else
                {
                    str.append(c);
                }
            }

            if (not success)
            {
                THROW(TokenException, "Unexpected end of characters in string literal.", line, COLUMN);
            }

            Token tok;

            tok.type = Token::String;
            tok.str = str;

            tokens.append(tok);
        } else if (input[offset] == '#')
        {
            for (; offset < input.getLength(); ++offset)
            {
                if (input[offset] == '\n')
                {
                    break;
                }
            }
        } else
        {
            char cc = input[offset];

            if (cc >= 'a' and cc <= 'z')
            {
            } else if (cc >= 'A' and cc <= 'Z')
            {
            } else if (cc == '_')
            {
            } else
            {
                THROW(TokenException, "Invalid token.", line, COLUMN);
            }

            String str;

            for (; offset < input.getLength(); ++offset)
            {
                char c = input[offset];

                if (c >= 'a' and c <= 'z')
                {
                } else if (c >= 'A' and c <= 'Z')
                {
                } else if (c == '_')
                {
                } else if (c >= '0' and c <= '9')
                {
                } else
                {
                    break;
                }

                str.append(c);
            }

            Token tok;
            tok.type = Token::Identifier;
            tok.str = str;

            tokens.append(tok);
        }
    }

    return tokens;
}
}
