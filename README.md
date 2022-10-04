# Account managment system

This system allows the user to create a user account 
and later modify personal and credit information.  
A menu list appears with multiple options. The user 
can choose what to do when the main menu pops up. 
The options are as follows:
- [x]  **01** OPEN NEW ACCOUNT
- [x]  **02** BALANCE ENQUIRY
- [x]  **03** DEPOSIT AMOUNT
- [x]  **04** WITHDRAW AMOUNT 
- [x]  **05** MODIFY ACCOUNT INFORMATION
- [x]  **06** CLOSE ACCOUNT
- [x]  **07** LOG OUT



The project was carried out by Mohammad Alidoust.


### Core files and their tasks
```buildoutcfg
The components of the source code. 
MAIN 
01. 'main.cpp': Handeling requests
CLASSES
02. 'MainMenu': Creating main menu, Getting user response
03. 'GetPath' : Returning requested paths
04. 'Messages': Returning messages
05. 'OpenNewAccount': Opens new accounts
06. 'ParseDB': Opening and screening data base
07. 'BalanceQuery': Returning credit requests
08. 'UserInfo': Storing user information
09. 'DataBase': Storing dataBases
10. 'ExitQuit': Quiting the program
```
### How to run it
```c++20
The C++20 compiler is used to compile and debug the code.
The following command can be used to run the code
 
g++ -o main.exe main.cpp; ./main.exe

Note. This command is not universal.
One may need adjustments, depending on your OS.

```