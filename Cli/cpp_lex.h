#pragma once

#include "CppTokenNodeType.h"
#include "Buffer.h"

value struct TokenPosition
{
    TokenNodeType^ CurrTokenType;
    int YyBufferIndex;
    int YyBufferStart;
    int YyBufferEnd;
    int YyLexicalState;
};

value struct CppLexerGenerated
{
private:
    literal int YY_F = -1;
    literal int YY_NO_STATE = -1;
    literal int YY_BOL = 65536;
    literal int YY_EOF = 65537;


private:
    TokenNodeType^ currTokenType;
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
            if (CompareBufferText(yy_buffer, TextRange::FromLength(yy_buffer_index + 1, delimiter.Length), delimiter))
            {
                yy_buffer_index = yy_buffer_index + 1 + delimiter.Length;
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
    property TokenNodeType^ TokenType 
    { 
      TokenNodeType^ get(); 
    }
    TokenNodeType^ ProcessDirectiveOrHash(int state, TokenNodeType^ directive)
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
    wstring_view yy_buffer; // external resource;
    int yy_eof_pos;
    int yyline;
    bool yy_at_bol;
    int yy_lexical_state;

public:
  CppLexerGenerated(wstring_view buffer) : yy_last_was_cr(false), yy_buffer(buffer)
  {
  yy_buffer_index = 0;
  yy_buffer_start = 0;
  yy_buffer_end = 0;
  yyline = 0;
  yy_at_bol = true;
  yy_lexical_state = YYINITIAL;

    currTokenType = nullptr;
    lexDirectives = true;
  yy_eof_pos = yy_buffer.Length;
  }

protected:
    literal int DOXYGEN = 4;
    literal int INCLUDE_DIRECTIVE = 3;
    literal int YYINITIAL = 0;
    literal int CODE_DIRECTIVE = 2;
    literal int DIRECTIVE = 1;
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
private: int yylength ()
  {
  return yy_buffer_end - yy_buffer_start;
  }
private:
    literal int YY_E_INTERNAL = 0;
    literal int YY_E_MATCH = 1;
private: static array<String^>^ yy_error_string = gcnew array<String^>
  {
  "Error: Internal error.\n",
  "Error: Unmatched input.\n"
  };
private: void yy_error (int code,bool fatal)
  {
  System::Console::Write(yy_error_string[code]);
  if (fatal)
    {
    throw gcnew System::ApplicationException("Fatal Error.\n");
    }
  }
public:
    TokenNodeType^ _locateToken();

};

