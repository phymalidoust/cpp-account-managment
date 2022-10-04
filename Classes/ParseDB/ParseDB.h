#ifndef PROJECT_PARSEDB_H
#define PROJECT_PARSEDB_H

#include <vector>
#include <string>
using namespace std;

class ParseDB {

public:
    ParseDB();
    bool readDB();
//    bool existDB();
//    bool accountExist();
    string nationalCode;
//    vector<vector<string>> content;
    string firstName, lastName, accType, credit;
//    unsigned int userNo;
//    bool writeToDB();

};


#endif
