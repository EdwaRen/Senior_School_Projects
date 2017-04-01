//
//  Teacher.cpp
//  Assignment_3
//
//  Created by - on 2017/03/27.
//  Copyright © 2017 Eddie of the House of Ren. All rights reserved.
//

#include "Teacher.h"
#include <string>
#include <sstream>
#include <math.h>

using namespace std;

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
void Teacher::markStudentLate(Student& s) {
    s.addLate();
}
string Teacher::toString() {
    stringstream a;
    a << getFirstName() << " " << getLastName() << ", Address: " << getAddress() << ", Teachables: " << teachables << ", ID: " << employeeID << endl <<getSchedule() << endl;
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

void Teacher::setSchedule(Course a, Course b, Course c, Course d) {
    
    tSchedule[0] = a;
    tSchedule[1] = b;
    tSchedule[2] = c;
    tSchedule[3] = d;
    
}

string Teacher::getSchedule() const{
    
    //Course e, f, g, h;
    //cout << "SCH 1: "<<e.getCName() << e.getCCode() << e.getCLevel() ;
    
    stringstream a;
    a << "First Period:   "<<tSchedule[0].getCName() << endl <<"Second Period:  " << tSchedule[1].getCName() << endl << "Third Period:   "<< tSchedule[2].getCName() <<endl<< "Fourth Period:  "<< tSchedule[3].getCName();
    return a.str();
}

void Teacher::addToClass(Student& a, int place) {
    
    myClass[place] = a;
    
}


