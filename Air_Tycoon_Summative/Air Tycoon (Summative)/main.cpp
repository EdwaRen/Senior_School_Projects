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
    cout << "Welcome to Fight Club Airlines! With our unprecedented services, you will truly enjoy flying the friendly skies!" << endl << endl;
    Attendant e;
    
    e.autoAssignPassengers();

    

    cout << endl << e.displayUnbookedCustomers() << endl;
    cout << "\n"<<e.displayNextCustomer() << endl;
    
    cout << e.displayAllInfoBySeatOrder() << endl;
    
    std::cout << "\nHello, World!\n";
    return 0;
}
