//
//  main.cpp
//  Air Tycoon (Summative)
//
//  Created by - on 2017/04/12.
//  Copyright © 2017 Eddie of the House of Ren. All rights reserved.
//

#include <iostream>
#include "BasicInfo.hpp"
#include "Seat.hpp"

int main(int argc, const char * argv[]) {
    // insert code here...
    BasicInfo a;
    a = BasicInfo("Helllo", "World Avenue", "32145678");
    cout << a.getPhoneNumber() << endl;
    Seat b;
    b = Seat(423564, true, a);
    
    cout << b.getName() << " " <<b.getSeatAvail() << endl <<b.toString() << endl;
    
    
    std::cout << "Hello, World!\n";
    return 0;
}
