#include <iostream>
#include "welcmWords.h"
#include "mainMenu.h"
#include <string>
using namespace std;


mainMenu::mainMenu() {

    cout << "| MAIN MENU                                     |\n";
    cout << "| 01 - OPEN A NEW ACCOUNT                       |\n";
    cout << "| 02 - DEPOSIT AMOUNT                           |\n";
    cout << "| 03 - WITHDRAW AMOUNT                          |\n";
    cout << "| 04 - BALANCE ENQUIRY                          |\n";
    cout << "| 05 - ALL ACCOUNT HOLDER LIST                  |\n";
    cout << "| 06 - CLOSE AN ACCOUNT                         |\n";
    cout << "| 07 - MODIFY PERSONAL INFORMATION              |\n";
    cout << "| 08 - MoDIFY ACCOUNT BALANCE                   |\n";
    cout << "| 09 - EXIT                                     |\n";
    cout << "|-----------------------------------------------|\n";


    cout << mainMenuChoice(0);
}

unsigned int mainMenu::mainMenuChoice(unsigned int choice){

    string input;
    unsigned int counter = 0;
    do {
        if(counter != 0){inputError();}
        cout << "Please enter your choice (1-9): ";
        cin >> input;
        try{
            choice = stoi(input);
        }catch(...){
            counter++;
            continue;}
        counter++;
    }
    while (choice <= 0 || choice >= 10);

    return choice;
}

void mainMenu::inputError() {
    cout << "Invalid input ! Only integers between 01 and 09 are valid.\n";
}