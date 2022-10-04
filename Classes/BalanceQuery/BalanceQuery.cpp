#include <iostream>
#include <fstream>
#include "BalanceQuery.h"
#include "../Messages/MessagesInfo.h"
#include "../GetPath/GetPath.h"
using namespace std;

BalanceQuery::BalanceQuery() {}


void BalanceQuery::checkCredit() {
    MessagesInfo checkingMessage;
    checkingMessage.checkingcredit();

    fstream myFile;
    GetPath address;
    string pathDB = address.dataBase();
    string line;
    bool Flag = false;
    int commaPlace[4];

    myFile.open(pathDB, fstream::app);
    myFile.close();
    myFile.open(pathDB, ios::in);
    if(!myFile){checkingMessage.notOpenedFile();}
    else{
        int counter, len, i;
        while(getline(myFile, line)){
            counter = line.find(',');
            if(line.substr(0,counter) == nationalCode){
                counter = line.rfind(',');
                len = line.length();

                counter = -1;
                i = 0;
                do{
                    counter = line.find(',');
                    commaPlace[i] = line.substr(counter++,len).find(',');
                    i++;

                }while(counter =! len);

                cout << "Hello" << line.substr(counter++,len).find(',');
                cout << "The balance of your account is " << line.substr(counter,len) << " NOK.\n";
                Flag = true;
                break;
            }
        }
        myFile.close();

        if(!Flag) {checkingMessage.notOpenedFile();}

    }


}

