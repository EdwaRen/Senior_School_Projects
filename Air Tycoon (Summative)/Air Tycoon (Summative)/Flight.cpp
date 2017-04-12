//
//  Flight.cpp
//  Air Tycoon (Summative)
//
//  Created by - on 2017/04/12.
//  Copyright © 2017 Eddie of the House of Ren. All rights reserved.
//

#include "Flight.hpp"
#include <string>
#include <sstream>
using namespace  std;

Flight::Flight() {
    for (int x = 0; x < SEAT_NUM; x++) {
        Seat a;
        flightSeats[x] = a;
    }
}
Flight::Flight(string destination) {
    flightDestination = destination;
}
Seat& Flight::getFlightSeat(int a) {
    return flightSeats[a];
}
string Flight::getFlightDestination() {
    return flightDestination;
}
void Flight::setFlightSeat(Seat &a, int b) {
    flightSeats[b] = a;
}
void Flight::setFlightDestination(string a) {
    flightDestination = a;
}
string Flight::displaySeatsAvailible() {
    stringstream a;
    for (int x = 0; x < SEAT_NUM; x++) {
        if (flightSeats[x].getSeatAvail() == true) {
            
        }
    }
    return a.str();
    
}


















