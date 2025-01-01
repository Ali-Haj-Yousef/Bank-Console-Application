#ifndef CLSMANAGEUSERSSCREEN_H
#define CLSMANAGEUSERSSCREEN_H
#include <iostream>
#include "clsScreen.h"
using namespace std;
#include <iomanip>
#include "clsUtil.h"
#include "clsInputValidate.h"
#include "clsUserListScreen.h"
#include "clsAddNewUserScreen.h"
#include "clsDeleteUserScreen.h"
#include "clsFindUserScreen.h"
#include "clsUpdateUserScreen.h"

class clsManageUsersScreen : protected clsScreen
{
    private:
        enum enManageUsersMenuOption{
            enListUsers = 1,
            enAddNewUser = 2,
            enDeleteUser = 3,
            enUpdateUser = 4,
            enFindUser = 5,
            enMainMenu = 6
        };

        static void _showListUsersScreen(){
            clsUserListScreen::showUserListScreen();
        }

        static void _showAddNewUserScreen(){
            clsAddNewUserScreen::showAddNewUserScreen();
        }

        static void _showDeleteUserScreen(){
            clsDeleteUserScreen::showDeleteUserScreen();
        }

        static void _showFindUserScreen(){
            clsFindUserScreen::showFindUserScreen();
        }

        static void _showUpdateUserScreen(){
            clsUpdateUserScreen::showUpdateUserScreen();
        }

        static void _goBackToManageUsersMenu(){
            cout << endl << "\nPress any key to go back to Main menu ...";
            system("pause>0");
            showManageUsersScreen();
        }

        static short _readManageUsersMenuOption(){
            return clsInputValidate::readShortNumberBetween(1, 6, "\n" + clsUtil::tabs(5) + "Choose what do you want to do. [1 ~ 6]. ");
        }

        static void _performManageUsersMenuOption(enManageUsersMenuOption option){
            switch(option){
            case enManageUsersMenuOption::enListUsers:
                _showListUsersScreen();
                _goBackToManageUsersMenu();
                break;
            case enManageUsersMenuOption::enAddNewUser:
                _showAddNewUserScreen();
                _goBackToManageUsersMenu();
                break;
            case enManageUsersMenuOption::enDeleteUser:
                _showDeleteUserScreen();
                _goBackToManageUsersMenu();
                break;
            case enManageUsersMenuOption::enFindUser:
                _showFindUserScreen();
                _goBackToManageUsersMenu();
                break;
            case enManageUsersMenuOption::enUpdateUser:
                _showUpdateUserScreen();
                _goBackToManageUsersMenu();
                break;
            case enManageUsersMenuOption::enMainMenu:
                break;
            }
        }
public:

    static void showManageUsersScreen(){
        _drawScreenHeader(clsUtil::tabs(7) + "Manage Users Screen");
        cout << endl;
        cout << clsUtil::tabs(5) << "=============================================\n";
        cout << clsUtil::tabs(7) << "Manage Users Menu\n";
        cout << clsUtil::tabs(5) << "=============================================\n";
        cout << clsUtil::tabs(5) << " [1] List Users.\n";
        cout << clsUtil::tabs(5) << " [2] Add New User.\n";
        cout << clsUtil::tabs(5) << " [3] Delete User.\n";
        cout << clsUtil::tabs(5) << " [4] Update User.\n";
        cout << clsUtil::tabs(5) << " [5] Find User.\n";
        cout << clsUtil::tabs(5) << " [6] Main Menu.\n";
        cout << clsUtil::tabs(5) << "=============================================\n";
        _performManageUsersMenuOption((enManageUsersMenuOption)_readManageUsersMenuOption());

    }
};

#endif // CLSMANAGEUSERSSCREEN_H
