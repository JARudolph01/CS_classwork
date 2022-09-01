#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>

using namespace std;

const int MAX = 200;
int newarray[MAX];
void dataGet(int newarray[]);
void dataPrint(int newarray[]);
//int seqSearch(const int list[], int length, const int& item);
int binarySearch(const int list[], int length, const int& item);

ifstream inFile;
ofstream outFile;

int main ()
   {
      inFile.open("intsSort.txt");
      outFile.open("comps.txt");
      dataGet(newarray);      
      inFile.close();

      int searchValue;
      while(searchValue!=-9){
         cout<<"Enter a value to search: ";
         cin>>searchValue;
         binarySearch(newarray, MAX, searchValue);
      }
      outFile.close();
      return 0;
   }
 
 void dataGet(int newarray[])
   {
   for (int i=0; i<MAX; i++)
         {
         inFile >> newarray[i];
         }
    }
    
 void dataPrint(int newarray[])

   {
      for (int i=0; i<MAX; i++)
         {
            cout << newarray[i] << "     " ;
            if((i+1)%5 == 0)
            {
               cout << endl;
            }

         }
    }




//function definition to search and count comparisons goes here

int seqSearch(const int list[], int length, const int& item)
{
   int loc; 
   bool found = false;
   int comparisons=0;

    loc = 0;

    while (loc < length && !found){
      if (list[loc] == item){
         found = true;
      }
      else{
         loc++;
      }
      comparisons++;
   }
   if (found){
      cout<<"found "<<item<<" at index: "<<loc<<". Comparrisons: "<<comparisons<<".\n";
      //outFile<<"found "<<item<<" at index: "<<loc<<". Comparrisons: "<<comparisons<<".\n";
      return loc;
   }
   else{
      cout<<"item: "<<item<<" not found\n";
      //outFile<<"item: "<<item<<" not found\n";
      return -1;
   }
}



int binarySearch(const int list[], int length, const int& item)
{
    int comparisons=0;
    int first = 0;
    int last = length - 1;
    int mid;

    bool found = false;

    while (first <= last && !found)
    {
        mid = (first + last) / 2;

        if (list[mid] == item)
            found = true;
        else if (list[mid] > item)
            last = mid - 1;
        else
            first = mid + 1;
         comparisons++;
    }

    if (found){
       cout<<"found "<<item<<" at index: "<<mid<<". Comparrisons: "<<comparisons<<".\n";
       outFile<<"found "<<item<<" at index: "<<mid<<". Comparrisons: "<<comparisons<<".\n";
       return mid;
    }
        
    else{
       cout<<"item: "<<item<<" not found\n";
       outFile<<"item: "<<item<<" not found\n";
       return -1;
    }
        
} //end binarySearch