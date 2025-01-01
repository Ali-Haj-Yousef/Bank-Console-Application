#ifndef CLSTRANSFERLOGLISTSCREEN_H
#define CLSTRANSFERLOGLISTSCREEN_H
#include <iostream>
using namespace std;
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsUtil.h"

class clsTransferLogListScreen : protected clsScreen
{
private:

    static void _printTransferRecord(clsBankClient::stTransferRecord transfer){
        cout << "| " << left << setw(35) << transfer.dateTime << "| " << left << setw(12) << transfer.sourceAccountNumber << "| " << left << setw(12) << transfer.destinationAccountNumber << "| " << left << setw(12) << transfer.amount << "| " << left << setw(18) <<  transfer.sourceAccountBalance << "| " << left << setw(18) << transfer.destinationAccountBalance << "| " << left << setw(15) << transfer.username << endl;
    }

public:

    static void showTransferLogListScreen(){
        vector <clsBankClient::stTransferRecord> transfers = clsBankClient::getTransferLogList();
        string title = clsUtil::tabs(7) + "Transfer Log List Screen";
        string subTitle = clsUtil::tabs(8) + "(" + to_string(transfers.size()) + ") Record (s).";
        _drawScreenHeader(title, subTitle);
        cout << "\n_______________________________________________________________________________________________________________________________________\n\n";
        cout << "| " << left << setw(35) << "Date/Time" << "| " << left << setw(12) << "s.Acc" << "| " << left << setw(12) << "d.Acc" << "| " << left << setw(12) << "Amount" << "| " << left << setw(18) <<  "s.Balance" << "| " << left << setw(18) << "d.Balance" << "| " << left << setw(15) << "User";
        cout << "\n_______________________________________________________________________________________________________________________________________\n\n";
        for(clsBankClient::stTransferRecord& transfer : transfers)
            _printTransferRecord(transfer);
        cout << "\n_______________________________________________________________________________________________________________________________________\n\n";

    }

};

#endif // CLSTRANSFERLOGLISTSCREEN_H
