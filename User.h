//
// Created by Unknown Device on 25-Dec-20.
//

#ifndef UNTITLED3_USER_H
#define UNTITLED3_USER_H

#include <string>
using namespace std;
class User {
private:
    int id;
    int phone;
    string dob;
    string address;
    string role;
//    bool IsLoggedIn();
//    void log();
    bool is_valid_email(const string& email);
    bool is_valid_number(const string& number);
    bool is_valid_name(const string& name);
    bool is_valid_password(string& password);

protected:
    string username;
    string password;
public:
    User();

    User(int id, int phone,string username, string password,string dob,string address, string role);
    int getId();
    void setId(int id);
    int getPhone();
    void setPhone(int phone);
    string getUsername();
    string getPassword();
    void setPassword(string password);
    string getDob();
    void setDob(string dob);
    string getAddress();
    void setAddress(string address);
    string getRole();
    void setRole(string role);
    void CreateUser();
    void EditUser();
    void DisplayUser();

    void setUsername(string basicString);
};

#endif //UNTITLED3_USER_H