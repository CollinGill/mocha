#pragma once

#include <cstdlib>
#include <iostream>
#include <unordered_set>
#include <vector>

#include "tokens.h"

namespace lexer {
    const std::unordered_set<char> whitespace = {
        ' ', '\n', '\t'
    };
    
    class Lexer 
    {
    public:
        Lexer();

        void lex_file(const std::string& file_contents);
        std::vector<token::Token> get_token_list();

        void print_token_list();

    private:
        std::vector<token::Token> token_list;

        // Used to keep track of current placement in file
        std::string file_contents;
        int file_size;
        int file_index;
        int row;
        int col;

        char peek();
        void eat_char();
        void eat_whitespace();
        token::Token eat_string_lit();
        token::Token eat_paren();
        void eat_numeric();
        void eat_arithmetic();
        void eat_ident();
    };
}
