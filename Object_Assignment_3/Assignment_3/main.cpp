//
//  main.cpp
//  Assignment_3
//
//  Created by - on 2017/03/08.
//  Copyright © 2017 Eddie of the House of Ren. All rights reserved.
//

#include <iostream>
#include "Header.h"




int main(int argc, const char * argv[]) {
    
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


    // insert code here...
    return 0;
}
