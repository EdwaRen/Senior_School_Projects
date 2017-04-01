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
#include <math.h>

class Course;



/*
string Teacher::toStringClass() {
    
    stringstream a;
    for (int x = 0; x < CLASS_SIZE;x++ ) {
        a << myClass[x].toString() << "\n\n";
    }
    return a.str();
}
*/


School::School() {
    
}
void School::StudentsEnroll() {
    srand(static_cast<uint32_t>(time(0)));
    
    string sNamef1[15] = {"Mar", "Jam", "Anne", "Flar", "Arin", "Hakun", "Goot", "Jim", "Son", "Trish", "Hear", "Sam", "Rel", "Atr", "Sour"};
    string sNamef2[15] = {"y", "ster", "na", "iette", "ner", "a", "ther", "an", "nel", "er", "ean", "ool", "en", "ar", "on"};

    string sName2[12] = {"North", "Huntt", "Coach", "Cutt", "Larll", "Pudd", "Methyl", "Fleur", "Einz", "Chan", "Lash", "Harp"};
    string sName3[18] = {"ouest", "eer", "osh", "een", "ool", "ash", "art", "ion", "iot", "out", "arm", "ith", "oop", "", "", "", "", ""};
    string sName4[21] = {"er", "ar", "ic", "oc", "an", "ot", "ab", "od", "ox", "ot", "al", "es", "at", "os", "up", "", "", "", "", "", ""};

    string street1[10] = {"Largon", "Propasn", "Crapulous", "Pastafar", "Chedem", "Ehdeer", "Chiiz", "Farouqm", "Blas", "MethylButan"};
    string street2[10] = {"Avenue", "Street", "Road", "Court", "Drive", "Crescent", "Boulevard", "Expressway", "Lane", "Way"};
    
    for (int x = 0; x < SCHOOL_POP; x ++) {
        stringstream a, b, d, myAddress;
        a << sNamef1[rand()%15] << sNamef2[rand()%15];
        b << sName2[rand()%12] <<sName3[rand()%18] << sName4[rand()%21];
        int c = rand()%100;
        d << "S" << rand()%100000000 + rand()%10 * 100000000;
        myAddress << rand()%50 << " " << street1[rand()%10] << sName4[rand()%15]<< " " << street2[rand()%10];
        StudentPop[x] = Student(a.str(), b.str(), myAddress.str(), c, d.str());
    }
}
void School::TeachersHire() {
    srand(static_cast<uint32_t>(time(0)));
    string sNamef1[4] = {"Mr.", "Ms.", "Dr.", "Prof."};
    
    string sName2[12] = {"Scorp", "Prey", "Hunt", "Target", "Patrol", "Polic", "Order", "Chill", "Lion", "Grammar", "Party", "Snak"};
    string sName3[18] = {"ouest", "eer", "osh", "een", "ool", "ash", "art", "ion", "iot", "out", "arm", "ith", "oop", "", "", "", "", ""};
    string sName4[21] = {"er", "ar", "ic", "oc", "an", "ot", "ab", "od", "ox", "ot", "al", "es", "at", "os", "up", "", "", "", "", "", ""};
    
    string street1[10] = {"Largon", "Propasn", "Crapulous", "Pastafar", "Chedem", "Ehdeer", "Chiiz", "Farouqm", "Blas", "MethylButan"};
    string street2[10] = {"Avenue", "Street", "Road", "Court", "Drive", "Crescent", "Boulevard", "Expressway", "Lane", "Way"};
    
    string Teachables[4] = {"Sciences", "Mathematics", "Finances", "Commerce"};
    string Teachables2[4] = {"Humanities", "Physical Education", "Languages", "Arts",};

    for (int x = 0; x < TEACHER_POP; x++) {
        stringstream a, b, myAddress, d, e;
        a << sNamef1[rand()%4];
        b << sName2[rand()%12] << sName3[rand()%18] << sName4[rand()%21];
        myAddress << street1[rand()%10] << sName4[rand()%15] << " " << street2[rand()%10];
        d << Teachables[rand()%4] << " and " << Teachables2[rand()%4];
        e << "C" << rand()%10000 + rand()%10 * 10000;

        TeacherPop[x] = Teacher(a.str(), b.str(), myAddress.str(), d.str(), e.str());
        TeacherPop[x].setSchedule(CoursePop[(x*4)], CoursePop[(x*4)+1], CoursePop[(x*4)+2], CoursePop[(x*4)+3]);
        
        
    }
}
void School::CoursesCreate() {
    string level[5]  = {"Introductory", "Academic", "High Level" , "Standard Level", "Applied"};
    string CourseName[12] = {"Mathematics", "Chemistry", "Physics", "English Studies", "French Studies", "Geomatics", "Software Engineering", "History", "Pastafarianology", "Religious Studies", "Business Management", "Financial Investment"};
    
    //To reflect the standards of the OCDSB, teachables have no relation with a teacher's teaching course.
    string CourseCode[12] = {"MTMATC", "SCHSRY", "SPHYCS", "ENGSTU", "FIFSTU", "GEOMTC", "SOFTEG", "HISTRY", "PSTFRN", "RAMENN", "BSUMNG", "FNCIVS"};

    for (int x = 0; x < COURSE_POP; x++) {
        stringstream d;
        double myNum = x/4;
        myNum = floor(myNum);
        int courseRand = rand()%12;
        stringstream courseID;
        if (x <= 9) {
            courseID << "0" << x;
        } else {
            courseID << x;
        }
        d << CourseCode[courseRand] << "-" << courseID.str();

        CoursePop[x] = Course(level[rand()%5], CourseName[courseRand], TeacherPop[(int)myNum], d.str());
        for (int i = 0; i < CLASS_SIZE; i++) {
            int xCopy = x;
            if (xCopy>= 20 && xCopy <40) {
                xCopy = xCopy - 20;
            } else if (xCopy>= 40 && xCopy <60) {
                xCopy = xCopy - 40;
            } else if (xCopy>= 60 && xCopy <80){
                xCopy = xCopy - 60;
            }
            
            int c = (xCopy*25) + i;
            CoursePop[x].addStuClass(StudentPop[(xCopy*20)+i], i);
        }
        
    }
}

void School::MemberAutoSchedule() {
    for (int x = 0; x < COURSE_POP; x++) {
        CoursePop[x].setCTeacher(TeacherPop[(int)floor(x/4)]);
    }
    
    for (int x = 0; x < TEACHER_POP; x++) {
        TeacherPop[x].setSchedule(CoursePop[(x*4)], CoursePop[(x*4)+1], CoursePop[(x*4)+2], CoursePop[(x*4)+3]);
    }
    /*
     cout << toStringTeacher() << endl;
    for (int x = 0; x < COURSE_POP; x++) {
        CoursePop[x].setCTeacher(TeacherPop[(int)floor(x/4)]);
    }
     */
    
}

string School::toStringStudent() {
    stringstream a;
    for (int x = 0; x < SCHOOL_POP; x ++) {
        a << StudentPop[x].toString() << "\n";
    }
    return a.str();
}
string School::toStringTeacher() {
    stringstream a;
    for (int x = 0; x < TEACHER_POP; x ++) {
        a << TeacherPop[x].toString() << "\n";
    }
    return a.str();
}
string School::toStringCourse() {
    stringstream a;
    for (int x = 0; x < COURSE_POP; x ++) {
        a << CoursePop[x].toStringClass() << "\n";
    }
    return a.str();
}























