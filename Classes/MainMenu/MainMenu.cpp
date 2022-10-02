#include <iostream>
#include "../Messages/MessagesInfo.h"
#include "MainMenu.h"
#include <string>
using namespace std;


MainMenu::MainMenu() {}

void MainMenu::headerMenu(){
    cout << "|-----------------------------------------------|\n";
    cout << "| MAIN MENU                                     |\n";
    cout << "| 01 - OPEN A NEW ACCOUNT                       |\n";
    cout << "| 02 - DEPOSIT AMOUNT                           |\n";
    cout << "| 03 - WITHDRAW AMOUNT                          |\n";
    cout << "| 04 - BALANCE ENQUIRY                          |\n";
    cout << "| 05 - ALL ACCOUNT HOLDER LIST                  |\n";
    cout << "| 06 - CLOSE AN ACCOUNT                         |\n";
    cout << "| 07 - MODIFY PERSONAL INFORMATION              |\n";
    cout << "| 08 - MODIFY ACCOUNT BALANCE                   |\n";
    cout << "| 09 - LOG OUT                                  |\n";
    cout << "|-----------------------------------------------|\n";
}

unsigned int MainMenu::getChoice(unsigned int choiceInt){

    string inputInt;
    unsigned int counter = 0;
    do {
        if(counter != 0){inputErrorInt();}
        cout << "Please enter your choice (1-9): ";
        cin >> inputInt;
        try{
            choiceInt = stoi(inputInt);
        }catch(...){
            counter++;
            continue;}
        counter++;
    }
    while (choiceInt <= 0 || choiceInt >= 10);

    return choiceInt;
}

void MainMenu::inputErrorInt() {
    cout << "Invalid input ! Only integers between 01 and 09 are valid.\n";
}


char MainMenu::getYesNo(string inputChar){

    char yes = 'y', no = 'n';
    char choiceChar;
    int n;
    unsigned int counter = 0;
    cout << "Exiting ! Are you sure?\n";
    do {
        if(counter != 0){inputErrorYesNO();}
        cout << "Please enter your choice (y/n): ";
        cin >> inputChar;
        n = inputChar.length();
        try{
            if(n != 1){throw 0;}
            choiceChar = inputChar[0];
        }catch(...){
            counter++;
            continue;}
        counter++;
    }
    while (!((choiceChar == 'y') || (choiceChar == 'n')));

    return choiceChar;

}

void MainMenu::inputErrorYesNO() {
    cout << "Invalid input ! Only yes or no is valid.\n";
}