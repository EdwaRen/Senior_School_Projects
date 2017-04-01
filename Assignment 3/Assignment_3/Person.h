//
//  Person.h
//  Assignment_3
//
//  Created by - on 2017/03/27.
//  Copyright © 2017 Eddie of the House of Ren. All rights reserved.
//

#ifndef Person_h
#define Person_h
#include <string>




using namespace std;


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




#endif /* Person_h */
