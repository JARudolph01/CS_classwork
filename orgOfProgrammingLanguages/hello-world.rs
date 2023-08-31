fn main() {
    println!("Hello World!");

    println!("enter your name: ");
    
    let name = user_input();
    println!("{}",name);

    println!("{}",add(1,-2));

    
}

fn add(a: i64, b: i64) -> i64 {
    a + b
}


fn user_input () -> String {
    use std::io;
    let mut user_in = String::new();
    io::stdin().read_line(&mut user_in).expect("failed to readline");
    user_in
}

// fn fizz_buzz() {
//     for x in 1..=100 {
//         if x % 15 == 0 {
//             println!("FizzBuzz")
//         } else if x % 3 == 0 {
//             println!("Fizz")
//         } else if x % 5 == 0 {
//             println!("Buzz")
//         } else {
//             println!("{}", x)
//         }
//     }
// }