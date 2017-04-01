//
//  Student.cpp
//  Assignment_3
//
//  Created by - on 2017/03/27.
//  Copyright © 2017 Eddie of the House of Ren. All rights reserved.
//

#include "Student.h"
#include <string>
#include <sstream>
#include <math.h>
using namespace std;

Student::Student(){
    //numLates = 0;
}
Student::Student(string f, string l, string a, int g, string idf) {
    //numLates = 0;
    setFirstName(f);
    setLastName(l);
    setAddress(a);
    grade = g;
    studentID = idf;
}
Student::Student(string f, string l, int g, string idf) {
    //numLates = 0;
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
    //cout << "Adding late: " << numLates<< endl;
    
}
string Student::toString() {
    stringstream a;
    a << getFirstName() << " " << getLastName() << ", Address: " << getAddress() << ", Grade: " << grade << ", Lates: "<< numLates << ", ID: " << studentID << endl << getSchedule() << endl;
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
void Student::setSchedule(string a, string b, string c, string d) {
    schedule[0] = a;
    schedule[1] = b;
    schedule[2] = c;
    schedule[3] = d;
}
string Student::getSchedule() const{
    stringstream a;
    a << "First Period:   "<<schedule[0] << endl <<"Second Period:  " <<schedule[1] << endl << "Third Period:   "<<schedule[2] <<endl<< "Fourth Period:  "<<schedule[3];
    return a.str();
}

