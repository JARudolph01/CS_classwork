

fn main() {

    /*
    Q1:
    Write a program using Rust programming language that defines two different integer variables, assigns values, and prints them. Also, update the second one to be equal to double the value of the first variable only if the second variable is greater than the first variable; otherwise, add 5 to the second variable, then print the updated value for the second variable.
    */
    println!("Q1:");
    let a = 1;
    let mut b = 3;
    println!("a = {}",a);
    println!("b = {}",b);
    if b > a {
        b=2*a;
    } else {
        b=b+5;
    }
    println!("b = {}",b);

    println!("");

    /*
    Q2:
    Write a function that accepts three integer numbers as input parameters and returns the average number for them. 
    */
    println!("Q2:");
    let x = 1;
    let y = 2;
    let z = 3;
    let avg = (x+y+z)/3;
    println!("avg = {}",avg);

    println!("");

    /*
    Q3:
    Define an array of integers in the range from 1 to 5, then:
        Print the array.
        Print the length of the array.
        Print the even numbers in the array using a for loop.
    */
    println!("Q3:");
    let arr = [1,2,3,4,5];

    //a
    println!("arr = {:?}",arr); 

    //b
    println!("arr length = {}",arr.len());

    //c
    print!("even numbers in the array: ");
    for i in 0..arr.len() {
        if arr[i]%2==0 {
            print!("{} ",arr[i]);
        }
    }
    println!("");
}


