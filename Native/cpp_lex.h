#pragma once

#include "CppTokenNodeType.h"
#include "Buffer.h"

#include <iostream>

struct TokenPosition
{
    TokenNodeType* CurrTokenType;
    int YyBufferIndex;
    int YyBufferStart;
    int YyBufferEnd;
    int YyLexicalState;
};

struct CppLexerGenerated
{
private:
    static const int YY_F = -1;
    static const int YY_NO_STATE = -1;
    static const int YY_BOL = 65536;
    static const int YY_EOF = 65537;


private:
    TokenNodeType* currTokenType;
    bool lexDirectives;
public:
    void Start();
    void Start(int startOffset, int endOffset);
    void Start(int startOffset, int endOffset, unsigned state, int lastTokenLen);
    void Advance();
    void ReadRawStringLiteral()
    {
        int start = yy_buffer_index;
        while(yy_buffer_index < yy_eof_pos && yy_buffer[yy_buffer_index] != '(')
            yy_buffer_index ++;
        auto delimiter = yy_buffer.GetText(TextRange(start, yy_buffer_index));
        while(yy_buffer_index < yy_eof_pos)
        {
            while(yy_buffer_index < yy_eof_pos && yy_buffer[yy_buffer_index] != ')')
                yy_buffer_index ++;
            if (CompareBufferText(yy_buffer, TextRange::FromLength(yy_buffer_index + 1, delimiter.length()), delimiter))
            {
                yy_buffer_index = yy_buffer_index + 1 + delimiter.length();
                if (yy_buffer_index < yy_eof_pos && yy_buffer[yy_buffer_index] == '"')
                {
                    yy_buffer_index ++;
                    yy_buffer_end = yy_buffer_index;
                    return;
                }
            }
            else if (yy_buffer_index < yy_eof_pos)
                yy_buffer_index ++;
        }
        yy_buffer_index = start;
        while(yy_buffer_index < yy_eof_pos && yy_buffer[yy_buffer_index] != '"' && !yy_isnewline(yy_buffer[yy_buffer_index]))
            yy_buffer_index ++;
        if (yy_buffer_index == yy_eof_pos || yy_isnewline(yy_buffer[yy_buffer_index]))
            yy_buffer_index--;
        else if (yy_buffer[yy_buffer_index] == '"' && yy_buffer_index + 1 < yy_eof_pos)
            yy_buffer_index ++;
        yy_buffer_end = yy_buffer_index;
    }

    TokenNodeType* GetTokenType() const;

    TokenNodeType* ProcessDirectiveOrHash(int state, TokenNodeType* directive)
    {
        if (lexDirectives)
        {
            yybegin(state);
            return directive;
        }
        if (directive == CppTokenNodeTypes::EMPTY_DIRECTIVE)
        {
            // Rollback, retain all the input except the `#` itself
            yy_buffer_end = yy_buffer_index = yy_buffer_start + 1;
            return currTokenType = CppTokenNodeTypes::HASH;
        }
        else
            return currTokenType = CppTokenNodeTypes::HASHED_IDENTIFIER;
    }
private:
    int yy_buffer_index;
    int yy_buffer_start;
    int yy_buffer_end;
    StringBuffer const & yy_buffer; // external resource;
    int yy_eof_pos;
    int yyline;
    bool yy_at_bol;
    int yy_lexical_state;

public:
  CppLexerGenerated(StringBuffer const & buffer) : yy_last_was_cr(false), yy_buffer(buffer)
  {
  yy_buffer_index = 0;
  yy_buffer_start = 0;
  yy_buffer_end = 0;
  yyline = 0;
  yy_at_bol = true;
  yy_lexical_state = YYINITIAL;

    currTokenType = nullptr;
    lexDirectives = true;
  yy_eof_pos = yy_buffer.length();
  }

private:
    static const int DOXYGEN = 4;
    static const int INCLUDE_DIRECTIVE = 3;
    static const int YYINITIAL = 0;
    static const int CODE_DIRECTIVE = 2;
    static const int DIRECTIVE = 1;
private: void yybegin (int state)
  {
  yy_lexical_state = state;
  }

private: void yy_move_end ()
  {
  if (yy_buffer_end > yy_buffer_start && 
      '\n' == yy_buffer[yy_buffer_end-1])
    yy_buffer_end--;
  if (yy_buffer_end > yy_buffer_start &&
      '\r' == yy_buffer[yy_buffer_end-1])
    yy_buffer_end--;
  }
private:
    bool yy_last_was_cr;
private: void yy_mark_start ()
  {
  int i;
  for (i = yy_buffer_start; i < yy_buffer_index; i++)
    {
    if (yy_buffer[i] == '\n' && !yy_last_was_cr)
      {
      yyline++;
      }
    if (yy_buffer[i] == '\r')
      {
      yyline++;
      yy_last_was_cr=true;
      }
    else
      {
      yy_last_was_cr=false;
      }
    }
  yy_buffer_start = yy_buffer_index;
  }
private: void yy_mark_end ()
  {
  yy_buffer_end = yy_buffer_index;
  }
private: static bool yy_isnewline (wchar_t c)
  {
    return c == '\r' || c == '\n';
  }
 std::wstring yytext()
  {
  return  yy_buffer.GetText(TextRange(yy_buffer_start, yy_buffer_end));
  }
private: int yylength ()
  {
  return yy_buffer_end - yy_buffer_start;
  }
private:
    static const int YY_E_INTERNAL = 0;
    static const int YY_E_MATCH = 1;
private: static inline const std::wstring yy_error_string[] = 
  {
  L"Error: Internal error.\n",
  L"Error: Unmatched input.\n"
  };
private: void yy_error (int code,bool fatal)
  {
  std::wcerr << yy_error_string[code] << std::endl;
  if (fatal)
    {
    throw std::runtime_error("Fatal Error.\n");
    }
  }
public:
    TokenNodeType* _locateToken();

};

