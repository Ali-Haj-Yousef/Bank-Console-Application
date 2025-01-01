#ifndef CLSBANKCLIENT_H
#define CLSBANKCLIENT_H
#include <iostream>
using namespace std;
#include "clsPerson.h"
#include "clsString.h"
#include "clsInputValidate.h"
#include "global.h"
#include <string>
#include <fstream>
#include <vector>


class clsBankClient : public clsPerson
{

public:

    struct stTransferRecord{
        string dateTime;
        string sourceAccountNumber;
        string destinationAccountNumber;
        float amount;
        float sourceAccountBalance;
        float destinationAccountBalance;
        string username;
    };

private:
    string _accountNumber;
    string _pinCode;
    float _accountBalance;

    static string _convertClientObjectToDataLine(clsBankClient client){
         return client.getFirstName() + "#//#" + client.getLastName() + "#//#" + client.getEmail() + "#//#" + client.getPhone() + "#//#" + client.getAccountNumber() + "#//#" + client.getPinCode() + "#//#" + to_string(client.getAccountBalance());
    }

    static clsBankClient _convertClientDataLineToObject(string clientDataLine, string delim){
        vector<string> clientDataVector = clsString::splitString(clientDataLine, delim);
        return clsBankClient(clientDataVector[0], clientDataVector[1], clientDataVector[2], clientDataVector[3], clientDataVector[4], clientDataVector[5], stof(clientDataVector[6]));
    }

    static void _saveClientsToFile(vector <clsBankClient> clients){
        fstream file;
        file.open("clients.txt", ios::out);
        file.close();
        file.open("clients.txt", ios::app);
        if(file.is_open()){
            for(clsBankClient client : clients)
                file << _convertClientObjectToDataLine(client) << endl;
        }
        file.close();
    }

    string _prepareTransferRecord(float amount, clsBankClient destinationClient, string username){
        string dataLine = clsDate::getSystemDateTime() + "#//#";
        dataLine += _accountNumber + "#//#";
        dataLine += destinationClient.getAccountNumber() + "#//#";
        dataLine += to_string(amount) + "#//#";
        dataLine += to_string(_accountBalance) + "#//#";
        dataLine += to_string(destinationClient.getAccountBalance()) + "#//#";
        dataLine += username;
        return dataLine;
    }

    static stTransferRecord _getTransferLogStruct(string dataLine){
        vector <string> dataLineVector = clsString::splitString(dataLine, "#//#");
        stTransferRecord transferRecord;
        transferRecord.dateTime = dataLineVector[0];
        transferRecord.sourceAccountNumber = dataLineVector[1];
        transferRecord.destinationAccountNumber = dataLineVector[2];
        transferRecord.amount = stoi(dataLineVector[3]);
        transferRecord.sourceAccountBalance = stoi(dataLineVector[4]);
        transferRecord.destinationAccountBalance = stoi(dataLineVector[5]);
        transferRecord.username = dataLineVector[6];
        return transferRecord;
    }

    void _registerTransferLog(float amount, clsBankClient destinationClient, string username){
        string dataLine = _prepareTransferRecord(amount, destinationClient, username);
        fstream file;
        file.open("transferLog.txt", ios::out | ios::app);
        file << dataLine << endl;
        file.close();
    }

public:
    clsBankClient(string firstName, string lastName, string email, string phone, string accountNumber, string pinCode, float accountBalance) : clsPerson(firstName, lastName, email, phone){
        _accountNumber = accountNumber;
        _pinCode = pinCode;
        _accountBalance = accountBalance;
    }

    clsBankClient(){}

    void setAccountNumber(string accountNumber){_accountNumber = accountNumber;}

    string getAccountNumber(){return _accountNumber;}

    void setPinCode(string pinCode){_pinCode = pinCode;}

    string getPinCode(){return _pinCode;}

    void setAccountBalance(float accountBalance){_accountBalance = accountBalance;}

    float getAccountBalance(){return _accountBalance;}

    static clsBankClient * Find(string accountNumber, string pinCode = ""){
        vector <clsBankClient> clients = loadClientsFromFile();
        for(clsBankClient client : clients)
            if(client.getAccountNumber() == accountNumber){
                if((pinCode != "") && (client.getPinCode() != pinCode))
                    return NULL;
                clsBankClient * clientPointer = new clsBankClient(client);
                return clientPointer;
            }
        return NULL;
    }

    static bool isClientExist(string accountNumber){
        return Find(accountNumber) != NULL;
    }

    void Update(){
        vector <clsBankClient> clients = loadClientsFromFile();
        for(clsBankClient& client : clients)
            if(client.getAccountNumber() == _accountNumber){
                client = *this;
                break;
            }
        _saveClientsToFile(clients);
    }

    void Add(){
        fstream file;
        file.open("clients.txt", ios::app);
        file << endl << _convertClientObjectToDataLine(*this);
        file.close();
    }

    void Delete(){
        vector <clsBankClient> clients = loadClientsFromFile();
        for(short i = 0; i < sizeof(clients); i++)
            if(clients[i].getAccountNumber() == this->getAccountNumber()){
                clients.erase(clients.begin() + i);
                break;
            }
        _saveClientsToFile(clients);
    }

    static vector <clsBankClient> loadClientsFromFile(){
        vector <clsBankClient> clients;
        fstream file;
        file.open("clients.txt", ios::in);
        if(file.is_open()){
            string line;
            while(getline(file, line)){
                clients.push_back(_convertClientDataLineToObject(line, "#//#"));
            }
            file.close();
        }
        return clients;
    }

    static vector <stTransferRecord> getTransferLogList(){
        vector <stTransferRecord> transfers;
        fstream file;
        file.open("transferLog.txt", ios::in);
        if(file.is_open()){
            string line;
            while(getline(file, line))
                transfers.push_back(_getTransferLogStruct(line));
            file.close();
        }
        return transfers;
    }

    static double getTotatBalances(){
        vector <clsBankClient> clients = loadClientsFromFile();
        double totalBalances = 0;
        for(clsBankClient& client : clients)
            totalBalances += client.getAccountBalance();
        return totalBalances;
    }

    void deposit(double amount){
        this->setAccountBalance(_accountBalance + amount);
        vector <clsBankClient> clients = loadClientsFromFile();
        for(clsBankClient& client : clients)
            if(client.getAccountNumber() == _accountNumber){
                client.setAccountBalance(_accountBalance);
                break;
            }
        _saveClientsToFile(clients);
    }

    bool transfer(float amount, clsBankClient * destinationClient){
        if(amount > _accountBalance)
            return false;
        this->deposit(-1 * amount);
        destinationClient->deposit(amount);
        _registerTransferLog(amount, *destinationClient, currentUser->getUserName());
        return true;
    }

};

#endif // CLSBANKCLIENT_H
