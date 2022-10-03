#ifndef PROJECT_USERINFO_H
#define PROJECT_USERINFO_H
#include <string>
using namespace std;

class UserInfo {

public:
    UserInfo();
    string nationalCode, firstName, lastName, accType, credit;
    unsigned int userNo;
};


#endif
