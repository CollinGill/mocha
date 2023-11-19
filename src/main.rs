use std::env;

fn main() {
    let args: Vec<String> = env::args().collect();
    let usage= "mocha path/to/file.moc";

    if args.len() < 2 {
        eprintln!("Error: Incorrect usage, correct usage is...");
        println!("{}", usage);
    }

    let src_code = &args[1];
}
