#include <iostream>
#include "ExitQuit.h"
#include "../mainMenu/MainMenu.h"
#include <string>
using namespace std;

ExitQuit::ExitQuit() {
    string YesNo;
    char ans;
    MainMenu MainMenuObj;
    ans = MainMenuObj.getYesNo(YesNo);
//    cout << "ans is " << ans;
    if(ans == 'y'){stopFlag = exitFunc();}
    else{
//    system("clear");
    MainMenuObj.headerMenu();
    }
}

 bool ExitQuit::exitFunc() {
    cout << "\n";
    cout << "Loging out ... done.\n";
    cout << "Have a nice day!\n";
    cout << "\n";
    return true;
}

bool ExitQuit::exitFlag() {
    return true;
}