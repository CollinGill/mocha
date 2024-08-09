#include "include/lexer.h"
#include "include/tokens.h"

using namespace lexer;

Lexer::Lexer()
{
    this->file_index = 0;
    this->token_list = std::vector<token::Token>();
    this->row = 1;
    this->col = 1;
    this->file_size = 0;
}

void Lexer::lex_file(const std::string& file_contents)
{
    this->file_contents = file_contents;
    this->file_size = file_contents.length();

    // Iterate through file
    // If the character is whitesace, eat_whitespace()
    // If character is a ", eat_string_lit()
    // Repeat for all special characters, left over characters should be identifiers like func, variable names etc.
    // For those remaining characters, eat_ident()

    char current_char;
    while (this->file_index < this->file_size) {
        current_char = this->file_contents[this->file_index];

        if (whitespace.find(current_char) != whitespace.end()) {
            this->eat_whitespace();

        } else if (current_char == '"') {
            int start_row = this->row;
            int start_col = this->col;
            token::Token new_tok = this->eat_string_lit();

            if (new_tok.get_type() == token::NONE) {
                std::cout << "ERROR: unclosed string literal at (" << start_row << ", " << start_col << ")\n";
                exit(1);
                break;
            }

            this->token_list.push_back(new_tok);

        } else if (current_char == '(' || current_char == ')') {
            this->token_list.push_back(this->eat_paren());

        } else {
            this->eat_ident();
        }
    }
}

std::vector<token::Token> Lexer::get_token_list()
{
    return this->token_list;
}

void Lexer::print_token_list()
{
    std::cout << "TOKEN LIST\n";
    for (token::Token& token : this->token_list) {
        std::cout << "\t";
        token.print();
        std::cout << "\n";
    }
}

char Lexer::peek()
{
    if (this->file_index + 1 >= this->file_size) {
        return '\0';
    }

    return this->file_contents[this->file_index + 1];
}

void Lexer::eat_char()
{
    this->file_index++;
    this->col++;
}

void Lexer::eat_whitespace()
{
    char current_char = this->file_contents[this->file_index];
    this->file_index++;

    switch (current_char) {
        case ' ':
            this->col++;
            break;
        case '\n':
            this->row++;
            this->col = 1;
            break;
        case '\t':
            this->col += 4;
            break;

        default:
            break;
    }
}

token::Token Lexer::eat_string_lit()
{
    // TODO: Add support for escape characters

    int row_start = this->row, col_start = this->col;
    int index_start = this->file_index;

    while (this->file_index < this->file_size) {
        if (this->file_contents[this->file_index] == '"' && this->file_index != index_start) {
            token::Token new_token = token::Token(
                token::STRING_LIT, this->file_contents.substr(index_start, this->file_index - index_start + 1), 
                row_start, col_start
            );

            this->eat_char();
            return new_token;
        }

        this->eat_char();
    }

    return token::Token();
}

token::Token Lexer::eat_paren()
{
    token::Token new_tok;

    if (this->file_contents[this->file_index] == '(') {
        new_tok.set_type(token::LPAREN);
        new_tok.set_value("(");

    } else {
        new_tok.set_type(token::RPAREN);
        new_tok.set_value(")");

    }

    new_tok.set_row(this->row);
    new_tok.set_col(this->col);

    this->eat_char();
    return new_tok;
}

void Lexer::eat_numeric()
{

}

void Lexer::eat_arithmetic()
{

}

void Lexer::eat_ident()
{
    this->eat_char();
}
