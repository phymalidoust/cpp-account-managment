#ifndef PROJECT_PARSEDB_H
#define PROJECT_PARSEDB_H

#include <vector>
#include <string>
using namespace std;

class ParseDB {

public:
    ParseDB();
    bool readDB();
    string nationalCode;
    string firstName, lastName, accType, credit;

};


#endif
