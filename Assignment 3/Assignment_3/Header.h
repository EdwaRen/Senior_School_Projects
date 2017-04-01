//
//  Header.h
//  Assignment_3
//
//  Created by - on 2017/03/08.
//  Copyright © 2017 Eddie of the House of Ren. All rights reserved.
//

#ifndef Header_h
#define Header_h

class Person;
class Student;
class Teacher;
class Course;

#include <string>
#include "Teacher.h"
#include "Student.h"
#include "Person.h"

using namespace std;


class Course;


class School {
    
private:
    int const SCHOOL_POP = 500;
    int const TEACHER_POP = 20;
    int const COURSE_POP = 80;
    int const CLASS_SIZE = 25;
    
    Student *StudentPop = new Student[SCHOOL_POP];
    //Student *StudentPop_Test = new Stud
    
    Teacher *TeacherPop = new Teacher[TEACHER_POP];
    Teacher *TeacherPop_Test = new Teacher[TEACHER_POP];

    Course *CoursePop = new Course[COURSE_POP];

public:
    School();
    void StudentsEnroll();
    void TeachersHire();
    void CoursesCreate();
    void MemberAutoSchedule();
    
    string toStringStudent();
    string toStringTeacher();
    string toStringCourse();

    
    

    
};


#endif /* Header_h */
