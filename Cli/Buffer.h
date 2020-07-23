#pragma once

value struct TextRange
{
    initonly int StartOffset, EndOffset;

    property int Length
    {
        int get()
        {
            return EndOffset - StartOffset;
        }
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

using System::String;

value struct wstring_view
{
    initonly wchar_t const * myText;
    initonly int myLength;

public:
    wstring_view(wchar_t const * text, int length)
        : myText(text)
        , myLength(length)
    {}

    property wchar_t default[int]
    {
        wchar_t get(int i) { return myText[i]; }
    }

    property int Length
    {
        int get() { return myLength; }
    }

    wstring_view GetText(TextRange range)
    {
        return wstring_view { myText + range.StartOffset, range.Length };
    }
};

inline bool CompareBufferText(wstring_view buffer, TextRange range, wstring_view str)
{
    int len = str.Length;
    if (len != range.Length)
        return false;

    int pos = range.StartOffset;
    if (pos + len > buffer.Length)
        return false;

    for (int j = 0; j < len; j++, pos++)
    {
        if (str[j] != buffer[pos])
            return false;
    }
    return true;
}
