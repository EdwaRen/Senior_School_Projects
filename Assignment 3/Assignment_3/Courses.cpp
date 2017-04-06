//
//  Courses.cpp
//  Assignment_3
//
//  Created by - on 2017/03/27.
//  Copyright © 2017 Eddie of the House of Ren. All rights reserved.
//

#include "Courses.h"
#include <string>
#include <sstream>
#include <math.h>
#include "Teacher.h"

using namespace std;


Course::Course() {}
Course::Course(string a, string b, Teacher MsMr, string d){
    cLevel = a;
    cName = b;
    cTeacher = &MsMr;
    cCode = d;
    //cCollectionStudent = cTeacher.toStringClass();
    
}

void Course::setCLevel(string a) {
    cLevel = a;
}
void Course::setCName (string a) {
    cName = a;
}
void Course::setCTeacher (Teacher a) {
    *cTeacher;
    
    //cTeacher->setEmployeeID(a.getEmployeeID());
    
}
void Course::setCourseTeahcer(string a) {
    courseTeacher = a;
}

void Course::setCCode(string a){
    cCode = a;
}
string Course::getCLevel(){
    return cLevel;
}
string Course::getCName(){
    return cName;
}
Teacher& Course::getCTeacher() {
    return *cTeacher;
}
string Course::getCourseTeacher() {
    return courseTeacher;
}
string Course::getCCode() {
    return cCode;
}
string Course::getCStudents() {
    return cCollectionStudent;
}
void Course::addStuClass(Student& a, int b) {
    stringstream c;
    stuInClass[b] = a;
    c << cCollectionStudent <<stuInClass[b].getFirstName() << " " << stuInClass[b].getLastName() << ", ";
    cCollectionStudent = c.str();
}
string Course::toStringClass() {
    //cout << getCTeacher().getLastName() << endl;
    stringstream a;
    //getCTeacher();
    a << "\nCourse Name: " << getCLevel() << " " << getCName() <<", Teacher: " << getCourseTeacher()   << " " << ", Course Code: " << getCCode() << "\n   Students: "<< "\t" << getCStudents();
    
    
    return a.str();
}

