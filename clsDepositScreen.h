#ifndef CLSDEPOSITSCREEN_H
#define CLSDEPOSITSCREEN_H
#include <iostream>
using namespace std;
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

class clsDepositScreen : protected clsScreen
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

    static void showDepositScreen(){
        _drawScreenHeader(clsUtil::tabs(7) + "Deposit Screen");
        string accountNumber = clsInputValidate::readString("\n\nPlease enter an account number : ");
        while(!clsBankClient::isClientExist(accountNumber)){
            cout << "\nAccount number is not found, choose another one: ";
            accountNumber = clsInputValidate::readString();
        }
        clsBankClient * clientPointer = clsBankClient::Find(accountNumber);
        _printClient(*clientPointer);
        float depositAmount = clsInputValidate::readFloatNumber("\n\nPlease enter deposit amount. ");
        char decision;
        cout << "\nAre you sure you want to perform this transaction? ";
        cin >> decision;
        if(decision == 'y' || decision == 'Y'){
            clientPointer->deposit(depositAmount);
            cout << "\nAmount deposited successfully.";
            cout << "\n\nNew Balance is : " << clientPointer->getAccountBalance() + depositAmount;
        }

    }

};

#endif // CLSDEPOSITSCREEN_H
