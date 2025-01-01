#ifndef CLSFINDUSERSCREEN_H
#define CLSFINDUSERSCREEN_H
#include <iostream>
using namespace std;
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsUtil.h"
#include "clsUser.h"

class clsFindUserScreen : protected clsScreen
{
private:

    static void _printUser(clsUser user){
        cout << "\nUser Card :";
        cout << "\n_____________________________________________\n\n";
        cout << "First Name  : " << user.getFirstName() << endl;
        cout << "Last Name   : " << user.getLastName() << endl;
        cout << "Email       : " << user.getEmail() << endl;
        cout << "Phone       : " << user.getPhone() << endl;
        cout << "Username    : " << user.getUserName() << endl;
        cout << "Password    : " << user.getPassword() << endl;
        cout << "Permissions : " << user.getPermissions() << endl;
        cout << "_____________________________________________\n";
    }

public:

    static void showFindUserScreen(){
        _drawScreenHeader(clsUtil::tabs(7) + "Find User Screen");
        string username = clsInputValidate::readString("\n\nEnter a username. ");
        clsUser * user = clsUser::Find(username);
        if(user == NULL)
            cout << "\nUser doesn't exist! :-(";
        else{
            cout << "\nUser exists :-)\n";
            _printUser(*user);
        }
        delete user;
    }
};

#endif // CLSFINDUSERSCREEN_H
