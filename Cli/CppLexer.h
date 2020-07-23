#pragma once

#include "TokenNodeType.h"
#include "cpp_lex.h"

interface class IBuffer;

value struct CppLexer
{
    void Start();
    void Advance();

    property TokenNodeType^ TokenType
    {
        TokenNodeType^ get();
    }

    CppLexer(StringBuffer^ buffer);

private:
    CppLexerGenerated myInner;
};
