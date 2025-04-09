#include <iostream>
#include <string>
#include "invalidMonth.h"
#include "invalidDay.h"
#include "invalidYear.h"
#include "invalidFebDay.h"

using namespace std;

string getMonth(int month);
int getDay(int day, int month, int year);
int getYear(int year);
bool isLeapYear(int year);

int main() {
    int year, month, day;
    string monthName;
    bool valid = false;

    while (true) {
        cout << "Enter your birth year: ";
        cin >> year;

        if (cin.fail()) {
            cout << "Invalid input. Please enter a valid year.\n";
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        try {
            year = getYear(year);
            break;
        } catch (invalidYear& e) {
            cout << e.what() << endl;
        }
    }

    while (true) {
        cout << "Enter your birth month (1-12): ";
        cin >> month;

        if (cin.fail()) {
            cout << "Invalid input. Please enter a valid month.\n";
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        try {
            monthName = getMonth(month);
            break;
        } catch (invalidMonth& e) {
            cout << e.what() << endl;
        }
    }

    while (true) {
        cout << "Enter your birth day: ";
        cin >> day;

        if (cin.fail()) {
            cout << "Invalid input. Please enter a valid day.\n";
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        try {
            day = getDay(day, month, year);
            break;
        } catch (invalidFebDay& e) {
            cout << e.what() << endl;
        } catch (invalidDay& e) {
            cout << e.what() << endl;
        }
    }

    cout << '\n' << monthName << " " << day << ", " << year << endl;
    if (isLeapYear(year)) {
        cout << year << " is a leap year." << endl;
    } else {
        cout << year << " is not a leap year." << endl;
    }

    return 0;
}


string getMonth(int month)
{
    if (month < 1 || month > 12) {
        throw invalidMonth();
    }

    string monthName;

    switch(month)
    {
        case 1: monthName = "January"; break;
        case 2: monthName = "February"; break;
        case 3: monthName = "March"; break;
        case 4: monthName = "April"; break;
        case 5: monthName = "May"; break;
        case 6: monthName = "June"; break;
        case 7: monthName = "July"; break;
        case 8: monthName = "August"; break;
        case 9: monthName = "September"; break;
        case 10: monthName = "October"; break;
        case 11: monthName = "November"; break;
        case 12: monthName = "December"; break;
    }   
    return monthName;
}


int getDay(int day, int month, int year) 
{
    int daysInMonth[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    if (isLeapYear(year)) {
        daysInMonth[2] = 29;
    }

    if (day < 1 || day > daysInMonth[month]) {
        if (month == 2) {
            throw invalidFebDay();  
        } else {
            throw invalidDay(); 
        }
    }

    return day;
}

int getYear(int year)
{
    if (year < 1 || year > 2025)
    {
        throw invalidYear();
    }
    return year;
}

bool isLeapYear(int year) {
    return (year % 4 == 0) && ((year % 100 != 0) || (year % 400 == 0));
}