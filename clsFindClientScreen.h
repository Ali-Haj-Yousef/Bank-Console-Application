#ifndef CLSFINDCLIENTSCREEN_H
#define CLSFINDCLIENTSCREEN_H
#include <iostream>
using namespace std;
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsUtil.h"
#include <vector>
#include <string>

class clsFindClientScreen : protected clsScreen
{
private:

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

    static void showFindClientScreen(){
        _drawScreenHeader(clsUtil::tabs(7) + "Find Client Screen");
        string accountNumber = clsInputValidate::readString("\n\nPlease enter an account number : ");
        while(!clsBankClient::isClientExist(accountNumber)){
            cout << "\nAccount number is not found, enter another one: ";
            accountNumber = clsInputValidate::readString();
        }
        clsBankClient * client = clsBankClient::Find(accountNumber);
        _printClient(*client);
        delete client;
    }
};

#endif // CLSFINDCLIENTSCREEN_H
