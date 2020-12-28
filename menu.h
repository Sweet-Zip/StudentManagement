//
// Created by Unknown Device on 28-Dec-20.
//

#ifndef MAIN_CPP_MENU_H
#define MAIN_CPP_MENU_H
class Menu : public User{
public:
    void Admin_menu();
    void Student_menu();
    bool AdminLoggedIn();
    bool StuLoggedIn();
    void log();
};
#endif //MAIN_CPP_MENU_H
