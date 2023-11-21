use crate::token::Token;

pub struct Scanner {
    pub src_code: Vec<char>,
    pub tokens : Vec<Token>,
    pub index : usize,
}

impl Scanner {
    pub fn tokenize(&mut self) {
        let mut buf: Vec<char> = Vec::new();

        loop {
            match self.peek(0) {
                Some(cur_) => {
                    if cur_.is_whitespace() {
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

                        let token_name: String = buf.into_iter().collect();
                        println!("{}", token_name);
                        break;

                    } else if cur_.is_numeric() {

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