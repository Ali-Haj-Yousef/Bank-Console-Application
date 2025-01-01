#ifndef CLSADDNEWCLIENTSCREEN_H
#define CLSADDNEWCLIENTSCREEN_H
#include <iostream>
using namespace std;
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsUtil.h"
#include <vector>
#include <string>

class clsAddNewClientScreen : protected clsScreen
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

    static void showAddNewClientScreen(){
        _drawScreenHeader(clsUtil::tabs(7) + "Add New Client Screen");
        string accountNumber = clsInputValidate::readString("\n\nEnter an account number: ");
        while(clsBankClient::isClientExist(accountNumber)){
            cout << endl << "This account number already exists, enter another one: ";
            accountNumber = clsInputValidate::readString();
        }
        clsBankClient client;
        client.setAccountNumber(accountNumber);
        _readClientInfo(client);
        client.Add();
        cout << endl << "Client is added successfully.\n\n";
        _printClient(client);
    }
};

#endif // CLSADDNEWCLIENTSCREEN_H
