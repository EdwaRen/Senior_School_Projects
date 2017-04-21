//
//  BasicInfo.hpp
//  Air Tycoon (Summative)
//
//  Created by - on 2017/04/12.
//  Copyright © 2017 Eddie of the House of Ren. All rights reserved.
//

#ifndef BasicInfo_hpp
#define BasicInfo_hpp

#include <stdio.h>

#include <string>
//#include "Constants.cpp"

using namespace std;


class BasicInfo {

    
private:
    string name;
    string address;
    string phoneNumber;
    int customerID;
    
public:
    BasicInfo();
    BasicInfo(string Name, string Address, string PhoneNumber, int customerID);
    string getName();
    string getAddress();
    string getPhoneNumber();
    int getCustomerID();
    
    void setName(string a);
    void setAddress(string a);
    void setPhoneNumber(string a);
    void setCustomerID(int myID);
    
    string toString();

    
};


#endif /* BasicInfo_hpp */
