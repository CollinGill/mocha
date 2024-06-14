#include "include/tokens.h"

using namespace std;
using namespace token;

Token::Token(Token_Type type, std::string value, uint64_t row, uint64_t col)
{
    this->set_value(value);
    this->set_type(type);
    this->set_row(row);
    this->set_col(col);
}

Token::~Token() {}

// Public methods
void Token::print()
{
    cout << "<" << type_to_string(this->type) << ", " << this->value << ">";
}

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

// Helper functions
unique_ptr<Token> create_token(Token_Type type, string value, uint64_t row, uint64_t col)
{
    unique_ptr<Token> new_tok(new Token(type, value, row, col));
    return new_tok;
}

string token::type_to_string(Token_Type type)
{
    switch (type)
    {
    case LPAREN:
        return "LPAREN";

    case RPAREN:
        return "RPAREN";

    default:
        return "ERROR: INVALID TYPE";
    }
}