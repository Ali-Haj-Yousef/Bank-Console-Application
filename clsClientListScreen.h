#ifndef CLSCLIENTLISTSCREEN_H
#define CLSCLIENTLISTSCREEN_H
#include <iostream>
using namespace std;
#include "clsScreen.h"
#include "clsBankClient.h"
#include <vector>
#include <string>

class clsClientListScreen : protected clsScreen
{
private:

    static void printClientRecordLine(clsBankClient client){
        cout << "| " << left << setw(20) << client.getAccountNumber() << "| " << left << setw(25) << client.getFirstName() + " " + client.getLastName() << "| " << left << setw(15) << client.getPhone() << "| " << left << setw(35) << client.getEmail() << "| " << left << setw(15) <<  client.getPinCode() << "| " << left << setw(12) << client.getAccountBalance() << "\n";
    }
public:

    static void showClients(){
        vector <clsBankClient> clients = clsBankClient::loadClientsFromFile();
        _drawScreenHeader(clsUtil::tabs(7) + "Client List Screen", clsUtil::tabs(7) + " (" + to_string(clients.size()) + ") Client (s)");
        cout << "___________________________________________________________________________________________________________________________________________\n\n";
        cout << "| " << left << setw(20) << "Account Number" << "| " << left << setw(25) << "Client Name" << "| " << left << setw(15) << "Phone" << "| " << left << setw(35) << "Email" << "| " << left << setw(15) <<  "Pin Code" << "| " << left << setw(12) << "Balance" << endl;
        cout << "___________________________________________________________________________________________________________________________________________\n\n";
        for(clsBankClient& client : clients)
            printClientRecordLine(client);
    }
};

#endif // CLSCLIENTLISTSCREEN_H
