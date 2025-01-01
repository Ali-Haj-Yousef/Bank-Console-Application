#ifndef CLSUPDATECLIENTSCREEN_H
#define CLSUPDATECLIENTSCREEN_H
#include <iostream>
using namespace std;
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsUtil.h"
#include <vector>
#include <string>

class clsUpdateClientScreen : protected clsScreen
{
private:

    static void _readClientInfo(clsBankClient& client){
        client.setFirstName(clsInputValidate::readString("\nEnter First Name : "));
        cout << endl;
        client.setLastName(clsInputValidate::readString("\nEnter Last Name : "));
        cout << endl;
        client.setEmail(clsInputValidate::readString("\nEnter Email :"));
        cout << endl;
        client.setPhone(clsInputValidate::readString("\nEnter Phone :"));
        cout << endl;
        client.setPinCode(clsInputValidate::readString("\nEnter Pin Code:"));
        cout << endl;
        client.setAccountBalance(clsInputValidate::readFloatNumber("\nEnter Account Balance : "));
        cout << endl;
    }

    static void _printClient(clsBankClient client){
        cout << "\nClient Card :";
        cout << "\n_____________________________________________\n\n";
        cout << "First Name : " << client.getFirstName() << endl;
        cout << "Last Name : " << client.getLastName() << endl;
        cout << "Email : " << client.getEmail() << endl;
        cout << "Phone : " << client.getPhone() << endl;
        cout << "Account Number : " << client.getAccountNumber() << endl;
        cout << "Pin Code : " << client.getPinCode() << endl;
        cout << "Account Balance : " << client.getAccountBalance() << endl;
        cout << "_____________________________________________\n";
    }

public:

    static void showUpdateClientScreen(){
        _drawScreenHeader(clsUtil::tabs(7) + "Update Client Screen");
        string accountNumber = clsInputValidate::readString("\n\nPlease enter an account number : ");
        while(!clsBankClient::isClientExist(accountNumber)){
            cout << "\nAccount number is not found, choose another one: ";
            accountNumber = clsInputValidate::readString();
        }
        clsBankClient * clientPointer = clsBankClient::Find(accountNumber);
        _printClient(*clientPointer);
        cout << "\nUpdate Client Card:\n";
        cout << "______________________________\n";
        _readClientInfo(*clientPointer);
        _printClient(*clientPointer);
        clientPointer->Update();
        delete clientPointer;
    }
};

#endif // CLSUPDATECLIENTSCREEN_H
