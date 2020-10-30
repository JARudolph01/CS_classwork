#include <iostream>
#include <fstream>

using namespace std;

const int MAX = 200;
int newarray[MAX];
int otherNewArray[MAX];
void dataGet(int newarray[]);
void dataPrint(int newarray[]);
void bubbleSort(int list[], int length);
void selectionSort(int list[], int length);
ifstream inFile;
ofstream outFileBub;
ofstream outFileSel;

int main ()
   {
      inFile.open("ints.txt");
      outFileBub.open("bubbleOut.txt");
      outFileSel.open("selectionOut.txt");
      dataGet(newarray);      
      dataGet(otherNewArray);      
      inFile.close();

      bubbleSort(newarray, 200);
      selectionSort(otherNewArray, 200);
      
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
}

int selectionComparisions=0;
int selectionMoves=0;

int minLocation(int list[], int first, int last);
void swap(int list[], int first, int second);
void selectionSort(int list[], int length)
{
   selectionComparisions=0;
   selectionMoves=0;
    int loc, minIndex;

    for (loc = 0; loc < length; loc++)
    {
        minIndex = minLocation(list, loc, length - 1);
        swap(list, loc, minIndex);
    }
    cout<<"comparisons: "<<selectionComparisions<<" data moves: "<<selectionMoves<<endl;
    outFileSel<<"comparisons: "<<selectionComparisions<<" data moves: "<<selectionMoves<<endl;
}


void swap(int list[], int first, int second)
{
    int temp;

    temp = list[first];
    list[first] = list[second];
    list[second] = temp;
    selectionMoves+=3;
}
int minLocation(int list[], int first, int last)
{
    int loc, minIndex;

    minIndex = first;

    for (loc = first + 1; loc <= last; loc++){
       selectionComparisions++;
    
        if (list[loc] < list[minIndex])
            minIndex = loc;
    }

    return minIndex;
}