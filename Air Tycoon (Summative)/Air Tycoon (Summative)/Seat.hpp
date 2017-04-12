//
//  Seat.hpp
//  Air Tycoon (Summative)
//
//  Created by - on 2017/04/12.
//  Copyright © 2017 Eddie of the House of Ren. All rights reserved.
//

#ifndef Seat_hpp
#define Seat_hpp

#include <stdio.h>
#include "BasicInfo.hpp"

class Seat: public BasicInfo {
private:
    int seatNumber;
    bool seatAvail = false;
public:
    Seat();
    Seat(int SeatNumber, bool SeatAvail);
    Seat(int SeatNumber, bool SeatAvail, BasicInfo a);
    int getSeatNumber();
    bool getSeatAvail();
    void setSeatNumber(int a);
    void setSeatAvail(bool a);
    virtual string toString();
    
};


#endif /* Seat_hpp */
