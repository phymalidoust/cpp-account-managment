#include <iostream>
#include "ExitQuit.h"
#include "../mainMenu/MainMenu.h"
#include <string>
using namespace std;

ExitQuit::ExitQuit() {
    cout << "Exiting ! Are you sure?\n";
    string YesNo;
    char ans;
    MainMenu MainMenuObj;
    ans = MainMenuObj.getYesNo(YesNo);
    if(ans == 'y'){stopFlag = exitFunc();}
    else{
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