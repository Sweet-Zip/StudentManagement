//
// Created by Unknown Device on 25-Dec-20.
//

#ifndef UNTITLED3_USERMANAGER_H
#define UNTITLED3_USERMANAGER_H
#include "User.h"
//#include "main.cpp"
#include <string>


using namespace std;

class UserManager : public User {
private:


public:
    void SaveUser();
    void DisplayAllUsers();
    void UpdateUser();
    void DeleteUser();
    void menu();
    void sort();
    bool IsLoggedIn();
    void log();
    void Search();

};

//void UserManager::DisplayAllUsers();
//void UserManager::Search();
//void UserManager::UpdateUser();
//void UserManager::DeleteUser();
//void UserManager::sort();
//void UserManager::menu();
//bool UserManager::IsLoggedIn();
//void UserManager::log();

#endif //UNTITLED3_USERMANAGER_H