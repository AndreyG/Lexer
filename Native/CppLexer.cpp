#include "CppLexer.h"

#include "CppTokenNodeType.h"

void CppLexerGenerated::Start()
{
    Start(0, yy_buffer.length(), yy_lexical_state, 0);
}

void CppLexerGenerated::Start(int startOffset, int endOffset)
{
    Start(startOffset, endOffset, yy_lexical_state, 0);
}

void CppLexerGenerated::Start(int startOffset, int endOffset, unsigned state, int lastTokenLen)
{
    yy_buffer_index = startOffset;
    yy_buffer_start = startOffset - lastTokenLen;
    yy_buffer_end = startOffset;
    yy_eof_pos = endOffset;
    yy_lexical_state = (int)state;
    currTokenType = _locateToken();
}

void CppLexerGenerated::Advance()
{
    currTokenType = _locateToken();
}

TokenNodeType* CppLexerGenerated::GetTokenType() const
{
    return currTokenType;
}

#define INNER_LEXER_STATE_OFFSET 28
#define INNER_LEXER_TOKEN_LENGTH 20


CppLexer::CppLexer(std::wstring_view buffer)
    : myInner(buffer)
{}

void CppLexer::Start()
{
    myInner.Start();
}

void CppLexer::Advance()
{
    myInner.Advance();
}

TokenNodeType* CppLexer::GetTokenType() const
{
    return myInner.GetTokenType();
}
