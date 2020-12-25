//
// Created by Unknown Device on 25-Dec-20.
//
#include "UserManager.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;


void UserManager::UserManager::SaveUser() {
    fstream fp;
    fp.open("user.txt", ios::out | ios::app);
    User* user = new User();
    user->CreateUser();;
    fp.write((char*)user, sizeof(*user));
    fp.close();
    cout << "User saved" << endl;
}

void UserManager::UserManager::DisplayAllUsers() { ////start without debug IDE has some problem
    ////cout << "\nDisplay all users: " << endl; ////Got some problem
    User* user = new User();
    fstream fp;
    fp.open("user.txt", ios::in);
    while (fp.read((char*)user, sizeof(User))) {
        user->DisplayUser();
        cout << "-------------------------------\n";
        cout << "All user displayed" << endl;
        cout << "Press Enter to Continue";
    }
    cin.ignore();
    cin.get();
    fp.close();
}

void UserManager::UserManager::Search() {
    int id;
    cout<<"Enter user id: ";
    cin>>id;
    cout << "Update user detail: \n";
    fstream fp;
    User* user = new User();
    bool found = false;
    fp.open("user.txt", ios::in | ios::out);
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
        cout << "User found!!!\n";
        cout << "-------------------------------\n";
    }
}

void UserManager::UserManager::UpdateUser() {
    int id;
    cout<<"Enter user id: ";
    cin>>id;
    fstream fp;
    User* user = new User();
    bool found = false;
    fp.open("user.txt", ios::in | ios::out);
    while (fp.read((char*)user, sizeof(*user))) {
        if (user->getId() == id) {
            user->DisplayUser();
            cout << "Update user detail: \n";
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
        cout << "User have been update\n";
        cout << "-------------------------------\n";
    }
}
void UserManager::UserManager::DeleteUser() {
    int id;
    cout<<"Enter user ID: ";
    cin>>id;
    fstream fp;
    User* user = new User();
    fp.open("user.txt", ios::in);
    fstream fp2;
    fp2.open("temp.txt", ios::out | ios::app);
    fp.seekg(0, ios::beg);
    while (fp.read((char*)user, sizeof(*user))) {
        if (user->getId() != id) {
            fp2.write((char*)user, sizeof(*user));
            break;
        }
    }
    cout << "User has been deleted\n";
    cout << "-------------------------------\n";
    cin.ignore();
    cin.get();
    fp2.close();
    fp.close();
    remove("user.txt");
    rename("temp.txt", "user.txt");
}
void UserManager::UserManager::sort() {


}

void UserManager::UserManager::menu() {
    char ch;
    do {
        system("cls");

        cout<<endl<<endl<<"=================================Main Menu================================="<<endl;
        cout << "\t1.Add User"<<endl;
        cout << "\t2.Show all User"<<endl;
        cout << "\t3.Edit User"<<endl;
        cout << "\t4.Search User"<<endl;
        cout << "\t5.Sort User ::: (not available)"<<endl;
        cout << "\t6.Delete User"<<endl;
        //cout << "\t7.Log out"<<endl;
        cout << "\t0.Exit"<<endl<<endl;
        cout << "\tPlease Enter Your Choice (0-6): ";
        cin >> ch;
        system("cls");

        switch (ch) {
            case '1': SaveUser(); break;
            case '2': DisplayAllUsers(); break;
            case '3': UpdateUser(); break;
            case '4': Search(); break;
            case '5': sort(); break;
            case '6': DeleteUser(); break;
            //case '7': log(); break;
            case '0': exit(0);
            default:
                cout << "\a"; menu();

        }
    } while (ch != 7);
}

//class Student{
//private:
//public:
//    void SDisplayAllUser();
//    void Smenu();
//};
//void DisplayAllUser();
//void Student::SDisplayAllUser() {
//    cout << "Display all users: " << endl;
//    User* user = new User();
//    fstream fp;
//    fp.open("user.txt", ios::in);
////    fp.open("username.txt", ios::in);
////    fp.open("pass.txt", ios::in);
//    while (fp.read((char*)user, sizeof(User))) {
//        user->DisplayUser();
//        cout << "-------------------------------\n";
//    }
//    fp.close();
//    cout << "All user displayed" << endl;
//}
//void Student::Smenu() {
//    char ch;
//    do {
//        system("cls");
//
//        cout<<endl<<endl<<"=================================Main Menu================================="<<endl;
//
//    cout<<"1. Display all Students "<<endl;
//    cout<<"2. Search all Student (not available) "<<endl;
//    cout<<"3. Sort Students (not available)"<<endl;
//        cin >> ch;
//        system("cls");
//
//        switch (ch) {
//            case '1':
//                SDisplayAllUser();
//                break;
//            default:
//                cout<<"\a";Smenu();
//        }
//    } while (ch!=3);
//}

bool UserManager::UserManager::IsLoggedIn() {
    UserManager u;
    const string a="admin";
    string login_username, login_password;
    cout << "\nEnter your username: ";
    cin >> login_username;
    cout << "Enter your password: ";
    cin >> login_password;

    ifstream read("user.txt",ios::binary);
    (read >> u.username >> u.password);

    if (u.username == login_username && u.password == login_password) {
        return true;
    } else {
        return false;

    }
}
void UserManager::UserManager::log(){
    int choice;
    cout << "\n*************Welcome**********:"<<endl;
    cout << "\n1: Login\n2: Register\n\nEnter your choice: ";
    cin >> choice;

    if(choice == 2) {
        string login_username, login_password;

        cout << "\nSelect a username: ";
        cin >> login_username;
        cout << "Select a password: ";
        cin >> login_password;
        cout <<endl;

        ofstream read("user.txt",ios::app|ios::binary);
        read << login_username <<' '<< login_password <<endl;
        system("cls");
        cout<<"\nRegistration Successful\n";
        //main();
        read.close();
    } else if (choice == 1) {
        bool status = IsLoggedIn();

        if(!status)
        {
            cout << "Incorrect username or password" <<endl;
            system("PAUSE");
            return log();
        }
        else {
            cout << "\nLogin successful!\n" <<endl;
            system("PAUSE");
            return menu();
        }
    }
    if (choice !=2){
        cout<<"Wrong user name or password please try again";
        return log();
    }
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