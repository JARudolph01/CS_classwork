#include <iostream>
#include "realBigCheck.h"



void Account::setBalance(float amount)
{
    balance = amount;
}

bool Account::writeCheck(float amount)
{
    if (amount > balance)
            return false;
    balance -= amount;
    lastCheck = amount;
    return true;
    }

void Account::deposit(float amount)
{
    balance += amount;
    lastDeposit = amount;
}

float Account::getBalance()
{
    return balance;
}

float Account::getLastCheck()
{
    return lastCheck;
}

float Account::getLastDeposit()
{
    return lastDeposit;
}


int Account::menu(){
    int choice;
    
    cout << endl;
    cout << "1   Write a check" << endl;
    cout << "2   Make a deposit" << endl;
    cout << "3   Get the balance" << endl;
    cout << "4   Quit" << endl;
    cout << "Enter a number between 1 and 4: ";
    cin >> choice;
    return choice;
}