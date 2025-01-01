#ifndef CLSTRANSACTIONSSCREEN_H
#define CLSTRANSACTIONSSCREEN_H
#include <iostream>
#include "clsScreen.h"
using namespace std;
#include <iomanip>
#include "clsUtil.h"
#include "clsInputValidate.h"
#include "clsMainScreen.h"
#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTotalBalancesScreen.h"
#include "clsTransferScreen.h"
#include "clsTransferLogListScreen.h"

class clsTransactionsScreen : protected clsScreen
{
    private:
        enum enTransactionsMenuOption{
            enDeposit = 1,
            enWithdraw = 2,
            enTotalBalances = 3,
            enTransfer = 4,
            enTransferLog = 5,
            enMainMenu = 6
        };

        static void _showDepositScreen(){
            clsDepositScreen::showDepositScreen();
        }

        static void _showWithdrawScreen(){
            clsWithdrawScreen::showWithdrawScreen();
        }

        static void _showTotalBalancesScreen(){
            clsTotalBalancesScreen::showTotalBalancesScreen();
        }

        static void _showTransferScreen(){
            clsTransferScreen::showTransferScreen();
        }

        static void _showTransferLogScreen(){
            clsTransferLogListScreen::showTransferLogListScreen();
        }

        static void _goBackToTransactionsMenu(){
            cout << endl << "\nPress any key to go back to Transactions menu ...";
            system("pause>0");
            showTransactionsMenu();
        }

        static short _readTransactionsMenuOption(){
            return clsInputValidate::readShortNumberBetween(1, 6, "\n" + clsUtil::tabs(5) + "Choose what do you want to do. [1 ~ 6]. ");
        }

        static void _performTransactionsMenuOption(enTransactionsMenuOption option){
            switch(option){
            case enTransactionsMenuOption::enDeposit:
                _showDepositScreen();
                _goBackToTransactionsMenu();
                break;
            case enTransactionsMenuOption::enMainMenu:
                break;
            case enTransactionsMenuOption::enTotalBalances:
                _showTotalBalancesScreen();
                _goBackToTransactionsMenu();
                break;
            case enTransactionsMenuOption::enTransfer:
                _showTransferScreen();
                _goBackToTransactionsMenu();
                break;
            case enTransactionsMenuOption::enTransferLog:
                _showTransferLogScreen();
                _goBackToTransactionsMenu();
                break;
            case enTransactionsMenuOption::enWithdraw:
                _showWithdrawScreen();
                _goBackToTransactionsMenu();
                break;
            }
        }
public:
    static void showTransactionsMenu(){
        _drawScreenHeader(clsUtil::tabs(7) + "Transactions Screen");
        cout << endl;
        cout << clsUtil::tabs(5) << "=============================================\n";
        cout << clsUtil::tabs(7) << "Transactions Menu\n";
        cout << clsUtil::tabs(5) << "=============================================\n";
        cout << clsUtil::tabs(5) << " [1] Deposit.\n";
        cout << clsUtil::tabs(5) << " [2] Withdraw.\n";
        cout << clsUtil::tabs(5) << " [3] Total Balances.\n";
        cout << clsUtil::tabs(5) << " [4] Transfer.\n";
        cout << clsUtil::tabs(5) << " [5] Transfer Log.\n";
        cout << clsUtil::tabs(5) << " [6] Main Menu.\n";
        cout << clsUtil::tabs(5) << "=============================================\n";
        _performTransactionsMenuOption((enTransactionsMenuOption)_readTransactionsMenuOption());

    }
};

#endif // CLSTRANSACTIONSSCREEN_H
