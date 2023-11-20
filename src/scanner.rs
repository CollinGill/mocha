use std::str::Chars;
use crate::token::Token;

pub struct Scanner {
    pub src_code: String,
    pub tokens : Vec<Token>,
    pub index : usize,
}