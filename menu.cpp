//
// Created by Unknown Device on 28-Dec-20.
//

#include "User.h"
#include "UserManager.h"
#include "Students.h"
#include "menu.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

void Menu::Admin_menu() {
    int ch;
    UserManager admin;
    Student student;
    do {
        system("cls");

        cout<<endl<<endl<<"=================================Admin Menu================================="<<endl;
        cout << "\t1.Add Admin"<<endl;
        cout << "\t2.Show all Admin"<<endl;
        cout << "\t3.Edit Admin"<<endl;
        cout << "\t4.Search Admin"<<endl;
        cout << "\t5.Sort Admin ::: (not available)"<<endl;
        cout << "\t6.Delete Admin"<<endl;
        cout << "\t7.Add Student"<<endl;
        cout << "\t8.Show all Students"<<endl;
        cout << "\t9.Edit Student"<<endl;
        cout << "\t10.Search Student"<<endl;
        cout << "\t11.Sort Student"<<endl;
        cout << "\t12.Delete Student"<<endl;
        //cout << "\t13.Log out"<<endl;
        cout << "\t0.Exit"<<endl<<endl;
        cout << "\tPlease Enter Your Choice (0-12): ";
        cin >> ch;
        system("cls");

        switch (ch) {
            case 1: admin.SaveAdmin(); break;
            case 2: admin.DisplayAdmin(); break;
            case 3: admin.UpdateAdmin(); break;
            case 4: admin.Search(); break;
            case 5: admin.sort(); break;
            case 6: admin.DeleteAdmin(); break;
            case 7: student.SaveStudent(); break;
            case 8: student.DisplayStudents(); break;
            case 9: student.EditStudent(); break;
            case 10: student.SearchStudent(); break;
            case 11: student.SortStudent(); break;
            case 12: student.DeleteStudent(); break;
//              case 13: log(); break;
            case '0': exit(0);
            default:
                cout << "\a"; Menu();
        }
    } while (ch != 12);
}
void Menu::Student_menu() {
    int ch;
    Student student;
    do {
        system("cls");

        cout<<endl<<endl<<"=================================Student Menu================================="<<endl;

        cout << "\t1.Show all Students"<<endl;
        cout << "\t2.Search Student"<<endl;
        cout << "\t3.Sort Student"<<endl;
        //cout << "\4.Log out"<<endl;
        cout << "\t0.Exit"<<endl<<endl;
        cout << "\tPlease Enter Your Choice (0-12): ";
        cin >> ch;
        system("cls");

        switch (ch) {
            case 1: student.DisplayStudents(); break;
            case 2: student.SearchStudent(); break;
            case 3: student.SortStudent(); break;
//            case 4: log(); break;
            case '0': exit(0);
            default:
                cout << "\a"; Menu();
        }
    } while (ch != 4);
}

bool Menu::AdminLoggedIn() {

    const string a="admin";
    string login_username, login_password;
    cout << "\nEnter your username: ";
    cin >> login_username;
    cout << "Enter your password: ";
    cin >> login_password;

    ifstream read("admin.txt",ios::binary);
    (read >> username >> password);

    if (username == login_username && password == login_password || login_username == "admin" && login_password == "admin") {
        return true;
    } else {
        return false;

    }
}

bool Menu::StuLoggedIn() {

    //const string a="admin";
    string login_username, login_password;
    cout << "\nEnter your username: ";
    cin >> login_username;
    cout << "Enter your password: ";
    cin >> login_password;

    ifstream read("student.txt",ios::binary);
    (read >> username >> password);

    if (username == login_username && password == login_password || login_username == "student" && login_password == "student") {
        return true;
    } else {
        return false;

    }
}

void Menu::log(){
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

        ofstream read("admin.txt",ios::app|ios::binary);
        read << login_username <<' '<< login_password <<endl;
        system("cls");
        cout<<"\nRegistration Successful\n";
        //log();
        read.close();
        log();
    } else if (choice == 1) {
        bool status = AdminLoggedIn();

        if(!status)
        {
            cout << "Incorrect username or password" <<endl;
            system("PAUSE");
            return log();
        }
        else {
            cout << "\nLogin successful!\n" <<endl;
            system("PAUSE");
            return Admin_menu();
        }
    }
    if (choice !=2){
        cout<<"Wrong user name or password please try again";
        return log();
    }
}