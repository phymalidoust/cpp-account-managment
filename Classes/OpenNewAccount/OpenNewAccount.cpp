#include <iostream>
#include <fstream>
#include "OpenNewAccount.h"
#include "../GetPath/GetPath.h"
using namespace std;

OpenNewAccount::OpenNewAccount() {}

void OpenNewAccount::readFromFile() {
    fstream myFile;
    GetPath address;
    string pathDB = address.dataBase();
    string line;
    bool stopFlag = false;

    myFile.open(pathDB, fstream::app);
    myFile.close();
    myFile.open(pathDB, ios::in);
    if(!myFile){cout << "We couldn't open the file.\n";
                cout << "Please contact the developer at 'phymalidoust@gmail.com'.\n";}
    else{
        int counter;
        while(getline(myFile, line)){
            counter = line.find(',');
            if(line.substr(0,counter) == nationalCode){
                cout << "You have already an account with us !\n";
                cout << "Please chose other items than 01:\n";
                stopFlag = true;
                break;
            }
        }
        myFile.close();

         if(!stopFlag) {writeToFile();}


    }


}

void OpenNewAccount::writeToFile() {

    cout << "|-----------------------------------------------|\n";
    cout << "|          THANK YOU FOR CHOSING US!            |\n";
    cout << "|            Opening a new account              |\n";
    cout << "|-----------------------------------------------|\n";

    string firstName, lastName, accType, deposit;
    int accTypeInt;

    cout << "Enter your first name: ";
    cin >> firstName;
    cout << "Enter your last name: ";
    cin >> lastName;
    cout << "\t\t   Accout type  \n";
    cout << "\t\t 01. Short term \n";
    cout << "\t\t 02. Long term  \n";
    cout << "Enter your accout type (01/02): ";
    cin >> accTypeInt;
    if(accTypeInt == 1){accType = "ShortTerm";}else{accType = "LongTerm";}
    cout << "Enter the amount of deposit: ";
    cin >> deposit;



    GetPath address;
    string pathDB = address.dataBase();
    fstream myFile;
    myFile.open(pathDB, ios::app);
    if(!myFile){cout << "We couldn't open the file.\n";
        cout << "Please contact the developer at 'phymalidoust@gmail.com'.\n";}
    else {
        myFile << "\n" << nationalCode << "," << firstName << "," << lastName << "," << accType << "," <<deposit;
        cout << "|-----------------------------------------------|\n";
        cout << "|             CONGRADULATIONS!                  |\n";
        cout << "|      Your account has been created.           |\n";
        cout << "|-----------------------------------------------|\n";
    }



}