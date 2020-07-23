#include "cpp_lex.inl"

#include "CppLexer.h"

#include <cstdlib>

System::TimeSpan lex_file(String^ path)
{
    auto content = System::IO::File::ReadAllText(path);
    auto stopwatch = System::Diagnostics::Stopwatch::StartNew();
    auto buffer = gcnew StringBuffer(content);
    CppLexer lexer(buffer);
    for (int i = 0; i != 100; ++i)
    {
        for (lexer.Start(); lexer.TokenType; lexer.Advance())
        {
        }
    }
    return stopwatch->Elapsed;
}

void jit_lexer()
{
    auto lexer = gcnew CppLexer(gcnew StringBuffer("int"));
    lexer->Start();
    lexer->Advance();
}

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        System::Console::WriteLine("Path to file or directory expected");
        return EXIT_FAILURE;
    }
    jit_lexer();
    auto path = gcnew String(argv[1]);
    auto fileAttrs = System::IO::File::GetAttributes(path);
    if (fileAttrs.HasFlag(System::IO::FileAttributes::Directory))
    {
        for each (String^ file in System::IO::Directory::EnumerateFiles(path, "*.cpp"))
        {
            auto duration = lex_file(file);
            auto backslash = file->LastIndexOf(L'\\');
            auto filename = file->Substring(backslash + 1, file->Length - backslash - 5);
            System::Console::WriteLine("\"{0}\": {1}", filename, duration.TotalMilliseconds / 1000);
        }
    }
    else if (path->EndsWith(".cpp"))
    {
        auto duration = lex_file(path);
        System::Console::WriteLine(duration);
    }
    else
    {
        System::Console::WriteLine("Path to .cpp file expected");
        return EXIT_FAILURE;
    }
}