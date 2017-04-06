//
//  Student.h
//  Assignment_3
//
//  Created by - on 2017/03/27.
//  Copyright © 2017 Eddie of the House of Ren. All rights reserved.
//

#ifndef Student_h
#define Student_h
#include <iostream>
#include <string>
class Person;
#include "Person.h"


using namespace std;


class Student: public Person {
private:
    int grade = 0;
    string studentID = "a";
    int numLates = 0;
    string schedule[4] = {"Crippling Depression SL", "How to Get Into Algonquin U", "Decreasing Procrastination Ski...", "Due tomorrow? Do tomorrow 101"};
    virtual bool isValidID(string idf) const;
public:
    Student();
    Student(string f, string l, string a, int g, string idf);
    Student(string f, string l, int g, string idf);
    int getGrade();
    string getStudentID();
    int getNumLates();
    void setGrade(int n);
    void setStudentID(string s);
    void addLate();
    
    string toString();
    
    virtual string getSchedule() const;
    virtual void setSchedule(string a, string b, string c, string d) ;
};


#endif /* Student_h */
