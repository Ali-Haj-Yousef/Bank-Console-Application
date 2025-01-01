#ifndef CLSUPDATEUSERSCREEN_H
#define CLSUPDATEUSERSCREEN_H
#include <iostream>
using namespace std;
#include "clsScreen.h"

class clsUpdateUserScreen : protected clsScreen
{
private:

    static short _readUserPermissions(){
        char fullAccess;
        cout << endl;
        cout << "Do you want to give full access? y/n? ";
        cin >> fullAccess;
        if(fullAccess == 'y')
            return -1;
        else{
            short permissions = 0;
            char option;
            cout << "\nShow Client List? y/n? ";
            cin >> option;
            if(option == 'y')
                permissions += clsUser::pShowClients;
            cout << endl;
            cout << "Add Client? y/n? ";
            cin >> option;
            if(option == 'y')
                permissions += clsUser::pAddClient;
            cout << endl;
            cout << "Delete Client? y/n? ";
            cin >> option;
            if(option == 'y')
                permissions += clsUser::pDeleteClient;
            cout << endl;
            cout << "Update Client? y/n? ";
            cin >> option;
            if(option == 'y')
                permissions += clsUser::pUpdateClient;
            cout << endl;
            cout << "Find Client? y/n? ";
            cin >> option;
            if(option == 'y')
                permissions += clsUser::pFindClient;
            cout << endl;
            cout << "Transactions? y/n? ";
            cin >> option;
            if(option == 'y')
                permissions += clsUser::pTransactions;
            cout << endl;
            cout << "Manage Users? y/n? ";
            cin >> option;
            if(option == 'y')
                permissions += clsUser::pManageUsers;
            cout << endl;
            cout << "Show Logins List? y/n? ";
            cin >> option;
            if(option == 'y')
                permissions += clsUser::pShowLogins;
            cout << endl;
            return permissions;
        }
    }

    static void _readUserInfo(clsUser& user){
        user.setFirstName(clsInputValidate::readString("\n\nEnter first name. "));
        user.setLastName(clsInputValidate::readString("\nEnter last name. "));
        user.setEmail(clsInputValidate::readString("\nEnter email. "));
        user.setPhone(clsInputValidate::readString("\nEnter phone. "));
        user.setPassword(clsInputValidate::readString("\nEnter password. "));
        user.setPermissions(_readUserPermissions());
    }

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

    static void showUpdateUserScreen(){
        _drawScreenHeader(clsUtil::tabs(7) + "Update User Screen");
        _drawScreenHeader(clsUtil::tabs(7) + "Find User Screen");
        string username = clsInputValidate::readString("\n\nEnter a username. ");
        while(!clsUser::isUserExist(username))
            username = clsInputValidate::readString("\nThis username doesn't exist, enter another one. ");
        clsUser * user = clsUser::Find(username);
        _printUser(*user);
        char decision;
        cout << "\nAre you sure you want to update this user? y/n? ";
        cin >> decision;
        if(decision == 'y' || decision == 'Y'){
            _readUserInfo(*user);
            user->Update();
            _printUser(*user);
        }
    }

};

#endif // CLSUPDATEUSERSCREEN_H
