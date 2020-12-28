//
// Created by Unknown Device on 28-Dec-20.
//
#include "UserManager.h"
#include "menu.h"
#include "Students.h"
#include <string>
#include <iostream>
#include <fstream>
void Student::SaveStudent() {
    fstream fp;
    fp.open("students.txt", ios::out | ios::app);
    User* user = new User();
    user->CreateUser();;
    fp.write((char*)user, sizeof(*user));
    fp.close();
    cout << "Student saved" << endl;
}
void Student::DisplayStudents() {
    cout << "\nDisplay all students: " << endl; ////Got some problem
    User* user = new User();
    fstream fp;
    fp.open("students.txt", ios::in);
    while (fp.read((char*)user, sizeof(User))) {
        user->DisplayUser();
        cout << "-------------------------------\n";
        cout << "All students displayed" << endl;
        cout << "Press Enter to Continue";
    }
    cin.ignore();
    cin.get();
    fp.close();
}
void Student::EditStudent() {
    int id;
    cout<<"Enter Student id: ";
    cin>>id;
    fstream fp;
    User* user = new User();
    bool found = false;
    fp.open("admin.txt", ios::in | ios::out);
    while (fp.read((char*)user, sizeof(*user))) {
        if (user->getId() == id) {
            user->DisplayUser();
            cout << "Update Student detail: \n";
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
        cout << "Student have been update\n";
        cout << "-------------------------------\n";
    }
}

void Student::SearchStudent() {
    int id;
    cout<<"Enter student id: ";
    cin>>id;
    cout << "Update student detail: \n";
    fstream fp;
    User* user = new User();
    bool found = false;
    fp.open("student.txt", ios::in | ios::out);
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
        cout << "student ID found!!!\n";
        cout << "-------------------------------\n";
    }
}
void Student::SortStudent() {

}
void Student::DeleteStudent() {
    int id;
    cout<<"Enter student ID: ";
    cin>>id;
    fstream fp;
    User* user = new User();
    fp.open("student.txt", ios::in);
    fstream fp2;
    fp2.open("temp.txt", ios::out | ios::app);
    fp.seekg(0, ios::beg);
    while (fp.read((char*)user, sizeof(*user))) {
        if (user->getId() != id) {
            fp2.write((char*)user, sizeof(*user));
            break;
        }
    }
    cout << "student has been deleted\n";
    cout << "-------------------------------\n";
    cin.ignore();
    cin.get();
    fp2.close();
    fp.close();
    remove("student.txt");
    rename("temp.txt", "student.txt");
}

