#ifndef CLSCURRENCYEXCHANGESCREEN_H
#define CLSCURRENCYEXCHANGESCREEN_H
#include <iostream>
using namespace std;
#include "clsScreen.h"
#include "clsCurrenciesListScreen.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateCurrencyScreen.h"
#include "clsCurrencyCalculatorScreen.h"

class clsCurrencyExchangeScreen : protected clsScreen
{
private:

    enum enCurrencyExchangeOption{
        enListCurrencies = 1,
        enFindCurrency = 2,
        enUpdateRate = 3,
        enCurrencyCalculator = 4,
        enMainMenu = 5
    };

    static short _readCurrencyExchangeOption(){
        return clsInputValidate::readShortNumberBetween(1, 5, "\n" + clsUtil::tabs(5) + "Choose what do you want to do. [1 ~ 5]. ");
    }

    static void _showListCurrenciesScreen(){
        clsCurrenciesListScreen::showCurrenciesListScreen();
    }

    static void _showFindCurrencyScreen(){
        clsFindCurrencyScreen::showFindCurrencyScreen();
    }

    static void _showUpdateRateScreen(){
        clsUpdateCurrencyScreen::showUpdateCurrencyScreen();
    }

    static void _showCurrencyCalculatorScreen(){
        clsCurrencyCalculatorScreen::showCurrencyCalculatorScreen();
    }

    static void _goBackToCurrencyExchangeScreen(){
        cout << endl << "\nPress any key to go back to currency exchange menu ...";
        system("pause>0");
        showCurrencyExchangeMenuScreen();
    }

    static void _performCurrencyExchangeOperation(enCurrencyExchangeOption option){
        switch(option){
        case enCurrencyExchangeOption::enListCurrencies:
            _showListCurrenciesScreen();
            _goBackToCurrencyExchangeScreen();
            break;
        case enCurrencyExchangeOption::enFindCurrency:
            _showFindCurrencyScreen();
            _goBackToCurrencyExchangeScreen();
            break;
        case enCurrencyExchangeOption::enCurrencyCalculator:
            _showCurrencyCalculatorScreen();
            _goBackToCurrencyExchangeScreen();
            break;
        case enCurrencyExchangeOption::enUpdateRate:
            _showUpdateRateScreen();
            _goBackToCurrencyExchangeScreen();
            break;
        case enCurrencyExchangeOption::enMainMenu:
            break;
        }
    }

public:

    static void showCurrencyExchangeMenuScreen(){
        _drawScreenHeader(clsUtil::tabs(6) + "Currency Exchange Main Screen");
        cout << endl;
        cout << clsUtil::tabs(5) << "=============================================\n";
        cout << clsUtil::tabs(7) << "Currency Exchange Menu\n";
        cout << clsUtil::tabs(5) << "=============================================\n";
        cout << clsUtil::tabs(5) << " [1] List Currencies.\n";
        cout << clsUtil::tabs(5) << " [2] Find Currency.\n";
        cout << clsUtil::tabs(5) << " [3] Update Rate.\n";
        cout << clsUtil::tabs(5) << " [4] Currency Calculator.\n";
        cout << clsUtil::tabs(5) << " [5] Main Menu.\n";
        cout << clsUtil::tabs(5) << "=============================================\n";
        _performCurrencyExchangeOperation((enCurrencyExchangeOption)_readCurrencyExchangeOption());
    }
};

#endif // CLSCURRENCYEXCHANGESCREEN_H
