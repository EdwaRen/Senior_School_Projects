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
#include "Flight.hpp"
#include "Passenger.hpp"
#include "Attendant.hpp"
#include "Constants.h"


int main(int argc, const char * argv[]) {
    
    // insert code here...
//    BasicInfo a;
//    a = BasicInfo("Helllo", "World Avenue", "32145678");
//    cout << a.getPhoneNumber() << endl;
//    Seat b;
//    b = Seat(423564, true, a);
//    
//    cout << b.getSeatInfo().getName() << " " <<b.getSeatAvail() << endl <<b.toString() << endl;
//    
//    Flight c;
//    c = Flight("New York", 1);
//   
//    cout << c.displaySeatsAvailible() << endl <<c.displayPassengerInfo() <<endl;
//    
//    Passenger d;
//    
//    cout << endl;
    
    Attendant e;
    
    int seatNumCount = 0;
    int flightNumCount = 0;

    for (int x = 0; x < CUSTOMER_AMOUNT; x++) {
        
        
        e.reserveSeat(e.getCustomers(x), e.getRoutes(flightNumCount), seatNumCount);
        
        seatNumCount++;
        if (seatNumCount >= 10) {
            seatNumCount = 0;
            flightNumCount++;
        }
    }
    for (int x = 0; x < FLIGHTS_AMOUNT; x++) {
        cout << "\n" << x << endl;
        printf("%-2s", e.displayAllCustomerBySeatOrder(e.getRoutes(x)).c_str());

        //cout << e.displayAllCustomerBySeatOrder(e.getRoutes(x)) << endl;
    }

    
    
    //d = Passenger(a, b, c, "Boston");
    
    
    std::cout << "\nHello, World!\n";
    return 0;
}
