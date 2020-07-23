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

struct IBuffer
{
    virtual wchar_t operator[](int) const = 0;
    virtual int length() const = 0;

    virtual std::wstring GetText(TextRange) const = 0;

    virtual ~IBuffer() = default;
};

class StringBuffer : public IBuffer
{
    std::wstring myText;

public:
    StringBuffer(std::wstring text)
        : myText(std::move(text))
    {}

    wchar_t operator[](int i) const { return myText[i]; }
    int length() const { return static_cast<int>(myText.length()); }

    std::wstring GetText(TextRange range) const
    {
        return myText.substr(range.StartOffset, range.length());
    }
};

inline bool CompareBufferText(IBuffer const & buffer, TextRange range, std::wstring const & str)
{
    int len = str.length();
    if (len != range.length())
        return false;

    int pos = range.StartOffset;
    if (pos + len > buffer.length())
        return false;

    for (int j = 0; j < len; j++, pos++)
    {
        if (str[j] != buffer[pos])
            return false;
    }
    return true;
}