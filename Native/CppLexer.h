#pragma once

#include "TokenNodeType.h"
#include "cpp_lex.h"

struct CppLexer
{
    void Start();
    void Advance();

    TokenNodeType* GetTokenType() const;
    
    CppLexer(std::wstring_view buffer);

private:
    CppLexerGenerated myInner;
};
