#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>


using namespace std;

struct studentType
{
	string name;
	double gpa;
	int sID;
	char grade;
	studentType *point; //pointer to the next node
};

int main()

{

studentType student1;
studentType *studPtr;
studentType *head;
studentType *tail;

studPtr = &student1;
head = &student1;
studPtr->gpa = 3.5;
studPtr->name = "Julie";
studPtr->sID = 5588447;
studPtr->grade = 'A';

cout << "grade " << studPtr->gpa << endl;

//second studentType

studentType student2;
studentType *studPtr2;
student1.point = &student2;

cout << "ptr value for first student record  " << studPtr << endl;
cout << "ptr value for second student record  " << studPtr2 << endl;


studPtr2 = &student2;
cout << "ptr value for second student record  " << studPtr2 << endl;
cout << "the pointer field in the struct for the first student should now point to the second instancee of studentType " << student1.point << endl;
cout << " then assign null or 0 to the pointer in the second student record - so that means it is the tail " << endl;
student2.point = 0;
tail = student2.point;

cout << "the pointer from the second student record is now " << student2.point << endl;
cout << " the value of head " << head << " the value of tail " << tail << endl;

/* bool ptrequal = 0;
int x = 1234;
int y, w, z;
int *p;

p = &x;
int *q;
q = &y;
cout << "this is p " << p << endl;
cout << " this is *p " << *p << endl;
cout << "this is the q value " << q << endl;
cout << "this is the *q value " << *q << endl;
if (p == q)
	cout << "the pointer values are equal " << endl;
//q = q + 1;
p = p -1;
//p = p--;
if (p == q)
	cout << "now they really are " << endl;
//cout << "increm q " << q << endl;
cout << "increm p " << p << endl;

// and now for something completely different
*/

/*
int *list;

list = new int[5];
cout << "pointer to dynamic array " << list << endl;

int i;
for (i = 0; i < 5; i++)
	list[i] = i * i;


for(i = 0; i < 5; i++)
	cout << "items in the list  " << list[i] << "  ptr value " << list << endl;

cout << "pointer to dynamic array value after fill and print " << list << endl;
*/

return 0;
}