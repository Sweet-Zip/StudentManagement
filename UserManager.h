//
// Created by Unknown Device on 25-Dec-20.
//

#ifndef UNTITLED3_USERMANAGER_H
#define UNTITLED3_USERMANAGER_H
#include "User.h"
#include "menu.h"
//#include "main.cpp"
#include <string>


using namespace std;

class UserManager : public User {
private:
public:
    void SaveAdmin();
    void DisplayAdmin();
    void UpdateAdmin();
    void DeleteAdmin();
    void sort();
    void Search();
};
#endif //UNTITLED3_USERMANAGER_H