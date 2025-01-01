#ifndef CLSMAINSCREEN_H
#define CLSMAINSCREEN_H
#include <iostream>
#include "clsScreen.h"
using namespace std;
#include <iomanip>
#include "clsUtil.h"
#include "clsInputValidate.h"
#include "clsClientListScreen.h"
#include "clsAddNewClientScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsFindClientScreen.h"
#include "clsTransactionsScreen.h"
#include "clsManageUsersScreen.h"
#include "clsAccessDeniedScreen.h"
#include "clsLoginRegister.h"
#include "clsCurrencyExchangeScreen.h"
#include "global.h"
#include "math.h"


class clsMainScreen : protected clsScreen
{
private:
    enum enMainMenuOption{
        enShowClientList = 1,
        enAddNewClient = 2,
        enDeleteClient = 3,
        enUpdateClient = 4,
        enFindClient = 5,
        enTransactions = 6,
        enManageUsers = 7,
        enLoginRegister = 8,
        enCurrencyExchange = 9,
        enLogout = 10
    };

    static bool isAllowedTo(clsUser::enPermissions permission, short permissions){
        return (permissions | permission) == permissions;
    }


    static void _showAllClientsScreen(){
        clsClientListScreen::showClients();
    }

    static void _showAddNewClientScreen(){
        clsAddNewClientScreen::showAddNewClientScreen();
    }

    static void _showDeleteClientScreen(){
        clsDeleteClientScreen::showDeleteClientScreen();
    }

    static void _showUpdateClientScreen(){
        clsUpdateClientScreen::showUpdateClientScreen();
    }

    static void _showFindClientScreen(){
        clsFindClientScreen::showFindClientScreen();
    }

    static void _showTransactionsScreen(){
        clsTransactionsScreen::showTransactionsMenu();
    }

    static void _showManageUsersScreen(){
        clsManageUsersScreen::showManageUsersScreen();
    }

    static void _showLoginRegisterScreen(){
        clsLoginRegister::showLoginRegisterScreen();
    }

    static void _showCurrencyExchangeScreen(){
        clsCurrencyExchangeScreen::showCurrencyExchangeMenuScreen();
    }

    static void _goBackToMainMenu(){
        cout << endl << "\nPress any key to go back to main menu ...";
        system("pause>0");
        showMainMenu();
    }

    static short _readMainMenuOption(){
        return clsInputValidate::readShortNumberBetween(1, 10, "\n" + clsUtil::tabs(5) + "Choose what do you want to do. [1 ~ 10]. ");
    }

    static void _performMainMenuOption(enMainMenuOption option){
        switch(option){
        case enMainMenuOption::enShowClientList:
            isAllowedTo(clsUser::pShowClients, currentUser->getPermissions()) ? _showAllClientsScreen() : clsAccessDeniedScreen::showAccessDeniedScreen();
            _goBackToMainMenu();
            break;
        case enMainMenuOption::enAddNewClient:
            isAllowedTo(clsUser::pAddClient, currentUser->getPermissions()) ? _showAddNewClientScreen() : clsAccessDeniedScreen::showAccessDeniedScreen();
            _goBackToMainMenu();
            break;
        case enMainMenuOption::enDeleteClient:
            isAllowedTo(clsUser::pDeleteClient, currentUser->getPermissions()) ? _showDeleteClientScreen() : clsAccessDeniedScreen::showAccessDeniedScreen();
            _goBackToMainMenu();
            break;
        case enMainMenuOption::enUpdateClient:
            isAllowedTo(clsUser::pUpdateClient, currentUser->getPermissions()) ? _showUpdateClientScreen() : clsAccessDeniedScreen::showAccessDeniedScreen();
            _goBackToMainMenu();
            break;
        case enMainMenuOption::enFindClient:
            isAllowedTo(clsUser::pFindClient, currentUser->getPermissions()) ? _showFindClientScreen() : clsAccessDeniedScreen::showAccessDeniedScreen();
            _goBackToMainMenu();
            break;
        case enMainMenuOption::enTransactions:
            isAllowedTo(clsUser::pTransactions, currentUser->getPermissions()) ? _showTransactionsScreen() : clsAccessDeniedScreen::showAccessDeniedScreen();
            _goBackToMainMenu();
            break;
        case enMainMenuOption::enManageUsers:
            isAllowedTo(clsUser::pManageUsers, currentUser->getPermissions()) ? _showManageUsersScreen() : clsAccessDeniedScreen::showAccessDeniedScreen();
            _goBackToMainMenu();
            break;
        case enMainMenuOption::enLoginRegister:
            isAllowedTo(clsUser::pShowLogins, currentUser->getPermissions()) ? _showLoginRegisterScreen() : clsAccessDeniedScreen::showAccessDeniedScreen();
            _goBackToMainMenu();
        case enMainMenuOption::enCurrencyExchange:
            isAllowedTo(clsUser::pCurrencyExchange, currentUser->getPermissions()) ? _showCurrencyExchangeScreen() : clsAccessDeniedScreen::showAccessDeniedScreen();
            _goBackToMainMenu();
        case enMainMenuOption::enLogout:
            currentUser = NULL;
            break;
        }
    }
public:
    static void showMainMenu(){
        _drawScreenHeader(clsUtil::tabs(7) + "Main Screen");
        cout << endl;
        cout << clsUtil::tabs(5) << "=============================================\n";
        cout << clsUtil::tabs(7) << "Main Menu\n";
        cout << clsUtil::tabs(5) << "=============================================\n";
        cout << clsUtil::tabs(5) << " [1] Show Client List.\n";
        cout << clsUtil::tabs(5) << " [2] Add New Client.\n";
        cout << clsUtil::tabs(5) << " [3] Delete Client.\n";
        cout << clsUtil::tabs(5) << " [4] Update Client Info.\n";
        cout << clsUtil::tabs(5) << " [5] Find Client.\n";
        cout << clsUtil::tabs(5) << " [6] Transactions.\n";
        cout << clsUtil::tabs(5) << " [7] Manage Users.\n";
        cout << clsUtil::tabs(5) << " [8] Login Register.\n";
        cout << clsUtil::tabs(5) << " [9] Currency Exchange.\n";
        cout << clsUtil::tabs(5) << " [10] Logout.\n";
        cout << clsUtil::tabs(5) << "=============================================\n";
        _performMainMenuOption((enMainMenuOption)_readMainMenuOption());

    }
};

#endif // CLSMAINSCREEN_H
