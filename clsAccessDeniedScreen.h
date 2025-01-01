#ifndef CLSACCESSDENIEDSCREEN_H
#define CLSACCESSDENIEDSCREEN_H
#include <iostream>
using namespace std;
#include "clsUtil.h"
#include"clsScreen.h"

class clsAccessDeniedScreen : clsScreen
{
public:

    static void showAccessDeniedScreen(){
        _drawScreenHeader(clsUtil::tabs(5) + "Access Denied! Contact Your Admin.");
    }
};

#endif // CLSACCESSDENIEDSCREEN_H
