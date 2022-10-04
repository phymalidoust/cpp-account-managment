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

void MessagesInfo::headerMenu() {
    cout << "|-----------------------------------------------|\n";
    cout << "| MAIN MENU                                     |\n";
    cout << "| 01 - OPEN NEW ACCOUNT                         |\n";
    cout << "| 02 - BALANCE ENQUIRY                          |\n";
    cout << "| 03 - DEPOSIT AMOUNT                           |\n";
    cout << "| 04 - WITHDRAW AMOUNT                          |\n";
    cout << "| 05 - MODIFY ACCOUNT INFORMATION               |\n";
    cout << "| 06 - CLOSE AN ACCOUNT                         |\n";
    cout << "| 07 - LOG OUT                                  |\n";
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

void MessagesInfo::checkingcredit() {
    cout << "|-----------------------------------------------|\n";
    cout << "|          Checking you account balance         |\n";
    cout << "|-----------------------------------------------|\n";
}