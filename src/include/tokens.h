#pragma once

#include <iostream>
#include <memory>
#include <stdint.h>
#include <string>

namespace token
{
    enum Token_Type
    {
        LPAREN,
        RPAREN,
        IDENTIFIER,
        INT_LIT,
        FLOAT_LIT,
        STRING_LIT,
        CHAR_LIT,
        SEMI,
        COLON,
        LBRACKET,
        RBRACKET,
        FUNC,
        ARROW,
        RETURN,
        EQU,
        TYPE,
        VAR,
        CONST,
        PLUS,
        MINUS,
        MULT,
        DIV,
        MOD,
        EXP

    };

    class Token
    {
    public:
        Token(Token_Type type, std::string value, uint64_t row, uint64_t col);
        ~Token();

        void set_type(Token_Type type);
        void set_value(std::string value);
        void set_row(uint64_t row);
        void set_col(uint64_t col);

        Token_Type get_type();
        std::string get_value();
        uint64_t get_row();
        uint64_t get_col();

        void print();

    private:
        Token_Type type;
        std::string value;
        uint64_t row;
        uint64_t col;
    };

    std::unique_ptr<Token> create_token(Token_Type type, std::string value, uint64_t row, uint64_t col);

    std::string type_to_string(Token_Type type);

} // token
