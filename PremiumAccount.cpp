//
//  PremiumAccount.cpp
//  hw10
//
//  Created by Youssef Donia on 4/19/20.
//  Copyright © 2020 Youssef Donia. All rights reserved.
//
#define EXTRA_CREDIT
#include "PremiumAccount.h"

using namespace std;

const double PremiumAccount::MIN_BALANCE = 1000;

PremiumAccount::PremiumAccount(string ownerName_, double balance_, Date date_) :Account(ownerName_, balance_, date_)
{
}


bool PremiumAccount::withdraw(double amount, Date date)
{
    Transaction t;
    //check to make sure amount is not negative
    if (amount < 0)
    {
        cout << "Amount cannot be negative, withdraw not executed" << endl << endl;
        return false;
    }
    if (balance < amount + MIN_BALANCE)
    {
        cout << "Insufficient balance, withdrawal not executed" << endl << endl;
        return false;
    } else
    {
        balance = balance - amount;
        t.amount = amount;
        t.date = date;
        t.transactionType = 2;
        recordTransaction(t);
        return true;
    }
}

double PremiumAccount::getMinBalance()
{
    return MIN_BALANCE;
}

void PremiumAccount::print() const
{
    cout << "Premium account, ";
    this->Account::print();
}
