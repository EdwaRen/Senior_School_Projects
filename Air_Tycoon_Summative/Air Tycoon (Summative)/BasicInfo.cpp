//
//  BasicInfo.cpp
//  Air Tycoon (Summative)
//
//  Created by - on 2017/04/12.
//  Copyright © 2017 Eddie of the House of Ren. All rights reserved.
//

#include "BasicInfo.hpp"
#include <sstream>

using namespace std;

BasicInfo::BasicInfo() { }
BasicInfo::BasicInfo(string Name, string Address, string PhoneNumber, int myID) {
    name = Name;
    address = Address;
    phoneNumber = PhoneNumber;
    customerID = myID;
}
string BasicInfo::getAddress() {
    return address;
}
string BasicInfo::getName() {
    return name;
}
string BasicInfo::getPhoneNumber() {
    return phoneNumber;
}
int BasicInfo::getCustomerID() {
    return customerID;
}

void BasicInfo::setName(string a) {
    name = a;
}
void BasicInfo::setAddress(string a) {
    address = a;
}
void BasicInfo::setPhoneNumber(string a) {
    phoneNumber = a;
}
void BasicInfo::setCustomerID(int myID) {
    customerID = myID;
}

string BasicInfo::toString() {
    stringstream a;
    
    a << name << " - " << address << " - " << phoneNumber << " - ID: " << customerID << endl;
    
    return a.str();
    
}
