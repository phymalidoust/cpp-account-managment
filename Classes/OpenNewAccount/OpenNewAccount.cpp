#include <iostream>
#include <fstream>
#include "OpenNewAccount.h"
#include "../GetPath/GetPath.h"
#include "../Messages/MessagesInfo.h"
#include "../UserInfo/UserInfo.h"
using namespace std;

OpenNewAccount::OpenNewAccount() {}

void OpenNewAccount::writeToFile() {

    MessagesInfo MessageObj;
    MessageObj.openingAccount();


    string firstName, lastName, accType, deposit;
    int accTypeInt;

    cout << "Enter your first name: ";
    cin >> firstName;
    cout << "Enter your last name: ";
    cin >> lastName;
    cout << "\t\t\t   Accout type  \n";
    cout << "\t\t 01. Short term (1 month) \n";
    cout << "\t\t 02. Long term  (more than 1 year) \n";
    cout << "Enter your accout type (01/02): ";
    cin >> accTypeInt;
    if(accTypeInt == 1){accType = "ShortTerm";}else{accType = "LongTerm";}
    cout << "Enter the amount of deposit (in NOK): ";
    cin >> deposit;


    unsigned int userNo = 0;
    UserInfo accInfo;
    GetPath address;
    string pathDB = address.userInfoBinary();
    fstream myFile;
    myFile.open(pathDB, ios::binary | ios::out | ios::app);
    if(!myFile){MessageObj.notOpenedFile();}
    else {
        accInfo.nationalCode = nationalCode;
        accInfo.firstName = firstName;
        accInfo.lastName = lastName;
        accInfo.accType = accType;
        accInfo.credit = deposit;
        accInfo.userNo = userNo;
        myFile.write((char *) &accInfo, sizeof(UserInfo));
        MessageObj.openingDone();
    }

    myFile.close();

}