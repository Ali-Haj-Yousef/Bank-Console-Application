#ifndef CLSCURRENCYCALCULATORSCREEN_H
#define CLSCURRENCYCALCULATORSCREEN_H
#include <iostream>
using namespace std;
#include "clsScreen.h"
#include "clsUtil.h"
#include "clsInputValidate.h"

class clsCurrencyCalculatorScreen : protected clsScreen
{
private:

    static void _printCurrency(clsCurrency currency){
        cout << "_______________________________________\n\n";
        cout << "Country : " << currency.getCountry() << endl;
        cout << "Code : " << currency.getCurrencyCode() << endl;
        cout << "Name : " << currency.getCurrencyName() << endl;
        cout << "Rate(1$) : " << currency.getRate() << endl;
        cout << "_______________________________________\n\n";
    }

    static clsCurrency * _getCurrency(string message){
        clsCurrency * currency;
        string currencyCode = clsInputValidate::readString(message);
        while((currency = clsCurrency::FindByCode(currencyCode)) == NULL)
            currencyCode = clsInputValidate::readString("\nError! This Currency Doesn't Exist, Enter Another Code: ");
        return currency;
    }

    static void _showCurrencyCalculatorScreen(){
        _drawScreenHeader(clsUtil::tabs(7) + "Currency Calculator Screen");
        clsCurrency * currencyFrom = _getCurrency("\nPlease Enter Currency1 Code: ");
        cout << "\nConvert From:\n";
        _printCurrency(*currencyFrom);
        clsCurrency * currencyTo = _getCurrency("\nPlease Enter Curency2 Code: ");
        cout << "\nConvert To:\n";
        _printCurrency(*currencyTo);
        float amountToExchange = clsInputValidate::readFloatNumber("\nEnter Amount To Exchange: ");
        float exchangedAmount = clsCurrency::convert(currencyFrom->getCurrencyCode(), currencyTo->getCurrencyCode(), amountToExchange);
        cout << amountToExchange << " " << currencyFrom->getCurrencyCode() << " = " << exchangedAmount << " " << currencyTo->getCurrencyCode();
    }

public:

    static void showCurrencyCalculatorScreen(){
        char decision = 'y';
        while(decision == 'y' || decision == 'Y'){
            _showCurrencyCalculatorScreen();
            cout << "\n\nDo You Want To Perform Another Calculation? y/n? ";
            cin >> decision;
        }
    }

};

#endif // CLSCURRENCYCALCULATORSCREEN_H
