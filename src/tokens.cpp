#include "include/tokens.h"

using namespace std;
using namespace token;

Token::Token() {}

Token::~Token() {}

// Getters and Setters

void Token::set_type(Token_Type type)
{
    this->type = type;
}

void Token::set_value(string value)
{
    this->value = value;
}

void Token::set_row(uint64_t row)
{
    this->row = row;
}

void Token::set_col(uint64_t col)
{
    this->col = col;
}

Token_Type Token::get_type()
{
    return this->type;
}

string Token::get_value()
{
    return this->value;
}

uint64_t Token::get_row()
{
    return this->row;
}

uint64_t Token::get_col()
{
    return this->col;
}
