#ifndef PROJECT_OPENNEWACCOUNT_H
#define PROJECT_OPENNEWACCOUNT_H
#include <string>
using namespace std;

class OpenNewAccount {

public:
    OpenNewAccount();
    void readFromFile();
    void writeToFile();
    string nationalCode;
};

#endif
