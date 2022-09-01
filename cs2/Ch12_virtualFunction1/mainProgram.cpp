   
#include <iostream>
#include "petType.h"
#include "dogType.h"

using namespace std;
 
void callPrint(petType& p);

int main()
{
    cout << "create a pet named Lucky and a dog called Tommy that is a German Shepard " << endl;
    petType pet("Lucky");                     //Line 1
    dogType dog("Tommy", "German Shepherd");  //Line 2
 
    cout << "call pet.print " << endl;
    pet.print();                              //Line 3
    cout << endl;                             //Line 4
    cout << "call dog.print " << endl;
    dog.print();                              //Line 5

    cout << "*** Calling the function callPrint first passing pet second passing dog  ***"
         << endl;                             //Line 6
    callPrint(pet);                           //Line 7
    cout << endl;                             //Line 8
    callPrint(dog);                           //Line 9
    cout << endl;                             //Line 10

    return 0;
}


void callPrint(petType& p)
{	
    p.print();
}
