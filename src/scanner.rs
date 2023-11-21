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
                Some(cur_) => {
                    if cur_.is_whitespace() {
                        if cur_ == '\n' {
                            self.line += 1;
                            self.col = 0;
                        } else {
                            self.col += 1;
                        }

                        self.consume();

                    } else if cur_ == ';' {
                        let tok = Token {
                            line: self.line,
                            col: self.col,
                            type_: String::from("SEMI"),
                            value: String::from(";")
                        };

                        self.tokens.push(tok);
                        self.col += 1;
                        self.consume();

                    } else if cur_ == ',' {
                        let tok = Token {
                            line: self.line,
                            col: self.col,
                            type_: String::from("COMMA"),
                            value: String::from(",")
                        };

                        self.tokens.push(tok);
                        self.col += 1;
                        self.consume();

                    } else if cur_ == '(' {
                        let tok = Token {
                            line: self.line,
                            col: self.col,
                            type_: String::from("L-PAREN"),
                            value: String::from("(")
                        };

                        self.tokens.push(tok);
                        self.col += 1;
                        self.consume();

                    } else if cur_ == ')' {
                        let tok = Token {
                            line: self.line,
                            col: self.col,
                            type_: String::from("R-PAREN"),
                            value: String::from(")")
                        };

                        self.tokens.push(tok);
                        self.col += 1;
                        self.consume();

                    } else if cur_ == '{' {
                        let tok = Token {
                            line: self.line,
                            col: self.col,
                            type_: String::from("L-BRACKET"),
                            value: String::from("{")
                        };

                        self.tokens.push(tok);
                        self.col += 1;
                        self.consume();

                    } else if cur_ == '}' {
                        let tok = Token {
                            line: self.line,
                            col: self.col,
                            type_: String::from("R-BRACKET"),
                            value: String::from("}")
                        };

                        self.tokens.push(tok);
                        self.col += 1;
                        self.consume();

                    } else if cur_ == ':' {
                        let tok = Token {
                            line: self.line,
                            col: self.col,
                            type_: String::from("COLON"),
                            value: String::from(":")
                        };

                        self.tokens.push(tok);
                        self.col += 1;
                        self.consume();

                    } else if cur_.is_alphabetic() || cur_ == '_' {
                        loop {
                            match self.peek(0) {
                                Some(cur) => {
                                    if cur.is_alphanumeric() || cur == '_' {
                                        buf.push(cur);
                                        self.consume();

                                    } else { break; }
                                }

                                None => { break; }
                            }
                        }

                        let token_name: String = buf.iter().collect();
                        self.col += token_name.len();

                        let tok: Token;

                        if token_name == "func" {
                            tok = Token {
                                line: self.line,
                                col: self.col,
                                type_: String::from("FUNC"),
                                value: String::from(token_name)
                            };

                            self.tokens.push(tok);
                        } else if token_name == "return" {
                            tok = Token {
                                line: self.line,
                                col: self.col,
                                type_: String::from("RETURN"),
                                value: String::from(token_name)
                            };

                            self.tokens.push(tok);

                        } else if token_name == "void" {
                            tok = Token {
                                line: self.line,
                                col: self.col,
                                type_: String::from("TYPE"),
                                value: String::from(token_name)
                            };

                            self.tokens.push(tok);

                        } else {
                            tok = Token {
                                line: self.line,
                                col: self.col,
                                type_: String::from("IDENTIFIER"),
                                value: String::from(token_name)
                            };

                            self.tokens.push(tok);
                        }

                    } else if cur_.is_numeric() {
                        // Placeholder
                        self.consume();

                    } else {
                        // Placeholder
                        self.consume();
                    }
                }

                None => {break;}
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

    fn consume(&mut self) {
        self.index += 1;
    }

}