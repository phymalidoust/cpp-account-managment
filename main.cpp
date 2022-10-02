#include <iostream>
#include "Classes/Messages/MessagesInfo.h"
#include "Classes/MainMenu/MainMenu.h"
#include "Classes/ExitQuit/ExitQuit.h"
#include "Classes/OpenNewAccount/OpenNewAccount.h"
#include "Classes/BalanceQuery/BalanceQuery.h"
#include "Classes/GetPath/GetPath.h"
#include <string>
using namespace std;

int main() {

    MessagesInfo MessageObj;
    MessageObj.welcmWords();
    MainMenu MainMenuObj;
    MainMenuObj.headerMenu();
    unsigned int MainMenuChoice;
    bool stopFlag = false;
    string nationalCode;
    OpenNewAccount newAcc;
    BalanceQuery balance;


    do{
        MainMenuChoice = MainMenuObj.getChoice(0);
        switch (MainMenuChoice) {
            case 1:
                cout << "Enter your national code (5 digits): ";
                cin >> nationalCode;
                newAcc.nationalCode = nationalCode;
                newAcc.readFromFile();
                break;
            case 2:
                cout << "Enter your national code (5 digits): ";
                cin >> nationalCode;
                balance.nationalCode = nationalCode;
                balance.checkCredit();
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
                ExitQuit Ex;
                stopFlag = Ex.stopFlag;
//                cout << stopFlag<<endl;
        }

    }while (!stopFlag);




//    GetPath db;
//    cout << db.dataBase();

//    string input;
//    cin >> input;
//    cout << stoi(input);



    return 0;
}
