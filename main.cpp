#include <iostream>
#include "Classes/Messages/MessagesInfo.h"
#include "Classes/MainMenu/MainMenu.h"
#include "Classes/ExitQuit/ExitQuit.h"
#include "Classes/OpenNewAccount/OpenNewAccount.h"
#include "Classes/BalanceQuery/BalanceQuery.h"
#include "Classes/GetPath/GetPath.h"
#include "Classes/ParseDB/ParseDB.h"
#include "Classes/UserInfo/UserInfo.h"
#include "Classes/UnitTests/UnitTests.h"
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
using namespace std;

void writeToDB(ParseDB);
void deleteUser(ParseDB);
void accountInfo(ParseDB);
void tests1();



int main() {

tests1();
    cout << "\nPress enter to return to the main menu.\n";
    system("read");


    MessagesInfo MessageObj;
    MessageObj.welcmWords();
    MainMenu MainMenuObj;

    unsigned int MainMenuChoice;
    OpenNewAccount newAcc;
    BalanceQuery balance;
    ParseDB parsedDB;
    string YesNo;
    string temp;
    bool stopFlag = false;
    string nationalCode;
    string firstName;
    string lastName;
    string accType;
    string credit;


    do{
        MainMenuObj.headerMenu();
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
                    cout << "|-----------------------------------------------\n";
                    cout << "| " << parsedDB.firstName << " !\n";
                    cout <<"| " <<  "The credit of your account is " << parsedDB.credit << " NOK.\n";
                    cout << "|-----------------------------------------------\n";
                    cout << "\nPress enter to return to the main menu.\n";
                    system("read");
                }else{
                    MessageObj.noAccountFound();
                }
                break;
            case 3:
                cout << "Enter your national code (5 digits): ";
                cin >> nationalCode;
                parsedDB.nationalCode = nationalCode;
                if(parsedDB.readDB()){
                    cout << "|-----------------------------------------------\n";
                    cout << "| " << parsedDB.firstName << " !\n";
                    cout << "| " << "The credit of your account is " << parsedDB.credit << " NOK.\n";
                    cout << "| " << "How much do you like to add (NOK)? ";
                    cin >> temp;
                    parsedDB.credit = to_string((stoi(temp) + stoi(parsedDB.credit)));
                    writeToDB(parsedDB);
                    cout << "| " << "The credit of your account was updated to " << parsedDB.credit << " NOK.\n";
                    cout << "|-----------------------------------------------\n";
                    cout << "\nPress enter to return to the main menu.\n";
                    system("read");
                }else{
                    MessageObj.noAccountFound();
                }
                break;
            case 4:
                cout << "Enter your national code (5 digits): ";
                cin >> nationalCode;
                parsedDB.nationalCode = nationalCode;
                if(parsedDB.readDB()){
                    cout << "|-----------------------------------------------\n";
                    cout << "| " << parsedDB.firstName << " !\n";
                    cout << "| " << "The credit of your account is " << parsedDB.credit << " NOK.\n";
                    cout << "| " << "How much do you like to withdraw (NOK)? ";
                    cin >> temp;
                    parsedDB.credit = to_string((-stoi(temp) + stoi(parsedDB.credit)));
                    writeToDB(parsedDB);
                    cout << "| " << "The credit of your account was updated to " << parsedDB.credit << " NOK.\n";
                    cout << "|-----------------------------------------------\n";
                    cout << "\nPress enter to return to the main menu.\n";
                    system("read");
                }else{
                    MessageObj.noAccountFound();
                }
                break;
            case 5:
                cout << "Enter your national code (5 digits): ";
                cin >> nationalCode;
                parsedDB.nationalCode = nationalCode;
                if(parsedDB.readDB()){
                    accountInfo(parsedDB);
                    cout << "Which item are going to modify (1-3)? ";
                    cin >> temp;

                        switch (stoi(temp)) {
                            case 1:
                                cout << "First name: ";
                                cin >> parsedDB.firstName;
                                break;
                            case 2:
                                cout << "Last name: ";
                                cin >> parsedDB.lastName;
                                break;
                            case 3:
                                cout << "Account type: ";
                                cin >> parsedDB.accType;
                                break;
                        }
                    writeToDB(parsedDB);
                    cout << "| " << "Your account information was updated.\n";
                    accountInfo(parsedDB);
//                    cout << "|-----------------------------------------------\n";
                    cout << "\nPress enter to return to the main menu.\n";
                    system("read");
                }else{
                    MessageObj.noAccountFound();
                }
                break;
            case 6:

                cout << "Enter your national code (5 digits): ";
                cin >> nationalCode;
                parsedDB.nationalCode = nationalCode;
                if (parsedDB.readDB())
                {
                    accountInfo(parsedDB);                    cout << "CLOSING YOUR ACCOUNT !\n";
                    cout << "Are you sure (y/n)? \n";
                    char ans;
                    ans = MainMenuObj.getYesNo(YesNo);
                    if(ans == 'y')
                    {
                        deleteUser(parsedDB);
                        cout << "| " << "Your account was successfully closed. \n";
                        cout << "|-----------------------------------------------\n";
                        cout << "\nPress enter to return to the main menu.\n";
                        system("read");
                    }
                }
                else
                {
                    MessageObj.noAccountFound();
                }
                break;
            case 7:
                ExitQuit Ex;
                stopFlag = Ex.stopFlag;
        }

    }while (!stopFlag);




    return 0;
}


void writeToDB(ParseDB parsedDB){
    UserInfo accInfo;
    GetPath address;
    string pathDB = address.userInfoBinary();
    fstream myFile;

    myFile.open(pathDB, ios::binary|ios::in|ios::out);
    if(!myFile){cout << "We couldn't open the file.\n";
        cout << "Please contact the developer at 'phymalidoust@gmail.com'.\n";}
    else{
        while(myFile.read((char *) &accInfo, sizeof(UserInfo))){
            if(parsedDB.nationalCode == accInfo.nationalCode){
                accInfo.firstName = parsedDB.firstName;
                accInfo.lastName = parsedDB.lastName;
                accInfo.accType = parsedDB.accType;
                accInfo.credit = parsedDB.credit;

                int pos=(-1)*sizeof(UserInfo);
                myFile.seekp(pos,ios::cur);
                myFile.write((char *) &accInfo, sizeof(UserInfo));
                break;
            }
        }
    }
    myFile.close();

}

void deleteUser(ParseDB parsedDB){
    UserInfo accInfo;
    GetPath address;
    string pathDB = address.userInfoBinary();
    fstream myFile;
    string tempDB = address.tempDB();
    fstream tempFile;

    myFile.open(pathDB, ios::binary | ios::in);
    if(!myFile){cout << "We couldn't open main DB.\n";
        cout << "Please contact the developer at 'phymalidoust@gmail.com'.\n";}
    else{
        tempFile.open(tempDB, ios::binary | ios::out | ios::app);
        tempFile.seekg(0,ios::beg);
        if(!tempFile){cout << "We couldn't open temp DB.\n";
            cout << "Please contact the developer at 'phymalidoust@gmail.com'.\n";}
        else{
            while(myFile.read((char *) &accInfo, sizeof(UserInfo))) {
                if (!(parsedDB.nationalCode == accInfo.nationalCode))
                {
                    tempFile.write((char *) &accInfo, sizeof(UserInfo));
                }
            }
        }
    }
    myFile.close();
    tempFile.close();
    remove("../DataBase/Accounts.dat");
    rename("../DataBase/tempDB.dat","../DataBase/Accounts.dat");

}

void accountInfo(ParseDB parsedDB) {
    cout << "|-----------------------------------------------|\n";
    cout << "| YOUR ACCOUNT INFORMATION                      \n";
    cout << "| 01 - First name: "<< parsedDB.firstName << "  \n";
    cout << "| 02 - Last name: "<< parsedDB.lastName << "    \n";
    cout << "| 03 - Account type: "<< parsedDB.accType << "  \n";
    cout << "|-----------------------------------------------|\n";
}

void tests1(){

    UnitTests unitTestsObj;

    ExitQuit exitObj;
    unitTestsObj.passFailFunc(true, exitObj.exitFunc(), "ExitQuit");


}