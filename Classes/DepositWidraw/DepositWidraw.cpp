#include "DepositWidraw.h"
#include <string>
#include <vector>
#include <iostream>
#include "../ParseDB/ParseDB.h"
using namespace std;


DepositWidraw::DepositWidraw() {}


void DepositWidraw::depositCredit() {
    ParseDB parsedDB;
//    parsedDB.existDB();

    cout << "Enter your national code (5 digits): ";
    cin >> nationalCode;
    parsedDB.nationalCode = nationalCode;

}

void DepositWidraw::widrawCredit() {

}