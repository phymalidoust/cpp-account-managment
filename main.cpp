#include <iostream>
#include "Classes/Messages/MessagesInfo.h"
#include "Classes/MainMenu/MainMenu.h"
#include "Classes/ExitQuit/ExitQuit.h"
#include "Classes/OpenNewAccount/OpenNewAccount.h"
#include "Classes/BalanceQuery/BalanceQuery.h"
#include "Classes/GetPath/GetPath.h"
#include "Classes/ParseDB/ParseDB.h"
#include "Classes/UserInfo/UserInfo.h"
#include <string>
#include <vector>
using namespace std;

bool stopFlag = false;
string nationalCode, firstName, lastName, accType, credit;
//vector<vector<string>> content;

int main() {


    MessagesInfo MessageObj;
    MessageObj.welcmWords();
    MainMenu MainMenuObj;
    MainMenuObj.headerMenu();
    unsigned int MainMenuChoice;
    OpenNewAccount newAcc;
    BalanceQuery balance;
    ParseDB parsedDB;
//    parsedDB.existDB();
//    parsedDB.readDB();

//UserInfo accountInfo;
//accountInfo.firstName = "Hasan";
//cout << accountInfo.firstName<<endl;



    do{
        MainMenuChoice = MainMenuObj.getChoice(0);
        switch (MainMenuChoice) {
            case 1:
                cout << "Enter your national code (5 digits): ";
                cin >> nationalCode;
                parsedDB.nationalCode = nationalCode;
                if(parsedDB.readDB()){
                    cout << parsedDB.firstName << " !\n";
                    cout << "You have already an account with us !\n";
                    cout << "Please chose other items than 01:\n";
                }else{
                    newAcc.nationalCode = nationalCode;
                    newAcc.writeToFile();}
                break;
            case 2:
                cout << "Enter your national code (5 digits): ";
                cin >> nationalCode;
                parsedDB.nationalCode = nationalCode;
                if(parsedDB.readDB()){
                    cout << parsedDB.firstName << " !\n";
                    cout << "The credit of your account is " << parsedDB.credit << " NOK.\n";
//                    cout << "Please chose other items than 01:\n";
                }else{
                    cout << "You don't have an account with us !\n";
                    cout << "Please first open an account !\n";
                }
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
