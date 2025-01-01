#ifndef CLSTOTALBALANCESSCREEN_H
#define CLSTOTALBALANCESSCREEN_H
#include <iostream>
using namespace std;
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsString.h"
#include "clsUtil.h"

class clsTotalBalancesScreen : clsScreen
{
private:

    static void _printClientRecordBalanceLine(clsBankClient client){
        cout << "| " << left << setw(20) << client.getAccountNumber() << "| " << left << setw(25) << client.getFirstName() + " " + client.getLastName() << "| " << left << setw(15) << client.getAccountBalance() << "\n";
    }

public:

    static void showTotalBalancesScreen(){
        vector <clsBankClient> clients = clsBankClient::loadClientsFromFile();
        _drawScreenHeader(clsUtil::tabs(7) + "Balances List Screen", clsUtil::tabs(7) + " (" + to_string(clients.size()) + ") Client(s)");
        cout << "\n_____________________________________________________________\n\n";
        cout << "| " << left << setw(20) << "Account Number" << "| " << left << setw(25) << "Client Name" << "| " << left << setw(15) << "Balance";
        cout << "\n_____________________________________________________________\n\n";
        for(clsBankClient& client : clients)
            _printClientRecordBalanceLine(client);
        cout << "\n_____________________________________________________________\n\n";
        float totalBalances = clsBankClient::getTotatBalances();
        cout << "\t\t\tTotal Balances = " << totalBalances << endl;
        cout << "\t\t\t(" << clsString::trimLeft(clsUtil::getTextNumber(totalBalances)) << ")";
    }
};

#endif // CLSTOTALBALANCESSCREEN_H
