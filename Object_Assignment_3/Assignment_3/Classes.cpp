//
//  Classes.cpp
//  Assignment_3
//
//  Created by - on 2017/03/08.
//  Copyright © 2017 Eddie of the House of Ren. All rights reserved.
//
#include <iostream>
#include <stdio.h>
#include "Header.h"
#include <string>
#include <sstream>

Person::Person() {
    
}
Person::Person(string first, string last) {
    firstName = first;
    lastName = last;
}
Person::Person(string f, string l, string a) {
    firstName = f;
    lastName = l;
    address = a;
}
string Person::getFirstName() {
    return  firstName;
}
string Person::getLastName() {
    return  lastName;
}
string Person::getAddress() {
    return address;
}
void Person::setFirstName(string f) {
    firstName = f;
}
void Person::setLastName(string l) {
    lastName = l;
}
void Person::setAddress(string a) {
    address = a;
}
string Person::toString() {
    stringstream a;
    a << firstName << " " << lastName << " " << address << endl;
    return a.str();
}

Student::Student(){
    numLates = 0;
}
Student::Student(string f, string l, string a, int g, string idf) {
    numLates = 0;
    setFirstName(f);
    setLastName(l);
    setAddress(a);
    grade = g;
    studentID = idf;
}
Student::Student(string f, string l, int g, string idf) {
    numLates = 0;
    setFirstName(f);
    setLastName(l);
    grade = g;
    studentID = idf;
}
int Student::getGrade() {
    return grade;
}
string Student::getStudentID() {
    return studentID;
}
int Student::getNumLates() {
    return numLates;
}
void Student::setGrade(int n) {
    grade = n;
}
void Student::setStudentID(string s) {
    studentID = s;
}
void Student::addLate() {
    numLates = numLates + 1;
    cout << "Adding late: " << numLates<< endl;

}
string Student::toString() {
    stringstream a;
    a << getFirstName() << " " << getLastName() << ", Address: " << getAddress() << ", Grade: " << grade << ", Lates: "<< numLates << ", ID: " << studentID << endl;
    return a.str();
}
bool Student::isValidID(string idf) const{
    bool a = true;
    bool a2 = true;
    bool a3 = true;
    char cArray[11];
    /*for (int x = 0; x < 11; x++) {
        if (cArray[x] == 'p') {
            a2 = false;
        }
        cArray[x] = 'p';
    }*/
    if (idf.length() > 10 || idf.length() <=9) {
        a2 = false;
        a = false;
    } else {
        strcpy(cArray, idf.c_str());
    }
    //cout << "\n" << sizeof(cArray)/sizeof(cArray[0])  << " " << idf<< endl;
    if (a2 == true) {
        for (int x = 0; x < 10; x++) {
            //cout << cArray[x] << " ";
        }
        if (idf.length() > 10 || idf.length() <= 9) {
            a = false;
        } else if (cArray[0] != 'S') {
            a = false;
        } else {
            for (int i = 1; i < 10; i++) {
                if (cArray[i] != '1' && cArray[i] != '2' && cArray[i] != '3' && cArray[i] != '4' && cArray[i] != '5' && cArray[i] != '6'&& cArray[i] != '7'&& cArray[i] != '8' && cArray[i] != '9' && cArray[i] != '0') {
                    a = false;
                }
            }
        }
    }
     
    return a;
}
Teacher::Teacher() {}
Teacher::Teacher(string f, string l, string a, string t, string idf) {
    setFirstName(f);
    setLastName(l);
    setAddress(a);
    setTeachables(t);
    setEmployeeID(idf);
}
Teacher::Teacher(string f, string l, string t, string idf) {
    setFirstName(f);
    setLastName(l);
    setTeachables(t);
    setEmployeeID(idf);
}
string Teacher::getTeachables() {
    return teachables;
}
string Teacher::getEmployeeID() {
    return employeeID;
}
void Teacher::setTeachables(string t) {
    teachables = t;
}
void Teacher::setEmployeeID(string e) {
    employeeID = e;
}
void Teacher::markStudentLate(Student s) {
    s.addLate();
}
string Teacher::toString() {
    stringstream a;
    a << getFirstName() << " " << getLastName() << ", Address: " << getAddress() << ", Teachables: " << teachables << ", ID: " << employeeID << endl;
    return a.str();
}
bool Teacher::isValidID(string idf) const{
    bool a = true;
    bool a2 = true;
    char cArray[11];
    /*for (int x = 0; x < 11; x++) {
     if (cArray[x] == 'p') {
     a2 = false;
     }
     cArray[x] = 'p';
     }*/
    if (idf.length() > 6 || idf.length() <=5) {
        a2 = false;
        a = false;
    } else {
        strcpy(cArray, idf.c_str());
    }
    //cout << "\n" << sizeof(cArray)/sizeof(cArray[0])  << " " << idf<< endl;
    if (a2 == true) {
        for (int x = 0; x < 10; x++) {
            //cout << cArray[x] << " ";
        }
        if (idf.length() > 6 || idf.length() <= 5) {
            a = false;
        } else if (cArray[0] != 'C') {
            a = false;
        } else {
            for (int i = 1; i < 6; i++) {
                if (cArray[i] != '1' && cArray[i] != '2' && cArray[i] != '3' && cArray[i] != '4' && cArray[i] != '5' && cArray[i] != '6'&& cArray[i] != '7'&& cArray[i] != '8' && cArray[i] != '9' && cArray[i] != '0') {
                    a = false;
                }
            }
        }
    }
    
    return a;
}


















