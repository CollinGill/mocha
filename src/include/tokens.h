#pragma once

#include <memory>
#include <stdint.h>
#include <string>

namespace token
{
    enum Token_Type
    {
        LPAREN,
        RPAREN,
    };

    class Token
    {
    public:
        Token();
        ~Token();

        void set_type(Token_Type type);
        void set_value(std::string value);
        void set_row(uint64_t row);
        void set_col(uint64_t col);

        Token_Type get_type();
        std::string get_value();
        uint64_t get_row();
        uint64_t get_col();

    private:
        Token_Type type;
        std::string value;
        uint64_t row;
        uint64_t col;
    };

} // namespace name
