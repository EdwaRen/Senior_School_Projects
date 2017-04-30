//
//  GUI.hpp
//  Air Tycoon (Summative)
//
//  Created by - on 2017/04/24.
//  Copyright © 2017 Eddie of the House of Ren. All rights reserved.
//

#ifndef GUI_hpp
#define GUI_hpp

#include <stdio.h>
#include "Seat.hpp"
#include "Flight.hpp"
#include "Passenger.hpp"
#include "Constants.h"
#include "Attendant.hpp"

class GUI {
    
private:
    Attendant myAttendant;
public:
    GUI();
    //void setConstants();
    int guiController();
    
};




#endif /* GUI_hpp */
