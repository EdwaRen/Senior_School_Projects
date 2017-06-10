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
#include "GUI.hpp"


int main() {
    cout << "Welcome to Fight Club Airlines! With our unprecedented services, you will truly enjoy flying the friendly skies!" << endl << endl;
    cout << "Please read the instructions manuel and input to start the program" << endl;
    GUI a;
    
    while (a.guiController() == 0) {}
    
    
    std::cout << "\nHello, World!\n";
    return 0;
}
