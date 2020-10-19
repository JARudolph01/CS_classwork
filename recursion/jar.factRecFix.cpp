#include <iostream>

using namespace std;

long factorial (int n);

int main()
{
  int factNum;
  long answer;
  cout << "enter the number you would like to use to calculate the factorial " << endl;
  cin >>  factNum;
  answer=factorial(factNum);
  cout << "The factorial for " << factNum << " is " << answer << endl;
  return 0;
}

long factorial (int n)
{
  if(n>1){
    return n*factorial(n-1);
  }
  else{
    return 1;
  }
}