#include "ParseDB.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "../GetPath/GetPath.h"

using namespace std;

ParseDB::ParseDB() {}

bool ParseDB::existDB() {
    fstream myFile;
    GetPath address;
    string pathDB = address.dataBase();
    string line;

    myFile.open(pathDB, fstream::app);
    myFile.close();
    bool Flag = true;

    return Flag;
}

void ParseDB::readDB() {
    fstream myFile;
    GetPath address;
    string pathDB = address.dataBase();
    string line, word;
    bool Flag = false;

    vector<vector<string>> content;
    vector<string> row;

    myFile.open(pathDB, ios::in);
    if(!myFile){cout << "We couldn't open the file.\n";
        cout << "Please contact the developer at 'phymalidoust@gmail.com'.\n";}
    else{
        while(getline(myFile, line))
        {
            row.clear();

            stringstream str(line);

            while(getline(str, word, ','))
                row.push_back(word);
            content.push_back(row);
        }
    }
    myFile.close();


}



bool ParseDB::accountExist() {

    fstream myFile;
    GetPath address;
    string pathDB = address.dataBase();
    string line;
    bool Flag = false;

        for(int i=0;i<content.size();i++)
    {
        for(int j=0;j<content[i].size();j++)
        {
            if(content[0][j] == nationalCode){
                cout << "Hello " << content[1][j] << " !\n";
                cout << "You have already an account with us !\n";
                cout << "Please chose other items than 01:\n";
                Flag = true;
                break;
            }
        }
    }



    return Flag;
}

