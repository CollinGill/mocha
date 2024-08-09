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
    this->tab_width = 8;
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
    token::Token new_tok;
    while (this->file_index < this->file_size) {
        current_char = this->cur_char(); 

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

        } else if (current_char == '{' || current_char == '}') {
            this->token_list.push_back(this->eat_bracket());

        } else if (current_char == '=') {
            new_tok.set_row(this->row);
            new_tok.set_col(this->col);

            if (this->peek() == '>') {
                new_tok.set_type(token::ARROW);
                new_tok.set_value("=>");
                this->eat_char();

            } else {
                new_tok.set_type(token::EQU);
                new_tok.set_value("=");

            }

            this->token_list.push_back(new_tok);
            this->eat_char();

        } else if (current_char == ';') {
            new_tok.set_type(token::SEMI);
            new_tok.set_value(";");
            new_tok.set_row(this->row);
            new_tok.set_col(this->col);

            this->token_list.push_back(new_tok);
            this->eat_char();

        } else if (current_char == ':') {
            new_tok.set_type(token::COLON);
            new_tok.set_value(":");
            new_tok.set_row(this->row);
            new_tok.set_col(this->col);

            this->token_list.push_back(new_tok);
            this->eat_char();

        } else if (isdigit(current_char) || current_char == '.') {
            if (current_char == '.' && !isdigit(this->peek())) {
                std::cout << "ERROR: Invalid float at (" << this->row << ", " << this->col << ")\n";
                exit(1);
                break;
            }

            this->token_list.push_back(this->eat_numeric());

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

char Lexer::cur_char()
{
    if (this->file_index >= this->file_size) {
        return '\0';
    }

    return this->file_contents[this->file_index];

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
    switch (this->cur_char()) {
        case ' ':
            this->col++;
            break;
        case '\n':
            this->row++;
            this->col = 1;
            break;
        case '\t':
            this->col += this->tab_width;
            break;

        default:
            break;
    }

    this->file_index++;
}

token::Token Lexer::eat_string_lit()
{
    // TODO: Add support for escape characters

    int row_start = this->row, col_start = this->col;
    int index_start = this->file_index;

    while (this->file_index < this->file_size) {
        if (this->cur_char() == '"' && this->file_index != index_start) {
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

    if (this->cur_char() == '(') {
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

token::Token Lexer::eat_bracket()
{
    token::Token new_tok;

    if (this->cur_char() == '{') {
        new_tok.set_type(token::LBRACKET);
        new_tok.set_value("{");

    } else {
        new_tok.set_type(token::RBRACKET);
        new_tok.set_value("}");

    }

    new_tok.set_row(this->row);
    new_tok.set_col(this->col);

    this->eat_char();
    return new_tok;
}

token::Token Lexer::eat_numeric()
{
    token::Token new_token;
    new_token.set_row(this->row);
    new_token.set_col(this->col);
    int start = this->file_index;

    int decimal_count = 0;

    while (this->file_index < this->file_size) {
        if (this->cur_char() == '.') {
            this->eat_char();
            decimal_count++;
            if (decimal_count > 1) {
                return new_token;
            }
        } else if (isdigit(this->cur_char())) {
            this->eat_char();

        } else {
            if (decimal_count > 0) {
                new_token.set_type(token::FLOAT_LIT);

            } else {
                new_token.set_type(token::INT_LIT);

            }

            new_token.set_value(this->file_contents.substr(start, this->file_index - start));
            break;
        }
    }

    return new_token;
}

void Lexer::eat_arithmetic()
{

}

void Lexer::eat_ident()
{
    this->eat_char();
}
