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

class Seat:public BasicInfo {
private:
    int SEAT_NUM = 10;
    BasicInfo seatInfo;
    int seatNumber;
    bool seatAvail = true;
public:
    Seat();
    Seat(int SeatNumber, bool SeatAvail);
    Seat(int SeatNumber, bool SeatAvail, BasicInfo a);
    int getSeatNumber();
    bool getSeatAvail();
    BasicInfo getSeatInfo();
    void setSeatNumber(int a);
    void setSeatAvail(bool a);
    void setSeatInfo(BasicInfo a);
    string toString();
    
};


#endif /* Seat_hpp */
