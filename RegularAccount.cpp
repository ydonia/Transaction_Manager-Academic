//
//  RegularAccount.cpp
//  hw10
//
//  Created by Youssef Donia on 4/19/20.
//  Copyright © 2020 Youssef Donia. All rights reserved.
//
#define EXTRA_CREDIT
#include "RegularAccount.h"
#include "Account.h"
#include "Date.h"

using namespace std;

RegularAccount::RegularAccount(string ownerName_, double balance_, Date date_): Account(ownerName_, balance_, date_)
{
    
}

void RegularAccount::print() const //override the print function in Account
{
    cout << "Regular account, ";
    this->Account::print();
}
