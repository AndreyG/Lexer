#pragma once

#include "TokenNodeType.h"
#include "cpp_lex.h"

struct CppLexer
{
    void Start();
    void Advance();

    TokenNodeType* GetTokenType() const;
    
    CppLexer(IBuffer const & buffer);

private:
    CppLexerGenerated myInner;
};
