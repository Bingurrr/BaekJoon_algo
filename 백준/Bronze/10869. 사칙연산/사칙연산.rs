use std::io;

fn main() {
    let mut num = String::new();

    io::stdin().read_line(&mut num).unwrap();

    let numbers: Vec<&str> = num.split_whitespace().collect();

    let a: i32 = numbers[0].parse::<i32>().unwrap();
    let b: i32 = numbers[1].parse::<i32>().unwrap();
    println!("{}", a + b);
    println!("{}", a - b);
    println!("{}", a * b);
    println!("{}", a / b);
    println!("{}", a % b);
}