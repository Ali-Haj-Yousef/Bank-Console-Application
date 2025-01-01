#ifndef CLSLOGINSCREEN_H
#define CLSLOGINSCREEN_H
#include <iostream>
using namespace std;
#include "clsScreen.h"
#include "clsUtil.h"
#include "clsString.h"
#include "clsInputValidate.h"
#include "clsUser.h"
#include "global.h"
#include "clsMainScreen.h"
#include "clsDate.h"

class clsLoginScreen : protected clsScreen
{

public:

    static void showLoginScreen(){
        string userName = "", password = "";
        short trial = 0;
        do{
            _drawScreenHeader(clsUtil::tabs(7) + "Login Screen");
            if(userName != "" && password != ""){
                cout << "\nInvalid Username/Password.\n";
                cout << "You still have " << 3 - trial << " trials to login.\n";
                if(trial == 3){
                    cout << "\nYou are locked after 3 failed trials.\n";
                    return;
                }
            }
            trial++;
            userName = clsInputValidate::readString("\nEnter Username. ");
            password = clsInputValidate::readString("\nEnter Password. ");
        }while(!clsUser::isUserExist(userName, password));
        currentUser = clsUser::Find(userName, password);
        currentUser->registerLogIn();
        clsMainScreen::showMainMenu();
        showLoginScreen();
    }

};

#endif // CLSLOGINSCREEN_H
