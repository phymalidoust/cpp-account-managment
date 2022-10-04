#include <iostream>
#include "../Messages/MessagesInfo.h"
#include "MainMenu.h"
#include <string>
using namespace std;


MainMenu::MainMenu() {}

void MainMenu::headerMenu(){

    MessagesInfo message;
    message.headerMenu();

}

unsigned int MainMenu::getChoice(unsigned int choiceInt){

    string inputInt;
    unsigned int counter = 0;
    do {
        if(counter != 0){inputErrorInt();}
        cout << "Please enter your choice (1-7): ";
        cin >> inputInt;
        try{
            choiceInt = stoi(inputInt);
        }catch(...){
            counter++;
            continue;}
        counter++;
    }
    while (choiceInt <= 0 || choiceInt >= 8);

    return choiceInt;
}

void MainMenu::inputErrorInt() {
    cout << "Invalid input ! Only integers between 01 and 08 are valid.\n";
}


char MainMenu::getYesNo(string inputChar){

    char yes = 'y', no = 'n';
    char choiceChar;
    int n;
    unsigned int counter = 0;

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