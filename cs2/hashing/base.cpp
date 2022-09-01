// not blank
#include <iostream> 
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

ifstream inData;
//array of strings - chose a value approx 2 times the number of lines you will hash, but that is a prime number - in this case use 13
int main() 
{    
    inData.open("line.txt");

    string line;
    getline(inData,line);
    cout << line << endl;
	
    //you will need to get the length of your string
    //using the length as your lcv get the int value of each char and add it to a total which you will use in the part of the hash function that mods that sum by 13
    //once you have the hash value, use that as the index value of an array of strings and store you string in the array
    
    return 0;
}	// terminates the block of code