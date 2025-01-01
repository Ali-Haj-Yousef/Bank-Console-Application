#ifndef CLSCURRENCY_H
#define CLSCURRENCY_H
#include <iostream>
using namespace std;
#include <vector>
#include "clsUtil.h"
#include "clsString.h"

class clsCurrency
{
private:

    string _country;
    string _currencyCode;
    string _currencyName;
    float _rate;

    static clsCurrency _convertDataLineToCurrencyObject(string line){
        vector <string> lineVector = clsString::splitString(line, "#//#");
        return clsCurrency(lineVector[0], lineVector[1], lineVector[2], stof(lineVector[3]));
    }

    static string _convertCurrencyObjectToDataLine(clsCurrency currency){
        string dataLine = currency.getCountry() + "#//#";
        dataLine += currency.getCurrencyCode() + "#//#";
        dataLine += currency.getCurrencyName() + "#//#";
        dataLine += to_string(currency.getRate());
        return dataLine;
    }

    static void _saveCurrenciesToFile(vector <clsCurrency> currencies){
        fstream file;
        file.open("Currencies.txt", ios::out);
        if(file.is_open()){
            for(clsCurrency& currency : currencies)
                file << _convertCurrencyObjectToDataLine(currency) << endl;
            file.close();
        }
    }

public:

    clsCurrency(string country, string currencyCode, string currencyName, float rate){
        _country = country;
        _currencyCode = currencyCode;
        _currencyName = currencyName;
        _rate = rate;
    }

    clsCurrency(){}

    string getCountry(){return _country;}

    string getCurrencyCode(){return _currencyCode;}

    string getCurrencyName(){return _currencyName;}

    float getRate(){return _rate;}

    void setRate(float rate){_rate = rate;}

    static vector <clsCurrency> loadCurrenciesFromFile(){
        vector <clsCurrency> currenciesVector;
        fstream file;
        file.open("Currencies.txt", ios::in);
        if(file.is_open()){
            string line;
            while(getline(file, line))
                currenciesVector.push_back(_convertDataLineToCurrencyObject(line));
            file.close();
        }
        return currenciesVector;
    }

    static clsCurrency * FindByCode(string code){
        code = clsString::toLower(code);
        vector <clsCurrency> currencies = loadCurrenciesFromFile();
        for(clsCurrency& currency : currencies)
            if(clsString::toLower(currency.getCurrencyCode()) == code)
                return new clsCurrency(currency);
        return NULL;
    }

    static clsCurrency * FindByCountry(string country){
        country = clsString::toLower(country);
        vector <clsCurrency> currencies = loadCurrenciesFromFile();
        for(clsCurrency& currency : currencies)
            if(clsString::toLower(currency.getCountry()) == country)
                return new clsCurrency(currency);
        return NULL;
    }

    void Update(){
        vector <clsCurrency> currencies = loadCurrenciesFromFile();
        for(clsCurrency& currency : currencies)
            if(currency.getCurrencyCode() == _currencyCode){
                currency = *this;
                break;
            }
        _saveCurrenciesToFile(currencies);
    }

    void UpdateRate(float newRate){
        _rate = newRate;
        Update();
    }

    static float convert(string fromCurrencyCode, string toCurrencyCode, float amount){
        clsCurrency * currency1 = clsCurrency::FindByCode(fromCurrencyCode);
        clsCurrency * currency2 = clsCurrency::FindByCode(toCurrencyCode);
        float amountIn$ToExchange = amount / currency1->getRate();
        float amountInCurrency2 = amountIn$ToExchange * currency2->getRate();
        return amountInCurrency2;
    }

};

#endif // CLSCURRENCY_H
