#include "GetPath.h"
#include <string>
using namespace std;

GetPath::GetPath() {}


string GetPath::dataBase(){
    string path;
    path = "../DataBase/DataBase.csv";
    return path;
}

string GetPath::userInfoBinary(){
    string path;
    path = "../DataBase/Accounts.dat";
    return path;
}
