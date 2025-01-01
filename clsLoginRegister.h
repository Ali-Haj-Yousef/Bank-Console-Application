#ifndef CLSLOGINREGISTER_H
#define CLSLOGINREGISTER_H
#include "clsScreen.h"
#include <iostream>
#include <vector>
#include "clsString.h"
using namespace std;

class clsLoginRegister : protected clsScreen
{
private:

    static void _printLoginRegisterRecord(clsUser::stLoginRegisterRecord login){
        cout << "|" << left << setw(35) << login.dateTime <<  "| " << left << setw(16) << login.username << "| " << left << setw(16) << login.password << "| " << left << setw(8) << login.permissions << "\n";
    }

public:

    static void showLoginRegisterScreen(){
        system("cls");
        vector <clsUser::stLoginRegisterRecord> loginsRecords = clsUser::getLoginRegisterList();
        _drawScreenHeader(clsUtil::tabs(7) + "Login Register List Screen", clsUtil::tabs(7) + " (" + to_string(loginsRecords.size()) + ") Record (s)");
        cout << "\n________________________________________________________________________________________\n\n";
        cout << "|" << left << setw(35) << "Date/Time" <<  "| " << left << setw(16) << "Username" << "| " << left << setw(16) << "Password" << "| " << left << setw(8) << "Permissions";
        cout << "\n________________________________________________________________________________________\n\n";
        for(clsUser::stLoginRegisterRecord loginRecord : loginsRecords)
            _printLoginRegisterRecord(loginRecord);
        cout << "\n________________________________________________________________________________________\n\n";
    }
};

#endif // CLSLOGINREGISTER_H
