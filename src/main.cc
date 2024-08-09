#include <filesystem>
#include <iostream>

#include "include/io.h"
#include "include/lexer.h"

int main(int argc, char *argv[])
{
    if (argc != 2) {
        std::cerr << "ERROR: Not enough aruments\n";
        return 1;
    }

    std::string file_name = std::string(argv[1]);
    if (!file_name.ends_with(".moc")) {
        std::cerr << "ERROR: " << file_name << " is not a valid Mocha file\n";
        return 1;
    }

    if (!std::filesystem::exists(file_name)) {
        std::cerr << "ERROR: " << file_name << " does not exist\n";
        return 1;
    }

    Io io;
    lexer::Lexer lex;

    io.read_file(file_name);
    std::cout << io.get_file_contents() << "\n";

    lex.lex_file(io.get_file_contents());
    lex.print_token_list();

    return 0;
}
