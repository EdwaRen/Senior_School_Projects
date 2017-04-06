//
//  Teacher.h
//  Assignment_3
//
//  Created by - on 2017/03/27.
//  Copyright © 2017 Eddie of the House of Ren. All rights reserved.
//


#ifndef Teacher_h
#define Teacher_h

class Person;
class Student;
class Teacher;
//class Course;


#include "Person.h"

#include "Student.h"
#include "Courses.h"

#include <string>
using namespace std;


class Teacher: public Person {
    private:
    string teachables;
    string employeeID;
    int COURSE_NUM = 4;
    //Course mySchedule[4];
    Course *tSchedule = new Course[COURSE_NUM];
    int CLASS_SIZE = 80;
    Student *myClass = new Student[CLASS_SIZE];
    virtual bool isValidID(string idf) const;

    
    public:
    Teacher();
    Teacher(string f, string l, string a, string t, string idf);
    Teacher(string f, string l, string t, string idf);
    string getTeachables();
    string getEmployeeID();
    void setTeachables(string t);
    void setEmployeeID(string idf);
    void markStudentLate(Student& s);
    string toString();
    
    virtual string getSchedule() const;
    virtual void setSchedule(Course a, Course b, Course c, Course d) ;
    //virtual void autoSchedule(int d);
    
    void addToClass(Student& a, int place);
    //string toStringClass();
};


#endif /* Teacher_h */
