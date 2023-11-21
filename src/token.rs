pub struct Token {
    pub line: usize,
    pub col: usize,
    pub type_: String,
    pub value: String
}

impl Token {
    pub fn print_token(&self) {
        print!("<{}, {}>", self.type_, self.value);
    }

}