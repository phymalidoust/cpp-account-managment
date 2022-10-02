#include <iostream>
#include "ExitQuit.h"
#include "../mainMenu/MainMenu.h"
#include <string>
#include <stdlib.h>
using namespace std;

ExitQuit::ExitQuit() {
    string YesNo;
    char ans;
    MainMenu MainMenuObj;
    ans = MainMenuObj.getYesNo(YesNo);
//    cout << "ans is " << ans;
    if(ans == 'y'){exitFunc();}
    else{
//    system("clear");
    MainMenuObj.headerMenu();
    }
}

void ExitQuit::exitFunc() {
    cout << "\n";
    cout << "Loging out ... done.\n";
    cout << "Have a nice day!\n";
    cout << "\n";
    exitFlag();
}

bool ExitQuit::exitFlag() {
    return true;
}