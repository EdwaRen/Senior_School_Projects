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

using namespace std;

class BasicInfo {
    
private:
    string name;
    string address;
    string phoneNumber;
    
public:
    BasicInfo();
    BasicInfo(string Name, string Address, string PhoneNumber);
    string getName();
    string getAddress();
    string getPhoneNumber();
    
    void setName(string a);
    void setAddress(string a);
    void setPhoneNumber(string a);
    
};


#endif /* BasicInfo_hpp */
