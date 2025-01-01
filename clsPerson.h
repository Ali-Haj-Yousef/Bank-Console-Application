#ifndef CLSPERSON_H
#define CLSPERSON_H
#include <iostream>
#include "clsDate.h"
#include "clsString.h"
#include "clsPeriod.h"
#include "clsInputValidate.h"
#include "clsUtil.h"
using namespace std;

class clsPerson
{
private:
    string _firstName;
    string _lastName;
    string _email;
    string _phone;

public:
    clsPerson(string firstName, string lastName, string email, string phone){
        _firstName = firstName;
        _lastName = lastName;
        _email = email;
        _phone = phone;
    }

    clsPerson(){}

    void setFirstName(string firstName){_firstName = firstName;}

    string getFirstName(){return _firstName;}

    void setLastName(string lastName){_lastName = lastName;}

    string getLastName(){return _lastName;}

    void setEmail(string email){_email = email;}

    string getEmail(){return _email;}

    void setPhone(string phone){_phone = phone;}

    string getPhone(){return _phone;}
};

#endif // CLSPERSON_H
