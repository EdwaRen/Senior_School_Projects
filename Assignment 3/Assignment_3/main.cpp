//
//  main.cpp
//  Assignment_3
//
//  Created by - on 2017/03/08.
//  Copyright © 2017 Eddie of the House of Ren. All rights reserved.
//

#include <iostream>
#include "Header.h"
#include "Person.h"
#include "Student.h"
#include "Teacher.h"
#include "Courses.h"






int main(int argc, const char * argv[]) {
    
    cout << "Hello" << endl;
    
    School c;
    c.StudentsEnroll();
    c.TeachersHire();
    c.CoursesCreate();
    c.MemberAutoSchedule(); //Schedule courses for students and teachers.
    c.crackDownOnStudents(); //Randomly marks students late
    cout << "Printing Students: \n"<< c.toStringStudent() << endl;
    cout << "Printing Teachers: \n"<< c.toStringTeacher() << endl;
    cout << "Printing Courses: \n"<<c.toStringCourse() << endl;

    
    
    
    
    
    
    
    
    
    
    /*
    Student a;
    a = Student("John", "Smith", "Walled Street", 96, "S123457689");
    cout << a.getStudentID() << endl;
    if (a.isValidID(a.getStudentID())) {
        cout << "Valid ID " << endl;
    } else{
        cout << "Invalid ID " << endl;
    }
    
    Teacher b;
    b = Teacher("Mr.", "Mckay", "Sleepology", "C12345");
    if (b.isValidID(b.getEmployeeID())) {
        cout << "Valid ID " << endl;
    } else{
        cout << "Invalid ID " << endl;
    }
    b.markStudentLate(a);
    cout << b.toString() << endl;
    cout << a.toString() << endl;
    
    cout << "\n\n\n\n\n" << endl;
    
    a.setSchedule("English", "Anglais", "British", "UK Linguistics");
    cout << a.toString() << endl;

    cout << endl;
    
    b.setSchedule("Math", "French", "Physics", "Professional Gramming");
    cout << b.toString() << endl;
    
    b.createMyClass();
    cout << "\nPrintng Teacher's class: " << endl;
    cout << b.toStringClass() << endl;
*/
    //cout << a.getNumLates();


    // insert code here...
    return 0;
}
