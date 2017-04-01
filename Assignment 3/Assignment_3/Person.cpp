//
//  Person.cpp
//  Assignment_3
//
//  Created by - on 2017/03/27.
//  Copyright © 2017 Eddie of the House of Ren. All rights reserved.
//

#include "Person.h"
#include <string>
#include <sstream>
#include <math.h>
using namespace std;


Person::Person() {
    
}
Person::Person(string first, string last) {
    firstName = first;
    lastName = last;
}
Person::Person(string f, string l, string a) {
    firstName = f;
    lastName = l;
    address = a;
}
string Person::getFirstName() {
    return  firstName;
}
string Person::getLastName() {
    return  lastName;
}
string Person::getAddress() {
    return address;
}
void Person::setFirstName(string f) {
    firstName = f;
}
void Person::setLastName(string l) {
    lastName = l;
}
void Person::setAddress(string a) {
    address = a;
}
string Person::toString() {
    stringstream a;
    a << firstName << " " << lastName << " " << address << endl;
    return a.str();
}
