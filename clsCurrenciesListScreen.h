#ifndef CLSCURRENCIESLISTSCREEN_H
#define CLSCURRENCIESLISTSCREEN_H
#include <iostream>
using namespace std;
#include "clsScreen.h"
#include <iomanip>
#include "clsCurrency.h"
#include "clsUtil.h"

class clsCurrenciesListScreen : protected clsScreen
{
private:

    static void _printCurrencyRecordLine(clsCurrency currency){
        cout << "| " << left << setw(35) << currency.getCountry() << "| " << left << setw(10) << currency.getCurrencyCode() << "| " << left << setw(45) << currency.getCurrencyName() << "| " << left << setw(15) << currency.getRate() << endl;
    }

public:
    static void showCurrenciesListScreen(){
        vector <clsCurrency> currencies = clsCurrency::loadCurrenciesFromFile();
        string title = clsUtil::tabs(7) + "Currencies List Screen";
        string subTitle = clsUtil::tabs(7) + "  (" + to_string(currencies.size()) + ") Currency.";
        _drawScreenHeader(title, subTitle);
        cout << endl;
        cout << "__________________________________________________________________________________________________________\n\n";
        cout << "| " << left << setw(35) << "Country" << "| " << left << setw(10) << "Code" << "| " << left << setw(45) << "Name" << "| " << left << setw(15) << "Rate/(1$)" << endl;
        cout << "__________________________________________________________________________________________________________\n\n";
        for(clsCurrency& currency : currencies)
            _printCurrencyRecordLine(currency);
    }
};

#endif // CLSCURRENCIESLISTSCREEN_H
