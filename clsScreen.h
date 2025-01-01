#ifndef CLSSCREEN_H
#define CLSSCREEN_H
#include <iostream>
using namespace std;
#include "clsUtil.h"
#include "global.h"

class clsScreen
{
protected:
    static void _drawScreenHeader(string title, string subtitle = ""){
        system("cls");
        cout << clsUtil::tabs(4) << "____________________________________________________________\n\n";
        cout << title << endl;
        if(subtitle != "")
            cout << subtitle << endl;
        cout << clsUtil::tabs(4) << "____________________________________________________________";
        clsDate currentDate;
        cout << endl << endl << clsUtil::tabs(4) << "User: ";
        if(currentUser != NULL)
            cout << currentUser->getUserName();
        cout << endl << clsUtil::tabs(4) << "Date: " << currentDate.toString() << endl;
    }
};

#endif // CLSSCREEN_H
