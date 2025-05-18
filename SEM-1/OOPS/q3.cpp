#include <iostream>
using namespace std;

class BankAccount
{
    int accountNumber;
    double balance;

public:
    // No-argument constructor (opening a new account with default balance)
    BankAccount()
    {
        accountNumber = 0;
        balance = 0.0;
        cout << "\nNo-argument constructor called. New account created with 0 balance." << endl;
    }

    // One-argument constructor (opening a new account with 0 balance)
    BankAccount(int accNum)
    {
        accountNumber = accNum;
        balance = 100.0; // Minimum Balance
        cout << "One-argument constructor called. New account created with minimum balance." << endl;
    }

    // Two-argument constructor (opening a new account with a specific account number and custom initial deposit)
    BankAccount(int accNum, double initialBalance)
    {
        accountNumber = accNum;
        balance = initialBalance;
        cout << "Two-argument constructor called. New account created with user input balance." << endl;
    }

    // Copy constructor (creating a copy of an existing account)
    BankAccount(BankAccount &acc)
    {
        accountNumber = acc.accountNumber;
        balance = acc.balance;
        cout << "Copy constructor called. Copy created of account number: "<< acc.accountNumber << endl;
    }

    void display()
    {
        cout << "\t[Account Number = " << accountNumber << ", Balance = $" << balance << "]" << endl
             << endl;
    }
};

int main()
{
    // No-argument constructor (New account with default values)
    BankAccount account1;
    account1.display();

    // One-argument constructor (New account with account number and default balance)
    BankAccount account2(12345);
    account2.display();

    // Two-argument constructor (New account with account number and custom initial balance)
    BankAccount account3(67890, 500.0);
    account3.display();

    // Copy constructor (Creating a copy of an existing account)
    BankAccount account4 = account3;
    account4.display();

    return 0;
}
