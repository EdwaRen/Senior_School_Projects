//
//  Flight.hpp
//  Air Tycoon (Summative)
//
//  Created by - on 2017/04/12.
//  Copyright © 2017 Eddie of the House of Ren. All rights reserved.
//

#ifndef Flight_hpp
#define Flight_hpp

#include <stdio.h>
#include "Seat.hpp"

class Flight {
    
private:
    int FLIGHT_TAG = 0; //This flight's serial number in the routes[] array of the attendant class
    int SEAT_NUM = PLANE_SEATS;
    Seat *flightSeats = new Seat[SEAT_NUM];
    string flightDestination; //The destination for this flight. This can be preferably matched with the passenger's preffered destination
    
public:
    Flight();
    Flight(string destination, int flightTag);
    Seat& getFlightSeat(int a);
    string getFlightDestination();
    void setFlightSeat(Seat& a, int b);
    void setFlightDestination(string a);
    string displaySeatsAvailible(); //Displays availibility of seats
    string displayPassengerInfo();  //Displays the info of all 10 passengers

};









#endif /* Flight_hpp */
