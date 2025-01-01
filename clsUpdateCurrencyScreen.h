#ifndef CLSUPDATECURRENCYSCREEN_H
#define CLSUPDATECURRENCYSCREEN_H
#include <iostream>
using namespace std;
#include "clsScreen.h"

class clsUpdateCurrencyScreen : protected clsScreen
{
private:

    static void _printCurrency(clsCurrency currency){
        cout << "\n\nCurrency Card:\n";
        cout << "_______________________________________\n";
        cout << "Country : " << currency.getCountry() << endl;
        cout << "Code : " << currency.getCurrencyCode() << endl;
        cout << "Name : " << currency.getCurrencyName() << endl;
        cout << "Rate(1$) : " << currency.getRate() << endl;
        cout << "_______________________________________\n";
    }

public:

    static void showUpdateCurrencyScreen(){
        _drawScreenHeader(clsUtil::tabs(7) + "Update Currency Screen");
        clsCurrency * currency;
        string currencyCode = clsInputValidate::readString("\nPlease Enter Currency Code: ");
        while((currency = clsCurrency::FindByCode(currencyCode)) == NULL)
            currencyCode = clsInputValidate::readString("\nError! This Currency Doesn't Exist, Enter Another Code: ");
        _printCurrency(*currency);
        char decision;
        cout << "\nAre You Sure You Want To Update The Rate Of This Currency? y/n? ";
        cin >> decision;
        if(decision == 'y' || decision == 'Y'){
            cout << "\nUpdate Currency Rate:\n";
            cout << "_______________________\n\n";
            float newRate = clsInputValidate::readFloatNumber("\nEnter New Rate: ");
            currency->UpdateRate(newRate);
            cout << "\nCurrency Rate Updated Successfully :-)\n\n";
            _printCurrency(*currency);
        }
    }
};

#endif // CLSUPDATECURRENCYSCREEN_H
