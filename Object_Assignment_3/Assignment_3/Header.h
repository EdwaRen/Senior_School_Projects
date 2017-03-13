//
//  Header.h
//  Assignment_3
//
//  Created by - on 2017/03/08.
//  Copyright © 2017 Eddie of the House of Ren. All rights reserved.
//

#ifndef Header_h
#define Header_h

using namespace std;
class School {
    
private:
    
    School();
    
    
    
};


class Person {
private:
    string firstName;
    string lastName;
    string address = "N/A";
    
public:
    Person();
    Person(string first, string last);
    Person(string first, string last, string add);
    string getFirstName();
    string getLastName();
    string getAddress();
    void setFirstName(string f);
    void setLastName(string l);
    void setAddress(string a);
    string toString();
};

class Student : public Person {
private:
    int grade = 0;
    string studentID = "a";
    int numLates;
    
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
    virtual bool isValidID(string idf) const;
    string toString();
};

class Teacher: public Person {
private:
    string teachables;
    string employeeID;
public:
    Teacher();
    Teacher(string f, string l, string a, string t, string idf);
    Teacher(string f, string l, string t, string idf);
    string getTeachables();
    string getEmployeeID();
    void setTeachables(string t);
    void setEmployeeID(string idf);
    virtual bool isValidID(string idf) const;
    void markStudentLate(Student s);
    string toString();
};

#endif /* Header_h */
