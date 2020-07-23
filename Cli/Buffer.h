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

ref class StringBuffer
{
    initonly String^ myText;

public:
    StringBuffer(String^ text)
        : myText(text)
    {}

    property wchar_t default[int]
    {
        wchar_t get(int i) { return myText[i]; }
    }

    property int Length
    {
        int get() { return myText->Length; }
    }

    String^ GetText(TextRange range)
    {
        return myText->Substring(range.StartOffset, range.Length);
    }
};

inline bool CompareBufferText(StringBuffer^ buffer, TextRange range, String^ str)
{
    int len = str->Length;
    if (len != range.Length)
        return false;

    int pos = range.StartOffset;
    if (pos + len > buffer->Length)
        return false;

    for (int j = 0; j < len; j++, pos++)
    {
        if (str[j] != buffer[pos])
            return false;
    }
    return true;
}
