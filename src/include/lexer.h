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

    const std::unordered_set<char> arithmetic_op = {
        '+', '-', '*', '/'
    };

    const std::unordered_map<std::string, token::Token_Type> reserved_idents = {
        {"func", token::FUNC},      {"return", token::RETURN},  {"int", token::TYPE},
        {"float", token::TYPE},     {"string", token::TYPE},    {"var", token::VAR},
        {"const", token::CONST},    {"and", token::AND},        {"or", token::OR},
        {"not", token::NOT},        {"xor", token::XOR},        {"bool", token::TYPE},
        {"void", token::TYPE},      {"true", token::BOOL_LIT},  {"false", token::BOOL_LIT}
    };

    class Lexer {
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
        int tab_width;

        char cur_char();

        char peek();
        void eat_char();
        void eat_whitespace();
        token::Token eat_string_lit();
        token::Token eat_paren();
        token::Token eat_bracket();
        token::Token eat_numeric();
        token::Token eat_arithmetic();
        token::Token eat_ident();
    };
}
