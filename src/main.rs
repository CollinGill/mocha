mod scanner;
mod token;

use std::env;
use std::fs;

fn main() {
    let args: Vec<String> = env::args().collect();
    let usage= "mocha path/to/file.moc";

    if args.len() < 2 {
        eprintln!("Error: Incorrect usage, correct usage is...");
        println!("{}", usage);
    }

    let file_name = &args[1];
    let contents = fs::read_to_string(file_name)
                                 .expect("Should have been able to read the file");

}
