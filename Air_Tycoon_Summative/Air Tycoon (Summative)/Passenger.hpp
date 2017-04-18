//
//  Passenger.hpp
//  Air Tycoon (Summative)
//
//  Created by - on 2017/04/13.
//  Copyright © 2017 Eddie of the House of Ren. All rights reserved.
//

#ifndef Passenger_hpp
#define Passenger_hpp

#include <stdio.h>

#include "Seat.hpp"
#include "Flight.hpp"


class Flight;
class Seat;

using namespace std;

class Passenger : public BasicInfo{
    
private:
    int SEAT_NUM = 10;
    BasicInfo myInfo;
    int mySeatNum; //Used to access the passenger's seat from the flight's seat array at position mySeatNum
    Flight myFlight;
    string myPreference; //This variable is an optional for the player, there are repercussions if the attendant ignores the passenger's preference
    
public:
    Passenger();
    Passenger(BasicInfo a, int pSeatNum, Flight pFlight, string pPreference);
    string getMyPreference();
    Seat getMySeat();
    BasicInfo getMyInfo();
    Flight getMyFlight();
    int getMySeatNum();
    void setMyPreference(string a);
    void setMySeat(int b);
    void setMyFlight(Flight a); //Also the buy ticket function, needs to be called in conjunction with setMySeat due to lazy programming
    void setMyInfo(BasicInfo a);
    void setMySeatNum(int a);
    string toString();

};

#endif /* Passenger_hpp */
