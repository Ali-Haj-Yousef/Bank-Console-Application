#ifndef CLSDELETECLIENTSCREEN_H
#define CLSDELETECLIENTSCREEN_H
#include <iostream>
using namespace std;
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsUtil.h"
#include <vector>
#include <string>

class clsDeleteClientScreen : protected clsScreen
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

    static void showDeleteClientScreen(){
        _drawScreenHeader(clsUtil::tabs(7) + "Delete Client Screen");
        string accountNumber = clsInputValidate::readString("\n\nEnter an account number to be deleted: ");
        while(!clsBankClient::isClientExist(accountNumber)){
            cout << "\nThis account number doesn't exist, enter another one: ";
            accountNumber = clsInputValidate::readString();
        }
        clsBankClient * client = clsBankClient::Find(accountNumber);
        _printClient(*client);
        char decision;
        cout << "\nAre you sure you want to delete this client? y/n? ";
        cin >> decision;
        if(decision == 'y' || decision == 'Y'){
            client->Delete();
            cout << "\nClient is deleted successfully.";
        }
        delete client;
    }
};

#endif // CLSDELETECLIENTSCREEN_H
