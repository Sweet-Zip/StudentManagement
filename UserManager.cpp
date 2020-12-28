//
// Created by Unknown Device on 25-Dec-20.
//
#include "UserManager.h"
#include "menu.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;


void UserManager::UserManager::SaveAdmin() {
    fstream fp;
    fp.open("admin.txt", ios::out | ios::app);
    User* user = new User();
    user->CreateUser();
    fp.write((char*)user, sizeof(*user));
    fp.close();
    cout << "Admin saved" << endl;
}

void UserManager::UserManager::DisplayAdmin() { ////start without debug IDE has some problem
    cout << "\nDisplay all admin: " << endl; ////Got some problem
    User* user = new User();
    fstream fp;
    fp.open("admin.txt", ios::in);
    while (fp.read((char*)user, sizeof(User))) {
        user->DisplayUser();
        cout << "-------------------------------\n";
        cout << "All admins displayed" << endl;
        cout << "Press Enter to Continue";
    }
    cin.ignore();
    cin.get();
    fp.close();
}

void UserManager::UserManager::Search() {
    int id;
    cout<<"Enter admin id: ";
    cin>>id;
    cout << "Update admin detail: \n";
    fstream fp;
    User* user = new User();
    bool found = false;
    fp.open("admin.txt", ios::in | ios::out);
    while (fp.read((char*)user, sizeof(*user))) {
        if (user->getId() == id) {
            user->DisplayUser();
            found = true;
            break;
        }
    }
    fp.close();
    if (found == false)
        cout << "ID not found\n";
    else {
        cout <<endl<< "-------------------------------\n";
        cout << "Admin ID found!!!\n";
        cout << "-------------------------------\n";
    }
}

void UserManager::UserManager::UpdateAdmin() {
    int id;
    cout<<"Enter admin id: ";
    cin>>id;
    fstream fp;
    User* user = new User();
    bool found = false;
    fp.open("admin.txt", ios::in | ios::out);
    while (fp.read((char*)user, sizeof(*user))) {
        if (user->getId() == id) {
            user->DisplayUser();
            cout << "Update admin detail: \n";
            user->EditUser();
            int pos = -1 * static_cast<int>(sizeof(*user));
            fp.seekp(pos, ios::cur);
            fp.write((char*)user, sizeof(*user));
            found = true;
            break;
        }
    }
    fp.close();
    if (found == false)
        cout << "ID not found\n";
    else {
        cout << "Admin have been update\n";
        cout << "-------------------------------\n";
    }
}
void UserManager::UserManager::DeleteAdmin() {
    int id;
    cout<<"Enter admin ID: ";
    cin>>id;
    fstream fp;
    User* user = new User();
    fp.open("admin.txt", ios::in);
    fstream fp2;
    fp2.open("temp.txt", ios::out | ios::app);
    fp.seekg(0, ios::beg);
    while (fp.read((char*)user, sizeof(*user))) {
        if (user->getId() != id) {
            fp2.write((char*)user, sizeof(*user));
            break;
        }
    }
    cout << "Admin has been deleted\n";
    cout << "-------------------------------\n";
    cin.ignore();
    cin.get();
    fp2.close();
    fp.close();
    remove("admin.txt");
    rename("temp.txt", "admin.txt");
}
void UserManager::UserManager::sort() {


}

//class Options{
//private:
//public:
//    void options1();
//    option()
//};
//void Options::options1(){
//    char ch;
//    do {
//        system("cls");
//
//        cout<<endl<<endl<<"=================================Log-in================================="<<endl;
//        cin >> ch;
//        system("cls");
//
//        switch (ch) {
//            case '1':
//                UserManager::menu();
//                break;
//            default:
//                cout<<"\a";Options();
//        }
//    } while (ch!=3);
//}
//};