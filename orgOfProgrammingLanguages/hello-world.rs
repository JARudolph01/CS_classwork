fn main() {
    println!("");

    println!("enter your name: ");
    
    let name = user_input();
    println!("{}",name);

    println!("{}",add(1,-2));

    
}

fn array_test(){
    let mut array: [i64; 3] = [0; 3];
    println(array[2]);
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
