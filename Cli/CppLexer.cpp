#include "CppLexer.h"

#include "CppTokenNodeType.h"

void CppLexerGenerated::Start()
{
    Start(0, yy_buffer->Length, yy_lexical_state, 0);
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

TokenNodeType^ CppLexerGenerated::TokenType::get()
{
    return currTokenType;
}


#define INNER_LEXER_STATE_OFFSET 28
#define INNER_LEXER_TOKEN_LENGTH 20


CppLexer::CppLexer(IBuffer^ buffer)
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

TokenNodeType^ CppLexer::TokenType::get()
{
    return myInner.TokenType;
}
