use crate::token::Token;

pub struct Scanner {
    pub src_code: Vec<char>,
    pub tokens : Vec<Token>,
    pub index : usize,
    pub line: usize,
    pub col: usize,
}

impl Scanner {
    pub fn tokenize(&mut self) {
        let mut buf: Vec<char> = Vec::new();

        loop {
            match self.peek(0) {
                None => {break;}

                Some(cur_) => {
                    if cur_.is_whitespace()
                    {
                        if cur_ == '\n'
                        {
                            self.line += 1;
                            self.col = 0;
                        }

                        else { self.col += 1; }

                        self.consume(1);

                    }

                    else if cur_ == ';'
                    {
                        let tok = Token {
                            line: self.line,
                            col: self.col,
                            type_: String::from("SEMI"),
                            value: String::from(";")
                        };

                        self.tokens.push(tok);
                        self.col += 1;
                        self.consume(1);

                    }

                    else if cur_ == ','
                    {
                        let tok = Token {
                            line: self.line,
                            col: self.col,
                            type_: String::from("COMMA"),
                            value: String::from(",")
                        };

                        self.tokens.push(tok);
                        self.col += 1;
                        self.consume(1);

                    }

                    else if cur_ == '('
                    {
                        let tok = Token {
                            line: self.line,
                            col: self.col,
                            type_: String::from("L-PAREN"),
                            value: String::from("(")
                        };

                        self.tokens.push(tok);
                        self.col += 1;
                        self.consume(1);

                    }

                    else if cur_ == ')'
                    {
                        let tok = Token {
                            line: self.line,
                            col: self.col,
                            type_: String::from("R-PAREN"),
                            value: String::from(")")
                        };

                        self.tokens.push(tok);
                        self.col += 1;
                        self.consume(1);

                    }

                    else if cur_ == '{'
                    {
                        let tok = Token {
                            line: self.line,
                            col: self.col,
                            type_: String::from("L-BRACKET"),
                            value: String::from("{")
                        };

                        self.tokens.push(tok);
                        self.col += 1;
                        self.consume(1);

                    }

                    else if cur_ == '}'
                    {
                        let tok = Token {
                            line: self.line,
                            col: self.col,
                            type_: String::from("R-BRACKET"),
                            value: String::from("}")
                        };

                        self.tokens.push(tok);
                        self.col += 1;
                        self.consume(1);

                    }

                    else if cur_ == ':'
                    {
                        let tok = Token {
                            line: self.line,
                            col: self.col,
                            type_: String::from("COLON"),
                            value: String::from(":")
                        };

                        self.tokens.push(tok);
                        self.col += 1;
                        self.consume(1);

                    }

                    else if cur_ == '='
                    {
                        let tok:  Token;
                        match self.peek(1) {
                            Some(ch) => {
                                if ch == '>' {
                                    tok = Token {
                                        line: self.line,
                                        col: self.col,
                                        type_: String::from("ARROW"),
                                        value: String::from("=>")
                                    };
                                    self.col += 2;
                                    self.consume(2);

                                } else {
                                    tok = Token {
                                        line: self.line,
                                        col: self.col,
                                        type_: String::from("EQU"),
                                        value: String::from("=")
                                    };
                                    self.col += 1;
                                    self.consume(1);
                                }
                            }

                            None => {
                                tok = Token {
                                    line: self.line,
                                    col: self.col,
                                    type_: String::from("EQU"),
                                    value: String::from("=")
                                };

                                self.col += 1;
                                self.consume(1);
                            }
                        }

                        self.tokens.push(tok);

                    }

                    // Identifiers and keywords
                    else if cur_.is_alphabetic() || cur_ == '_'
                    {
                        loop {
                            match self.peek(0) {
                                Some(cur) => {
                                    if cur.is_alphanumeric() || cur == '_'
                                    {
                                        buf.push(cur);
                                        self.consume(1);

                                    }

                                    else { break; }
                                }

                                None => { break; }
                            }
                        }

                        let token_name: String = buf.iter().collect();
                        let token_len: usize = token_name.len();
                        let tok: Token;

                        if token_name == "func"
                        {
                            tok = Token {
                                line: self.line,
                                col: self.col,
                                type_: String::from("FUNC"),
                                value: String::from(token_name)
                            };

                            self.tokens.push(tok);
                        }

                        else if token_name == "return"
                        {
                            tok = Token {
                                line: self.line,
                                col: self.col,
                                type_: String::from("RETURN"),
                                value: String::from(token_name)
                            };
                            self.tokens.push(tok);

                        }

                        else if token_name == "var"
                        {
                            tok = Token {
                                line: self.line,
                                col: self.col,
                                type_: String::from("VAR"),
                                value: String::from(token_name)
                            };
                            self.tokens.push(tok);
                        }

                        else if token_name == "const"
                        {
                            tok = Token {
                                line: self.line,
                                col: self.col,
                                type_: String::from("CONST"),
                                value: String::from(token_name)
                            };
                            self.tokens.push(tok);
                        }

                        // Data types
                        else if token_name == "void"
                            || token_name == "int"
                            || token_name == "float"
                            || token_name == "string"
                            || token_name == "char"
                        {
                            tok = Token {
                                line: self.line,
                                col: self.col,
                                type_: String::from("TYPE"),
                                value: String::from(token_name)
                            };
                            self.tokens.push(tok);

                        }

                        else
                        {
                            tok = Token {
                                line: self.line,
                                col: self.col,
                                type_: String::from("IDENTIFIER"),
                                value: String::from(token_name)
                            };
                            self.tokens.push(tok);
                        }

                        self.col += token_len;
                        buf.clear();

                    }

                    // Numbers
                    else if cur_.is_numeric()
                    {
                        let mut has_radix = false;

                        loop {
                            match self.peek(0) {
                                Some(cur) => {
                                    if cur.is_numeric()
                                    {
                                        buf.push(cur);
                                        self.consume(1);
                                    }

                                    else if cur == '.'
                                    {
                                        if has_radix
                                        {
                                            eprintln!("ERROR: Invalid syntax\nLine: {}\nCol: {}",
                                                      self.line, self.col);
                                        }

                                        has_radix = true;
                                        buf.push(cur);
                                        self.consume(1);
                                    }

                                    else {break;}
                                }

                                None => {break;}
                            }

                            let token_value: String = buf.iter().collect();
                            let token_len: usize = token_value.len();
                            let tok: Token;

                            if has_radix
                            {
                                tok = Token {
                                    line:  self.line,
                                    col: self.col,
                                    type_: String::from("FLOAT-LIT"),
                                    value: token_value
                                };
                            }

                            else
                            {
                                tok = Token {
                                    line:  self.line,
                                    col: self.col,
                                    type_: String::from("INT-LIT"),
                                    value: token_value
                                };
                            }

                            self.tokens.push(tok);
                            self.col += token_len;
                            buf.clear();
                        }

                    }

                    // String literals
                    else if cur_ == '"'
                    {
                        buf.push(cur_);
                        self.consume(1);

                        loop {
                            match self.peek(0) {
                                Some(cur) => {
                                    buf.push(cur);
                                    self.consume(1);
                                    if cur == '"'
                                    {
                                        break;
                                    }
                                }

                                None => {break;}
                            }
                        }

                        let token_value: String = buf.iter().collect();
                        let token_len: usize = token_value.len();

                        let tok = Token {
                            line: self.line,
                            col: self.col,
                            type_: String::from("STRING-LIT"),
                            value: String::from(token_value)
                        };

                        self.tokens.push(tok);
                        self.col += token_len;
                        buf.clear();
                    }

                    else
                    {
                        // Placeholder
                        self.col += 1;
                        self.consume(1);
                    }
                }
            }
        }
    }

    fn peek(&self, offset: usize) -> Option<char>{
        if self.index + offset < self.src_code.len() {
            Some(self.src_code[self.index + offset])
        } else {
            None
        }
    }

    fn consume(&mut self, to_consume: usize) {
        self.index += to_consume;
    }

}