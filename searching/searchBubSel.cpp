#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>

using namespace std;

const int MAX = 200;
int newarray[MAX];
void dataGet(int newarray[]);
void dataPrint(int newarray[]);
void bubbleSort(int list[], int length);
ifstream inFile;
ofstream outFileBub;

int main ()
   {
      inFile.open("ints.txt");
      outFileBub.open("bubbleOut.txt");
      dataGet(newarray);      
      inFile.close();

      bubbleSort(newarray, 200);
      
      outFileBub.close();
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




void bubbleSort(int list[], int length)
{
   int comparisons=0;
   int dataMoves=0;
    for (int iteration = 1; iteration < length; iteration++)
    {
        for (int index = 0; index < length - iteration;
                            index++)
        {
            comparisons++;
            if (list[index] > list[index + 1])
            {
                dataMoves+=3;
                int temp = list[index];
                list[index] = list[index + 1];
                list[index + 1] = temp;
            }
        }
    }

    cout<<"comparisons: "<<comparisons<<" data moves: "<<dataMoves<<endl;
    outFileBub<<"comparisons: "<<comparisons<<" data moves: "<<dataMoves<<endl;
} //end bubbleSort