#pragma once

#include <string>

struct TextRange
{
    const int StartOffset, EndOffset;

    int length() const
    {
        return EndOffset - StartOffset;
    }

    TextRange(int start, int end)
        : StartOffset(start)
        , EndOffset(end)
    {}

    static TextRange FromLength(int start, int len)
    {
        return TextRange(start, start + len);
    }
};

inline bool CompareBufferText(std::wstring_view buffer, TextRange range, std::wstring_view str)
{
    int len = str.length();
    if (len != range.length())
        return false;

    int pos = range.StartOffset;
    if (pos + len > static_cast<int>(buffer.length()))
        return false;

    for (int j = 0; j < len; j++, pos++)
    {
        if (str[j] != buffer[pos])
            return false;
    }
    return true;
}
