pub struct Token {
    pub line: u64,
    pub col: u64,
    pub type_: String,
    pub value: String
}

pub fn print_token(token: Token) {
    print!("<{}, {}>", token.type_, token.value);
}