#include "cpp_lex.inl"

#include "CppLexer.h"

#include <cstdlib>
#include <chrono>
#include <filesystem>
#include <fstream>
#include <sstream>

std::wstring read_all_text(std::filesystem::path const & path)
{
    std::wifstream in(path);
    std::wstringstream buffer;
    buffer << in.rdbuf();
    return buffer.str();
}

using hrclock = std::chrono::high_resolution_clock;

hrclock::duration lex_file(std::filesystem::path const & path)
{
    auto content = read_all_text(path);
    auto start = hrclock::now();
    CppLexer lexer(content);
    for (int i = 0; i != 100; ++i)
    {
        for (lexer.Start(); lexer.GetTokenType(); lexer.Advance())
        {
        }
    }
    return hrclock::now() - start;
}

void writeline(hrclock::duration duration)
{
    std::cout << std::fixed << std::setw(7) << std::chrono::duration_cast<std::chrono::microseconds>(duration).count() / 1e6 << std::endl;
}

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        std::cerr << "Path to file or directory expected" << std::endl;
        return EXIT_FAILURE;
    }

    std::filesystem::path path(argv[1]);
    if (is_directory(path))
    {
        for (std::filesystem::directory_iterator it(path), end; it != end; ++it)
        {
            if (!it->is_regular_file())
                continue;

            auto file = it->path();
            if (file.extension() != ".cpp")
                continue;

            auto duration = lex_file(file);
            std::cout << file.stem() << ": ";
            writeline(duration);
        }
    }
    else if (path.extension() == ".cpp")
    {
        auto duration = lex_file(path);
        writeline(duration);
    }
    else
    {
        std::cerr << "Path to .cpp file expected" << std::endl;
        return EXIT_FAILURE;
    }
}