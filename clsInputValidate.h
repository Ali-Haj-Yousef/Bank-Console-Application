#ifndef CLSINPUTVALIDATE_H_INCLUDED
#define CLSINPUTVALIDATE_H_INCLUDED
#include <iostream>
#include <limits>
#pragma once
#include "clsDate.h"
using namespace std;
class clsInputValidate{
public:
    static bool isNumberBetween(short nb, short from, short to){
        return nb >= from && nb <= to;
    }

    static bool isNumberBetween(int nb, int from, int to){
        return nb >= from && nb <= to;
    }

    static bool isNumberBetween(double nb, double from, double to){
        return nb >= from && nb <= to;
    }

    static bool isNumberBetween(float nb, float from, float to){
        return nb >= from && nb <= to;
    }

    static bool isDateBetween(clsDate date, clsDate startDate, clsDate endDate){
        if(startDate.isAfterDate(endDate))
            swap(startDate, endDate);
        return date.isAfterDate(startDate) && endDate.isAfterDate(date);
    }

    static int readIntNumber(string message){
        cout << message;
        int nb;
        while(!(cin >> nb)){
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << message;
        }
        return nb;
    }

    static int readShortNumber(string message = ""){
        if(message != "")
            cout << message;
        short nb;
        while(!(cin >> nb)){
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << message;
        }
        return nb;
    }

    static float readFloatNumber(string message){
        cout << message;
        float nb;
        while(!(cin >> nb)){
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << message;
        }
        return nb;
    }

    static double readDblNumber(string message){
        cout << message;
        double nb;
        while(!(cin >> nb)){
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << message;
        }
        return nb;
    }

    static int readIntNumberBetween(int from, int to, string message){
        int nb;
        nb = readIntNumber(message);
        while(!isNumberBetween(nb, from, to)){
            cout << "Invalid number, enter again:\n";
            nb = readIntNumber(message);
        }
        return nb;
    }

    static double readDblNumberBetween(double from, double to, string message){
        double nb;
        nb = readDblNumber(message);
        while(!isNumberBetween(nb, from, to)){
            cout << "Invalid number, enter again:\n";
            nb = readDblNumber(message);
        }
        return nb;
    }

    static double readShortNumberBetween(short from, short to, string message = ""){
        short nb;
        nb = readShortNumber(message);
        while(!isNumberBetween(nb, from, to)){
            cout << "Invalid number, enter again:\n";
            nb = readShortNumber(message);
        }
        return nb;
    }

    static bool isValidDate(clsDate date){
        return date.isValid();
    }

    static string readString(string message = ""){
        if(message != "")
            cout << message;
        string str;
        getline(cin >> ws, str);
        return str;
    }
};

#endif // CLSINPUTVALIDATE_H_INCLUDED
