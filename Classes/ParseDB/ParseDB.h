#ifndef PROJECT_PARSEDB_H
#define PROJECT_PARSEDB_H

#include <vector>
#include <string>
using namespace std;

class ParseDB {

public:
    ParseDB();
    void readDB();
    bool existDB();
    bool accountExist();
    string nationalCode;
    vector<vector<string>> content;

};


#endif
