#ifndef  MATH_H
#define MATH_H


int add(int a, int b){
    return a+b;
}

int multiply(int a, int b){
    return a*b;
}

int StaticTest = 5;

class Pickaxe{
    private:
        int durability;
        int speed;
    public:
        Pickaxe(int d, int s){
            durability=d;
            speed=s;
        }
        int mine(){
            this->durability--;
            return durability;
        }

        void repair(int);//prototype method
};

void Pickaxe::repair(int i){
    durability+=i;
}

//template
template <typename T>
//find length of array
int len(T const & arr){
    return *(&arr + 1) - arr;
}

#endif

//useful source
//https://www.youtube.com/watch?v=vScV12EdgB4