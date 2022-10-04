#include "ParseDB.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "../GetPath/GetPath.h"
#include "../UserInfo/UserInfo.h"

using namespace std;

ParseDB::ParseDB() {}



bool ParseDB::readDB() {

//    string firstName, lastName, accType, credit;
    bool Flag = false;
    unsigned int userNo = 0;

    UserInfo accInfo;
    GetPath address;
    string pathDB = address.userInfoBinary();
    fstream myFile;

    myFile.open(pathDB, ios::binary | ios::in);
    if(!myFile){cout << "We couldn't open the file.\n";
        cout << "Please contact the developer at 'phymalidoust@gmail.com'.\n";}
    else{
        while(myFile.read((char *) &accInfo, sizeof(UserInfo))){
            if(nationalCode == accInfo.nationalCode){
                Flag = true;
                firstName = accInfo.firstName;
                lastName = accInfo.lastName;
                accType = accInfo.accType;
                credit = accInfo.credit;
                break;
            }
//            userNo++;
        }
        }
    myFile.close();
    return Flag;
    }





