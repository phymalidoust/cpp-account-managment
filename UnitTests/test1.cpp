#include <iostream>
#include "../Classes/Messages/MessagesInfo.h"
#include "../Classes/MainMenu/MainMenu.h"
#include "../Classes/ExitQuit/ExitQuit.h"
#include "../Classes/OpenNewAccount/OpenNewAccount.h"
#include "../Classes/BalanceQuery/BalanceQuery.h"
#include "../Classes/GetPath/GetPath.h"
#include "../Classes/ParseDB/ParseDB.h"
#include "../Classes/UserInfo/UserInfo.h"
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
using namespace std;

template <typename T>
void passFailFunc(T expected, T actual, string unitName){
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



//int test(){
//    ExitQuit exitObj;
//    test1(true, exitObj.exitFunc(), "ExitQuit");
//    return 0;
//}

