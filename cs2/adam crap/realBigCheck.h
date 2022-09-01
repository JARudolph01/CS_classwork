#include <iostream>

using namespace std;

class Account{
    public:
        float balance;
        float lastCheck;
        float lastDeposit;

        void setBalance(float amount);
        
        bool writeCheck(float amount);

        void deposit(float amount);
        
        float getBalance();

        float getLastCheck();

        float getLastDeposit();

        int menu();
};