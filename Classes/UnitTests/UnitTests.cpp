#include <iostream>
#include "../Messages/MessagesInfo.h"
#include "../MainMenu/MainMenu.h"
#include "../ExitQuit/ExitQuit.h"
#include "../OpenNewAccount/OpenNewAccount.h"
#include "../BalanceQuery/BalanceQuery.h"
#include "../GetPath/GetPath.h"
#include "../ParseDB/ParseDB.h"
#include "../UserInfo/UserInfo.h"
#include "UnitTests.h"
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
using namespace std;

UnitTests::UnitTests(){};

//template <class T>
void UnitTests::passFailFunc(bool expected, bool actual, string unitName){
    if(expected == actual)
    {
        cout << "Unit test " << unitName << " PASSED!\n";
    }
    else
    {
        cout << "Unit test " << unitName << " FAILED!\n";
        cout << "Expected result: " << expected << " \n";
        cout << "Actual result: " << actual << " \n";
    }
}


