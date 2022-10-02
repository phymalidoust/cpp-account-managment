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

bool ParseDB::readDB() {
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

    for(int i=0;i<content.size();i++)
    {
        for(int j=0;j<content[i].size();j++)
        {
//            cout << content[0][j] << " ";
            if(content[i][0] == nationalCode){
                firstName = content[i][1];
                lastName = content[i][2];
                accType = content[i][3];
                credit = content[i][4];
//                cout << i << " " << j << "\n";
//                cout << "First name is " << firstName << "\n";
                Flag = true;
                break;
            }
        }
    }

    return Flag;
}



bool ParseDB::accountExist() {

    cout << " accountExist ";
    string firstName;
    bool Flag = false;
    cout << "content.size() is " << content.size() << "\n";

        for(int i=0;i<content.size();i++)
    {
        for(int j=0;j<content[i].size();j++)
        {
            cout << content[0][j] << " ";
            if(content[0][j] == nationalCode){
                firstName = content[0][j];
                cout << "First name is " << firstName;
                Flag = true;
                break;
            }
        }
    }



    return Flag;
}

