//
//  Courses.h
//  Assignment_3
//
//  Created by - on 2017/03/27.
//  Copyright © 2017 Eddie of the House of Ren. All rights reserved.
//


#ifndef Courses_h
#define Courses_h

class Person;
class Student;
class Teacher;
class Course;

#include <string>
//#include "Teacher.h"
#include "Student.h"
#include "Person.h"

using namespace std;

class Course {
    
    private:
    string cLevel = "Unassigned";
    string cName = "Unassigned";
    Teacher* cTeacher;
    string cCode;
    int CLASS_SIZE = 25;
    string cCollectionStudent;
    
    Student *stuInClass = new Student[CLASS_SIZE];
    
    
    public:
    Course();
    Course(string a, string b, Teacher MsMr, string d);
    
    void setCLevel(string a);
    void setCName (string a);
    void setCTeacher (Teacher a);
    void setCCode(string a);
    string getCLevel();
    string getCName();
    Teacher& getCTeacher();
    string getCCode();
    string getCStudents();
    
    void addStuClass(Student& a, int b);
    string toStringClass();
    
};


#endif /* Courses_h */
