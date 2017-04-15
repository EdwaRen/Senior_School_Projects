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
#include "BasicInfo.hpp"


class Flight;
class Seat;

using namespace std;

class Passenger : public BasicInfo{
    
private:
    Seat mySeat;
    Flight myFlight;
    string myPreference;
    
public:
    Passenger();
    Passenger(BasicInfo a, Seat pSeat, Flight pFlight, string pPreference);
    string getMyPreference();
    Seat getMySeat();
    Flight getMyFlight();
    void setMyPreference(string a);
    void setMySeat(Seat a);
    void setMyFlight(Flight a); //Also the buy ticket function
    string toString();

};

#endif /* Passenger_hpp */
