#ifndef CLSTRANSFERSCREEN_H
#define CLSTRANSFERSCREEN_H
#include <iostream>
using namespace std;
#include "clsScreen.h"
#include "clsBankClient.h"
#include"clsInputValidate.h"

class clsTransferScreen : protected clsScreen
{
private:

    static void _printClientCard(clsBankClient * client){
        cout << endl << "Client Card:\n";
        cout << "__________________________________________________\n";
        cout << "Full Name      : " << client->getFirstName() + client->getLastName() << endl;
        cout << "Account Number : " << client->getAccountNumber() << endl;
        cout << "Balance        : " << client->getAccountBalance() << endl;
        cout << "__________________________________________________\n";
    }

    static string _readAccountNumber(string message){
        string accountNumber = clsInputValidate::readString(message);
        while(!clsBankClient::isClientExist(accountNumber)){
            cout << "\nThis account number doesn't exist, enter another one: ";
            accountNumber = clsInputValidate::readString();
        }
        return accountNumber;
    }

    static float _readTransferAmount(float sourceAccountBalance){
        float transferAmount = clsInputValidate::readFloatNumber("\nEnter transfer amount. ");
        while(transferAmount > sourceAccountBalance)
            transferAmount = clsInputValidate::readFloatNumber("\nAmount exceeds the available balance, enter another amount. ");
        return transferAmount;
    }

public:

    static void showTransferScreen(){
        _drawScreenHeader(clsUtil::tabs(7) + "Transfer Screen");
        string sourceAccountNumber = _readAccountNumber("\n\nPlease enter an account number to transfer from: ");
        clsBankClient * sourceClient = clsBankClient::Find(sourceAccountNumber);
        _printClientCard(sourceClient);
        string destinationAccountNumber = _readAccountNumber("\n\nPlease enter an account number to transfer to: ");
        clsBankClient * destinationClient = clsBankClient::Find(destinationAccountNumber);
        _printClientCard(destinationClient);
        float transferAmount = _readTransferAmount(sourceClient->getAccountBalance());
        char decision;
        cout << "\nAre you sure you want to perform this operation? y/n? ";
        cin >> decision;
        if(decision == 'y' || decision == 'Y'){
            if(sourceClient->transfer(transferAmount, destinationClient))
                cout << "\nTransfer is done successfully.\n";
            else
                cout << "\nTransfer failed.\n";
            _printClientCard(sourceClient);
            _printClientCard(destinationClient);
        }
    }

};

#endif // CLSTRANSFERSCREEN_H
