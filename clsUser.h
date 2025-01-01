#ifndef CLSUSER_H
#define CLSUSER_H
#include <iostream>
using namespace std;
#include "clsPerson.h"
#include "clsUser.h"
#include "clsString.h"
#include "clsDate.h"
#include "clsUtil.h"
#include <fstream>
#include <vector>
#include <string>

class clsUser : public clsPerson
{
public:

    struct stLoginRegisterRecord{
        string dateTime;
        string username;
        string password;
        short permissions;
    };

private:

    string _userName;
    string _password;
    short _permissions;

    static clsUser _convertUserDataLineToObject(string userDataLine, string delim){
        vector<string> userDataVector = clsString::splitString(userDataLine, delim);
        return clsUser(userDataVector[0], userDataVector[1], userDataVector[2], userDataVector[3], userDataVector[4], clsUtil::decryptText(userDataVector[5], 3), stoi(userDataVector[6]));
    }

    static string _convertUserObjectToDataLine(clsUser user){
         return user.getFirstName() + "#//#" + user.getLastName() + "#//#" + user.getEmail() + "#//#" + user.getPhone() + "#//#" + user.getUserName() + "#//#" + clsUtil::encryptText(user.getPassword(), 3) + "#//#" + to_string(user.getPermissions());
    }

    static void _saveUsersToFile(vector <clsUser> users){
        fstream file;
        file.open("users.txt", ios::out);
        if(file.is_open()){
            for(clsUser user : users)
                file << _convertUserObjectToDataLine(user) << endl;
        }
        file.close();
    }

    static stLoginRegisterRecord _convertLoginRegisterLineToRecord(string line){
        stLoginRegisterRecord loginRegisterRecord;
        vector <string> loginRegisterDataLine = clsString::splitString(line, "#//#");
        loginRegisterRecord.dateTime = loginRegisterDataLine[0];
        loginRegisterRecord.username = loginRegisterDataLine[1];
        loginRegisterRecord.password = loginRegisterDataLine[2];
        loginRegisterRecord.permissions = stoi(loginRegisterDataLine[3]);
        return loginRegisterRecord;
    }

    string _prepareLoginRecord(){
        return clsDate::getSystemDateTime() + "#//#" + _userName + "#//#" + _password + "#//#" + to_string(_permissions);
    }

public:

    clsUser(string firstName, string lastName, string email, string phone, string userName, string password, short permissions) : clsPerson(firstName, lastName, email, phone){
        _userName = userName;
        _password = password;
        _permissions = permissions;
    }

    clsUser(){}

    enum enPermissions{
        pShowClients = 1,
        pAddClient = 2,
        pDeleteClient = 4,
        pUpdateClient = 8,
        pFindClient = 16,
        pTransactions = 32,
        pManageUsers = 64,
        pShowLogins = 128,
        pCurrencyExchange = 256
    };

    void setUserName(string userName){_userName = userName;}

    string getUserName(){return _userName;}

    void setPassword(string password){_password = password;}

    string getPassword(){return _password;}

    void setPermissions(short permissions){_permissions = permissions;}

    short getPermissions(){return _permissions;}

    static vector <clsUser> loadUsersFromFile(){
        vector <clsUser> users;
        fstream file;
        file.open("users.txt", ios::in);
        if(file.is_open()){
            string line;
            while(getline(file, line)){
                users.push_back(_convertUserDataLineToObject(line, "#//#"));
            }
            file.close();
        }
        return users;
    }

    static vector <stLoginRegisterRecord> getLoginRegisterList(){
        vector <stLoginRegisterRecord> loginRegisterRecordVector;
        fstream file;
        file.open("logins.txt", ios::in);
        if(file.is_open()){
            string line;
            while(getline(file, line)){
                loginRegisterRecordVector.push_back(_convertLoginRegisterLineToRecord(line));
            }
            file.close();
        }
        return loginRegisterRecordVector;
    }

    static clsUser * Find(string userName, string password = ""){
        vector <clsUser> users = loadUsersFromFile();
        for(clsUser user : users)
            if(user.getUserName() == userName){
                if((password != "") && (user.getPassword() != password))
                    return NULL;
                clsUser * userPointer = new clsUser(user);
                return userPointer;
            }
        return NULL;
    }

    static bool isUserExist(string userName, string password = ""){
        return Find(userName, password) != NULL;
    }

    void Add(){
        fstream file;
        file.open("users.txt", ios::app);
        file << _convertUserObjectToDataLine(*this) << endl;
        file.close();
    }

    void Delete(){
        vector <clsUser> users = loadUsersFromFile();
        for(short i = 0; i < users.size(); i++)
            if(users[i].getUserName() == _userName){
                users.erase(users.begin() + i);
                break;
            }
        _saveUsersToFile(users);
    }

    void Update(){
        vector <clsUser> users = loadUsersFromFile();
        for(clsUser& user : users)
            if(user.getUserName() == _userName){
                user = *this;
                break;
            }
        _saveUsersToFile(users);
    }

    void registerLogIn(){
        string dataLine = _prepareLoginRecord();
        fstream file;
        file.open("logins.txt", ios::out | ios::app);
        file << dataLine << endl;
        file.close();
    }

};

#endif // CLSUSER_H
