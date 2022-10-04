#include <iostream>
#include <string>
#include <vector>
#include "UnitTests.h"
using namespace std;

UnitTests::UnitTests(){};

//template <class T>
void UnitTests::passFailFunc(bool expected, bool actual, string unitName){
    if(expected == actual)
    {
        cout << "Unit test " << unitName << " PASSED!\n";
    }
    else
    {
        cout << "Unit test " << unitName << " FAILED!\n";
        cout << "Expected result: " << expected << " \n";
        cout << "Actual result: " << actual << " \n";
    }
}


