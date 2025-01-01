#ifndef CLSUSERLISTSCREEN_H
#define CLSUSERLISTSCREEN_H
#include <iostream>
using namespace std;
#include "clsScreen.h"
#include "clsUser.h"

class clsUserListScreen : protected clsScreen
{
private:

    static void _printUserRecordLine(clsUser user){
        cout << "| " << left << setw(16) << user.getUserName() << "| " << left << setw(16) << user.getPassword() << "| " << left << setw(8) << user.getPermissions() << "\n";
    }

public:

    static void showUserListScreen(){
        system("cls");
        vector <clsUser> users = clsUser::loadUsersFromFile();
        _drawScreenHeader(clsUtil::tabs(7) + "User List Screen", clsUtil::tabs(7) + " (" + to_string(users.size()) + ") User (s)");
        cout << "\n____________________________________________________________\n\n";
        cout << "| " << left << setw(16) << "Username" << "| " << left << setw(16) << "Password" << "| " << left << setw(8) << "Permissions";
        cout << "\n____________________________________________________________\n\n";
        for(clsUser& user : users)
            _printUserRecordLine(user);
    }
};

#endif // CLSUSERLISTSCREEN_H
