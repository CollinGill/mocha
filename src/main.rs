mod scanner;
mod token;

use std::env;
use std::fs;
use crate::scanner::Scanner;

fn main() {
    let args: Vec<String> = env::args().collect();
    let usage= "mocha path/to/file.moc";

    if args.len() < 2 {
        eprintln!("Error: Incorrect usage, correct usage is...");
        println!("{}", usage);
    }

    let file_name: &String = &args[1];
    let contents: Vec<char> = fs::read_to_string(file_name)
                                    .expect("Failed to read input")
                                    .chars()
                                    .collect();

    let mut scanner_ = Scanner {
        src_code: contents,
        tokens: Vec::new(),
        index: 0
    };

    scanner_.tokenize();
}
