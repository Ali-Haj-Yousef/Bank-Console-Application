#ifndef CLSFINDCURRENCYSCREEN_H
#define CLSFINDCURRENCYSCREEN_H
#include <iostream>
using namespace std;
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsCurrency.h"

class clsFindCurrencyScreen : protected clsScreen
{
private:

    enum enFindOption{
        enCode = 1,
        enCountry = 2
    };

    static short _readFindOption(){
        return clsInputValidate::readShortNumberBetween(1, 2, "\nFind by: [1] Code or [2] Country? ");
    }

    static void _printCurrency(clsCurrency currency){
        cout << "Currency Card:\n";
        cout << "_______________________________________\n";
        cout << "Country : " << currency.getCountry() << endl;
        cout << "Code : " << currency.getCurrencyCode() << endl;
        cout << "Name : " << currency.getCurrencyName() << endl;
        cout << "Rate(1$) : " << currency.getRate() << endl;
        cout << "_______________________________________\n";
    }

    static void _performFindOperation(enFindOption findOption){
        clsCurrency * currency;
        if(findOption == enFindOption::enCode){
            string currencyCode = clsInputValidate::readString("\nPlease enter currency code: ");
            currency = clsCurrency::FindByCode(currencyCode);
        }
        else{
            string country = clsInputValidate::readString("\nPlease enter country name: ");
            currency = clsCurrency::FindByCountry(country);
        }
        if(currency == NULL)
            cout << "\nOops! Currency was not found! :-(";
        else{
            cout << "\nCurrency was found :-)\n\n";
            _printCurrency(*currency);
        }

    }

public:
    static void showFindCurrencyScreen(){
        _drawScreenHeader(clsUtil::tabs(7) + "Find Currency Screen");
        _performFindOperation((enFindOption)_readFindOption());
    }
};

#endif // CLSFINDCURRENCYSCREEN_H
