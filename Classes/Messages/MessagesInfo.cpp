#include <iostream>
#include "MessagesInfo.h"
#include "../mainMenu/MainMenu.h"
using namespace std;

MessagesInfo::MessagesInfo() {}

void MessagesInfo::welcmWords() {
    cout << "|-----------------------------------------------|\n";
    cout << "|                 WELCOM TO THE                 |\n";
    cout << "|           ACCOUNT MANAGMENT SYSTEM            |\n";
    cout << "|-----------------------------------------------|\n";
}

void MessagesInfo::openingAccount() {
    cout << "|-----------------------------------------------|\n";
    cout << "|          THANK YOU FOR CHOSING US!            |\n";
    cout << "|            Opening a new account              |\n";
    cout << "|-----------------------------------------------|\n";
}

void MessagesInfo::openingDone() {
    cout << "|-----------------------------------------------|\n";
    cout << "|             CONGRADULATIONS!                  |\n";
    cout << "|      Your account has been created.           |\n";
    cout << "|-----------------------------------------------|\n";
}
