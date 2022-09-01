#include<iostream>
#include"math.h"//use quotes if it's not an included library
using namespace std;

/*
data type is the domain of all values and the opperations that can be preformed

algorith is solution to a problem and a finite number of steps or time. 
*/

int main(){

    //calling functions from other file
    int sum=add(20,10);
    int product=multiply(20,10);
    cout<<sum<<"\n";
    cout<<product<<"\n";
    cout<<StaticTest<<"\n";

    //object from another class
    Pickaxe diamond(5,6);

    //public methods
    cout<<diamond.mine()<<"\n";
    cout<<diamond.mine()<<"\n";
    cout<<diamond.mine()<<"\n";

    //loop
    for(int i=0; i<10; i++){
        cout<<diamond.mine()<<"\n";
    }

    diamond.repair(10);
    cout<<diamond.mine()<<"\n\n";
    
    //array
    int favorateNumbers[]={1,2,3,4,5};
    

    //foreach
    for(int v:favorateNumbers){
        cout<<v<<" ";
    }
    cout<<"\n";

    //2d array's must be bounded on all dimentions except the first
    int grid[4][4] ={
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16}
    };

    //2d grid iteration
    for(int y=0; y<len(grid); y++){
        for(int x=0; x<len(grid[y]); x++){
            cout<<grid[x][y]<<" ";
        }
        cout<<"\n";
    }

    //length of array
    string favorateWords[]={"pie","pizza","cake","ice cream","eternal pain"};
    int arrSize=len(favorateWords);  //*(&favorateWords + 1) - favorateWords;
    cout<<arrSize<<" len\n";


    //empty array
    string blankArr[5];
    blankArr[1]="pi";
    cout<<blankArr[0]<<"\n";

    cout<<(6/4);//rounds down

    /*
    2d array
    lists
    sorting
    TREES
    
    */
}


