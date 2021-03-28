//
//  Date.cpp
//  hw10
//
//  Created by Youssef Donia on 4/18/20.
//  Copyright © 2020 Youssef Donia. All rights reserved.
//
#define EXTRA_CREDIT
#include "Date.h"

void Date::set(int month_, int day_, int year_, int hour_)
{
    month = month_;
    day = day_;
    year = year_;
    hour = hour_;
}
void Date::print() const
{
    //change the month from int to string and name it depending on its number
    string month_;
    
    if (month == 1)
        month_ = "January";
    if (month == 2)
        month_ = "February";
    if (month == 3)
        month_ = "March";
    if (month == 4)
        month_ = "April";
    if (month == 5)
        month_ = "May";
    if (month == 6)
        month_ = "June";
    if (month == 7)
        month_ = "July";
    if (month == 8)
        month_ = "August";
    if (month == 9)
        month_ = "September";
    if (month == 10)
        month_ = "October";
    if (month == 11)
        month_ = "November";
    if (month == 12)
        month_ = "December";
    
    cout << month_ << " " << day << ", " << year << ", " << hour << ":00";
}

int Date::getMonth() const
{
    return month;
}

int Date::getDay() const
{
    return day;
}

int Date::getYear() const
{
    return year;
}

int Date::getHour() const
{
    return hour;
}
