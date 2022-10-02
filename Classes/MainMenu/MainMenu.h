#ifndef PROJECT_MAINMENU_H
#define PROJECT_MAINMENU_H

#include <string>
using namespace std;

class MainMenu {

public:
    MainMenu();
    void headerMenu();
    unsigned int getChoice(unsigned int choice = 0);
    void inputErrorInt();
    char getYesNo(string ans = "n");
    void inputErrorYesNO();

};


#endif
