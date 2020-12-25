//
// Created by Unknown Device on 25-Dec-20.
//

#include <regex>
#include "User.h"
#include <string>
#include <iostream>

using namespace std;

    bool User::is_valid_email(const string& email){

        const regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
        return regex_match(email,pattern);

    }

    bool User::is_valid_number(const string& number) {
        for (const char c : number) {
            if (!isdigit(c))
                return false;
        }
        return true;
    }

    bool User::is_valid_name(const string& name) {
        for (const char c : name) {
            if (!isalpha(c) && !isspace(c))
                return false;
        }

        return true;
    }

    bool User::is_valid_password(string& password) {
        bool hasLower = false;
        bool hasUpper = false;
        bool hasDigit = false;

        for (const char c : password) {
            if (islower(c)){
                hasLower = true;
            }
            if (isupper(c)){
                hasUpper = true;
            }
            if (isdigit(c)){
                hasDigit = true;
            }
        }

        if ( hasUpper && hasDigit && hasLower && (password.length() >= 6)){
            cout << "Your password is Strong and succeeded" << endl;
        }
        else if ((hasLower || hasUpper) && hasDigit && (password.length() >=6)){
            cout << "Your password is Good and succeeded" << endl;
        }
        else{
            cout << "too Weak" << endl;
            return false;
        }
        return true;
    }


User::User() {
//        id = 0;           ///1
//        phone = 0;        ///2
//        username = "";    ///3
//        password = "";    ///4
//        dob = "";         ///5
//        address = "";     ///6
//        role = "";        ///7
    }
User:: User (int id, int phone,string username, string password,string dob,string address, string role) {

        this->id = id;
        this->phone=phone;
        this->username = username;
        this->password = password;
        this->dob=dob;
        this->address=address;
        this->role = role;
    }
    int User::getId(){
        return id;
    }
    void User::setId(int id){
        this->id=id;
    }
    int User::getPhone(){
        return phone;
    }
    void User::setPhone(int phone){
        this->phone=phone;
    }
    string User::getUsername(){
        return username;
    }
void User::setUsername(string basicString) {
        while (!is_valid_name(username)) {
            cout << "Enter your name again: ";
            getline(cin, username);
            cin.ignore();

            this->username = username;
        }
    }
    string User:: getPassword(){
        return password;
    }
    void User::setPassword(string password){
        while (!is_valid_password(password)){
            cout << "Please enter your password again: ";
            getline(cin, password);
            cin.ignore();
        }
        this->password=password;

    }
    string User::getDob(){
        return dob;
    }
    void User::setDob(string dob){
        this->dob=dob;
    }
    string User::getAddress(){
        return address;
    }
    void User::setAddress(string address){
        this->address=address;
    }
    string User::getRole(){
        return role;
    }
    void User::setRole(string role){
        this->role=role;
    }

    void User::CreateUser() {

        while (true)
        {
            cout<<"User ID: ";
            cin>>id;

            if (cin.fail())
            {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }

            if (id <= 0){
                continue;
            }

            break;
        }

        cout<<"Username: ";
        cin.ignore();
        getline(cin,username);
        setUsername(username);

        cout<<"Password: ";
        getline(cin,password);
        setPassword(password);

        cout<<"Phone number: ";
        cin>>phone;

        cout<<"Date of Birth: ";
        cin.ignore();
        getline(cin,dob);

        cout<<"Address: ";
        cin.ignore();
        getline(cin,address);

        cout<<"Role: ";
        cin.ignore();
        getline(cin,role);

    }
void User::EditUser() {

    cout<<"Username: ";
    cin.ignore();
    getline(cin,username);
    setUsername(username);

    cout<<"Password: ";
    getline(cin,password);
    setPassword(password);

    cout<<"Phone number: ";
    cin>>phone;

    cout<<"Date of Birth: ";
    cin.ignore();
    getline(cin,dob);

    cout<<"Address: ";
    cin.ignore();
    getline(cin,address);

    cout<<"Role: ";
    cin.ignore();
    getline(cin,role);

}

    void User::DisplayUser(){
        cout<<"ID: "<<id<<endl;
        cout<<"Username: "<<username<<endl;
        cout<<"Password: "<<password<<endl;
        cout<<"Date of Birth: "<<dob<<endl;
        cout<<"Phone Number: "<<phone<<endl;
        cout<<"Address: "<<address<<endl;
        cout<<"Role: "<<role<<endl;
    }
