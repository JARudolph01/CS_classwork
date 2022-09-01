#include <iostream>
#include <iomanip>
#include "realBigCheck.h"


using namespace std;


const int CHECK = 1, DEPOSIT = 2, BALANCE = 3, QUIT = 4;

Account ac;

int main()
{
   float balance, amount;
   int choice;
   cout << "Enter the initial balance: $";
   cin >> balance;
   ac.setBalance(balance);
   
   cout << fixed << showpoint << setprecision(2);
   choice = ac.menu();
   while (choice != QUIT)
      {
         if (choice == CHECK)
            {
               cout << "Enter check amount: $";
               cin >> amount;
               if(ac.writeCheck(amount))
                  cout << "Check accepted." << endl;
               else
                  {
                     cout << "not enough money";
                     cout << " oops!" << endl;
                  }
              }
          else if (choice == DEPOSIT)
            {
               cout << "Enter deposit amount: $";
               cin >> amount;
               ac.deposit(amount);
               cout << "Desposit accepted" << endl;
            }
          else 
            {
               amount = ac.getBalance();
               cout << "Your balance is: $" << amount << endl;
            }
          choice = ac.menu();
          }
      
      return 0;
   }
