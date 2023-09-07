fn add(x:i32, y:i32)->i32{
    return x+y;
    }
   fn add1(x:i32, y:i32)->i32{
    x+y
   }
   fn main() {
    print!("Hello World");
    println!("Hello World");
    print!("Hello World");
    //the left-hand side of a let statement is a ‘pattern’ let (x,y) = (1,2);
    let mut x = 5;
    let x = 5;
    //x = 10;
    println!("x ={}",x);
    let x: i32 = 8;
    {
    println!("{}", x); // Prints "8".
    let x = 12;
    println!("{}", x); // Prints "12".
    }
    println!("{}", x); // Prints "8".
    let x = 42;
    println!("{}", x); // Prints "42".
    let mut x1: i32 = 1;
    x1 = 7;
    println!("x1 ={}",x1);
    x1= 5;
    println!("x1 ={}",x1);
    let y = 4;
    println!("y ={}",y);
    let y = "I can also be bound to text!"; // `y` is now of a different type.
    println!("y ={}",y);
    println!("{}",add(5,6));
    println!("{}",add1(5,6));
    let avg: f32 ;
    {
    let mut sum: i32 = 0;
    sum = 10 + 30 + 20 ;
    avg = sum as f32/3 as f32;
    println!("avg = {}", avg);
    }
    let tup = (500, 6.4, 1);
    let (x, y, z) = tup;
    println!("The value of y is: {}", y);
    let a = [1, 2, 3, 4, 5];
    let element = a[0];
    println!("array is {:?}",a);
    println!("list lenght={}",a.len());
    println!("The value of element is: {}", element);
    let x = 5;
    if x == 5 {
    println!("x is five!");
    } else if x == 6 {
    println!("x is six!");
    } else {
    println!("x is not five or six :(");
    }
    //let mut x: i32;
    for x in 0..10 {
    print!("{} ", x); // x: i32
    }
    let arr:[i32; 5] = [10,20,30,40,50];
    println!("array is {:?}",arr);
   
    for index in 0..arr.len() {
    println!("index: {}, value: {}", index, arr[index]);
    for (index, value) in (5..10).enumerate() {
    println!("index = {} and value = {}", index, value);
    let mut x = 5; // mut x: i32
    let mut done = false; // mut done: bool
    while !done {
    x += x - 3;
   
    println!("{}", x);
   
    if x % 5 == 0 {
    done = true;
    }
   }
   }
   }
   } 