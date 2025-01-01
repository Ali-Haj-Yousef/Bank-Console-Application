#ifndef CLSDELETEUSERSCREEN_H
#define CLSDELETEUSERSCREEN_H
#include <iostream>
using namespace std;
#include "clsScreen.h"
#include "clsUser.h"
#include "clsPerson.h"
#include "clsInputValidate.h"
#include "global.h"
#include <vector>
#include <string>

class clsDeleteUserScreen : protected clsScreen
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

    static void showDeleteUserScreen(){
        _drawScreenHeader(clsUtil::tabs(7) + "Delete User Screen");
        string username = clsInputValidate::readString("\n\nEnter a username to be deleted. ");
        while(!clsUser::isUserExist(username))
            username = clsInputValidate::readString("\nThis username doesn't exist, enter another one. ");
        if(username == currentUser->getUserName()){
            cout << "\nError! You can't delete your username.";
            return;
        }
        clsUser * user = clsUser::Find(username);
        _printUser(*user);
        char decision;
        cout << "\nAre you sure you want to delete this user? y/n? ";
        cin >> decision;
        if(decision == 'y' || decision == 'Y'){
            user->Delete();
            cout << "\nThe user is deleted successfully.";
        }
        delete user;
    }

};

#endif // CLSDELETEUSERSCREEN_H
