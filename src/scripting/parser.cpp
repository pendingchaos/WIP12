#include "scripting/parser.h"

#define ADVANCE_LINE do\
{\
    lastLineOffset = offset;\
    ++line;\
} while (0)

#define COLUMN (offset - lastLineOffset)

namespace scripting
{
ASTNode *parseNumber(const String& source, size_t& offset, size_t& lastLineOffset, size_t& line)
{
    String str;

    bool fractional = false;
    bool scientific = false;
    bool plusMinus = false;

    size_t originalOffset = offset;

    while (true)
    {
        if (offset == source.getLength())
        {
            THROW(ParseException, "Unexpected end of source code.", line, COLUMN);
        }

        char c = source[offset++];

        if (c == '-' or c == '+')
        {
            if (scientific)
            {
                if (plusMinus)
                {
                    THROW(ParseException, "A scientific float literal can not contain two '+'s or '-'s.", line, COLUMN);
                } else
                {
                    plusMinus = true;
                }
            } else
            {
                if (offset != originalOffset+1)
                {
                    THROW(ParseException, "Unexpected sign in float literal.", line, COLUMN);
                }
            }
        } else if (c == '.')
        {
            if (fractional)
            {
                THROW(ParseException, "A float literal can not contain two '.'s.", line, COLUMN);
            } else
            {
                fractional = true;
            }
        } else if (c == 'e')
        {
            if (scientific)
            {
                THROW(ParseException, "A scientific float literal can not contain two 'e's.", line, COLUMN);
            } else
            {
                scientific = true;
            }
        } else if (c == '+' or c == '-')
        {
        } else if (c >= '0' and c <= '9')
        {
        } else if (c == ')' or c == '(')
        {
            --offset;
            break;
        } else if (c == ' ' or c == '\t')
        {
            break;
        } else if (c == '\n')
        {
            ADVANCE_LINE;
            break;
        } else if (c == '#')
        {
            while (true)
            {
                if (offset == source.getLength())
                {
                    THROW(ParseException, "Unexpected end of source code.", line, COLUMN);
                }

                if (source[offset] == '\n')
                {
                    ADVANCE_LINE;
                    break;
                }

                ++offset;
            }

            goto end;
        } else
        {
            THROW(ParseException, "Unexpected character in number literal.", line, COLUMN);
        }

        str.append(c);
    }

    end:
    if (scientific)
    {
        double v = strtod(str.getData(), nullptr);

        return (ASTNode *)NEW(FloatNode, v);
    } else
    {
        if (fractional)
        {
            double v = strtod(str.getData(), nullptr);

            return (ASTNode *)NEW(FloatNode, v);
        } else
        {
            int64_t v = strtoll(str.getData(), nullptr, 10);

            return (ASTNode *)NEW(IntegerNode, v);
        }
    }
}

ASTNode *parseBase16(const String& source, size_t& offset, size_t& lastLineOffset, size_t& line)
{
    String str;

    while (true)
    {
        if (offset == source.getLength())
        {
            THROW(ParseException, "Unexpected end of source code.", line, COLUMN);
        }

        char c = source[offset++];

        if (c >= '0' and c <= '9')
        {
        } else if (c >= 'a' and c <= 'z')
        {
        } else if (c >= 'A' and c <= 'Z')
        {
        } else if (c == ')' or c == '(')
        {
            --offset;
            break;
        } else if (c == ' ' or c == '\t')
        {
            break;
        } else if (c == '\n')
        {
            ADVANCE_LINE;
            break;
        } else if (c == '#')
        {
            while (true)
            {
                if (offset == source.getLength())
                {
                    THROW(ParseException, "Unexpected end of source code.", line, COLUMN);
                }

                if (source[offset] == '\n')
                {
                    ADVANCE_LINE;
                    break;
                }

                ++offset;
            }

            goto end;
        } else
        {
            THROW(ParseException, "Unexpected character in hexadecimal literal.", line, COLUMN);
        }

        str.append(c);
    }

    end:
    int64_t v = strtoll(str.getData(), nullptr, 16);

    return (ASTNode *)NEW(IntegerNode, v);
}

ASTNode *parseBase2(const String& source, size_t& offset, size_t& lastLineOffset, size_t& line)
{
    String str;

    while (true)
    {
        if (offset == source.getLength())
        {
            THROW(ParseException, "Unexpected end of source code.", line, COLUMN);
        }

        char c = source[offset++];

        if (c == '0' or c == '1')
        {
        } else if (c == ')' or c == '(')
        {
            --offset;
            break;
        } else if (c == ' ' or c == '\t')
        {
            break;
        } else if (c == '\n')
        {
            ADVANCE_LINE;
            break;
        } else if (c == '#')
        {
            while (true)
            {
                if (offset == source.getLength())
                {
                    THROW(ParseException, "Unexpected end of source code.", line, COLUMN);
                }

                if (source[offset] == '\n')
                {
                    ADVANCE_LINE;
                    break;
                }

                ++offset;
            }

            goto end;
        } else
        {
            THROW(ParseException, "Unexpected character in binary literal.", line, COLUMN);
        }

        str.append(c);
    }

    end:
    int64_t v = strtoll(str.getData(), nullptr, 2);

    return (ASTNode *)NEW(IntegerNode, v);
}

ASTNode *parseString(const String& source, size_t& offset, size_t& lastLineOffset, size_t& line)
{
    String str;

    while (true)
    {
        if (offset == source.getLength())
        {
            THROW(ParseException, "Unexpected end of characters in string literal.", line, COLUMN);
        }

        char c = source[offset++];

        if (c == '\\')
        {
            ++offset;

            if (offset == source.getLength())
            {
                THROW(ParseException, "Expected character after '\\'.", line, COLUMN);
            }

            char ec = source[offset];

            if (ec == 'n')
            {
                str.append('\n');
            } else if (ec == 't')
            {
                str.append('\n');
            } else if (ec == '\\')
            {
                str.append('\\');
            } else if (ec == '"')
            {
                str.append('"');
            } else if (ec == '#')
            {
                str.append('#');
            } else if (ec == 'x')
            {
                offset += 2;

                if (offset >= source.getLength())
                {
                    THROW(ParseException, "Unexpected end of source code.", line, COLUMN);
                }

                char hex[3] = {source[offset-1], source[offset], 0};

                if (hex[0] >= '0' and hex[0] <= '9')
                {
                } else if (hex[0] >= 'a' and hex[0] <= 'z')
                {
                } else if (hex[0] >= 'A' and hex[0] <= 'Z')
                {
                    THROW(ParseException, "Unexpected character in hexadecimal literal.", line, COLUMN);
                }

                if (hex[1] >= '0' and hex[1] <= '9')
                {
                } else if (hex[1] >= 'a' and hex[1] <= 'z')
                {
                } else if (hex[1] >= 'A' and hex[1] <= 'Z')
                {
                    THROW(ParseException, "Unexpected character in hexadecimal literal.", line, COLUMN);
                }

                str.append(strtoul(hex, nullptr, 16));
            } else
            {
                THROW(ParseException, "Invalid escape code.", line, COLUMN);
            }
        } else if (c == '"')
        {
            break;
        } else if (c == '#')
        {
            while (true)
            {
                if (offset == source.getLength())
                {
                    THROW(ParseException, "Unexpected end of source code..", line, COLUMN);
                }

                if (source[offset] == '\n')
                {
                    ADVANCE_LINE;
                    break;
                }

                ++offset;
            }
        } else if (c == '\n')
        {
            ADVANCE_LINE;
            str.append(c);
        } else
        {
            str.append(c);
        }
    }

    return (ASTNode *)NEW(StringNode, str);
}

ASTNode *_parse(const String& source, size_t& offset, size_t& lastLineOffset, size_t& line)
{
    while (true)
    {
        if (offset == source.getLength())
        {
            return (ASTNode *)NEW(StatementsNode);
        }

        char c = source[offset++];

        if (c == ' ' or c == '\t')
        {
        } else if (c == '\n')
        {
            ADVANCE_LINE;
        } else if (c == '(')
        {
            break;
        } else if (c == '#')
        {
            while (true)
            {
                if (source[offset] == '\n')
                {
                    ADVANCE_LINE;
                    break;
                }

                ++offset;
            }
        } else
        {
            THROW(ParseException, "Expected a '('. Got something else.", line, COLUMN);
        }
    }

    List<ASTNode *> nodes;

    while (true)
    {
        if (offset == source.getLength())
        {
            THROW(ParseException, "Unexpected end of source code.", line, COLUMN);
        }

        char c = source[offset++];

        bool isInt = c >= '0' and c <= '9';

        if (offset+1 < source.getLength())
        {
            isInt = isInt or (c == '+' and source[offset+1] >= '0' and source[offset+1] <= '9');
            isInt = isInt or (c == '-' and source[offset+1] >= '0' and source[offset+1] <= '9');
        }

        if (c == ')')
        {
            break;
        } else if (c == '(')
        {
            --offset;

            nodes.append(_parse(source, offset, lastLineOffset, line));
        } else if (source.startsWith("0x", offset-1))
        {
            ++offset; //Skip the 'x'

            nodes.append(parseBase16(source, offset, lastLineOffset, line));
        } else if (source.startsWith("0b", offset-1))
        {
            ++offset; //Skip the 'b'

            nodes.append(parseBase2(source, offset, lastLineOffset, line));
        } else if (isInt)
        {
            --offset;

            nodes.append(parseNumber(source, offset, lastLineOffset, line));
        } else if (c == '"')
        {
            nodes.append(parseString(source, offset, lastLineOffset, line));
        } else if (c == ' ' or c == '\t')
        {
        } else if (c == '\n')
        {
            ADVANCE_LINE;
        } else if (c == '#')
        {
            while (true)
            {
                if (offset == source.getLength())
                {
                    THROW(ParseException, "Unexpected end of source code.", line, COLUMN);
                }

                if (source[offset] == '\n')
                {
                    ADVANCE_LINE;
                    break;
                }

                ++offset;
            }
        } else
        {
            List<String> strs;
            String str;

            --offset;

            while (1)
            {
                if (offset == source.getLength())
                {
                    THROW(ParseException, "Unexpected end of source code.", line, COLUMN);
                }

                char c = source[offset++];

                if (c == ' ' or c == '\t')
                {
                    break;
                } else if (c == '\n')
                {
                    ADVANCE_LINE;
                    break;
                } else if (c == ')' or c == '(')
                {
                    --offset;
                    break;
                } else if (c == '#')
                {
                    while (true)
                    {
                        if (offset == source.getLength())
                        {
                            break;
                        }

                        if (source[offset] == '\n')
                        {
                            ADVANCE_LINE;
                            break;
                        }

                        ++offset;
                    }
                } else if (c == '.')
                {
                    strs.append(str);
                    str = "";
                } else
                {
                    str.append(c);
                }
            }

            strs.append(str);

            nodes.append((ASTNode *)NEW(IdentifierNode, strs));
        }
    }

    return (ASTNode *)NEW(CallNode, nodes);
}

ASTNode *parse(const String& source)
{
    size_t offset = 0;
    size_t lastLineOffset = 0;
    size_t line = 1;

    StatementsNode *result = NEW(StatementsNode);

    while (offset != source.getLength())
    {
        result->statements.append(_parse(source, offset, lastLineOffset, line));
    }

    return result;
}
}
