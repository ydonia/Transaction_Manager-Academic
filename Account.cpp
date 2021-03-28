//
//  Account.cpp
//  hw10
//
//  Created by Youssef Donia on 4/18/20.
//  Copyright © 2020 Youssef Donia. All rights reserved.
//

#define EXTRA_CREDIT
#include "Account.h"
#include <iomanip>
using namespace std;

int Account::numberAccounts = 0;
Account::Account(string ownerName_, double balance_, Date date_)
{
    ownerName = ownerName_;
    balance = balance_;

    accountNumber = (numberAccounts + 1000);
    numberAccounts++;
    transactionHistory = nullptr;
    numberTransactions = 0;
    Transaction t;
    t.date = date_;
    t.amount = balance_;
    t.transactionType = 0;
    recordTransaction(t);
}

bool Account::withdraw(double amount, Date date_)
{
    Transaction t;
    //check to make sure amount is not negative
    if (amount < 0)
    {
        cout << "Amount cannot be negative, withdraw not executed" << endl << endl;
        return false;
    }
    //check to see if there is sufficient balance in the account
    if (balance < amount)
    {
        cout << "Insufficient balance, withdrawal not executed" << endl << endl;
        return false;
    } else
    {
        balance = balance - amount;
        t.amount = amount;
        t.date = date_;
        t.transactionType = 2;
        recordTransaction(t);
        return true;
    }
}

bool Account::deposit(double amount, Date date_)
{
    Transaction t;
    if (amount < 0)
    {
        cout << "Amount cannot be negative, deposit not executed" << endl << endl;
        return false;
    } else
    {
        balance = balance + amount;
        t.amount = amount;
        t.date = date_;
        t.transactionType = 1;
        recordTransaction(t);
        return true;
    }
    
}

int Account::getAccountNumber() const
{
    return accountNumber;
}

double Account::getBalance() const
{
    return balance;
}

int Account::getNumberAccounts()
{
    return numberAccounts;
}

void Account::print() const
{
    cout << "#: " << accountNumber << ", Name: " << ownerName << ", Balance: " << fixed << setprecision(2) << balance << " Galactic units" << endl;
}

/* This function takes as argument a Transaction structure variable and
adds it to the transaction history. The transaction history
is implemented as an array of Transactions. A new array is dynamically allocated,
of size equal to (size of old array) + 1, to hold the added transaction.
The values of the old array are copied into the new array,
and the transaction to be added is copied into the last element of the new array.
The old array is released through delete. The address returned from dynamic array allocation is assigned  to transactionHistory.
*/
void Account::recordTransaction(Transaction t)
{
    Transaction * tempTransac;
    
    if (numberTransactions < 1)
    {
        transactionHistory = new Transaction[numberTransactions + 1];
        transactionHistory[0] = t;
    }else
    {
        //dynamically create new array
        tempTransac = new Transaction[numberTransactions + 1];
        
        //copy old array into new array
        for (int i = 0; i < numberTransactions; i++)
        {
            tempTransac[i] = transactionHistory[i];
        }
        //delete the transactionHistory array
        delete [] transactionHistory;
        
        //add the new transaction to the temp array
        int lastElement = numberTransactions;
        tempTransac[lastElement] = t;
        
        //get transactionHistory to point to the temporary array
        transactionHistory = tempTransac;
    }
    numberTransactions++;
}

void Account::printTransactions() const
{
    cout << "Transaction history:" << endl;
    cout << "-------------------" << endl;
    
    string type;
    double printBalance = 0;
    for (int i = 0; i < numberTransactions; i++)
    {
        if (transactionHistory[i].transactionType == 0)
            type = "Creation";
        else if (transactionHistory[i].transactionType == 1)
            type = "Deposit";
        else if (transactionHistory[i].transactionType == 2)
            type = "Withdrawal";
        
        if (transactionHistory[i].transactionType == 0)
            printBalance = transactionHistory[i].amount;
        else if (transactionHistory[i].transactionType == 1)
            printBalance = printBalance + transactionHistory[i].amount;
        else if (transactionHistory[i].transactionType == 2)
            printBalance = printBalance - transactionHistory[i].amount;
        
        cout << "Date: "; transactionHistory[i].date.print();
        cout << ", " << "Amount: " << transactionHistory[i].amount
        << ", " << "type: " << type << ", " << "New balance: " << fixed << setprecision(2) << printBalance << endl;
    }
}

 
