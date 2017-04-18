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
        BasicInfo b;
        a = Seat((FLIGHT_TAG*100) +1, true, b);
        flightSeats[x] = a;
    }
}
Flight::Flight(string destination, int flightTag) {
    FLIGHT_TAG = flightTag;
    flightDestination = destination;
    for (int x = 0; x < SEAT_NUM; x++) {
        Seat a;
        BasicInfo b;
        a = Seat((FLIGHT_TAG*100) +x, true, b);
        flightSeats[x] = a;
    }
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
            a << "Seat: " << flightSeats[x].getSeatNumber() << " is availible" << endl;
        }
    }
    return a.str();
    
}
string Flight::displayPassengerInfo() {
    stringstream a;
    a << "Passengers: " << endl;
    for (int x = 0; x < SEAT_NUM; x++) {
        if (flightSeats[x].getSeatAvail() == false) {
            a << "    Name: " << flightSeats[x].getSeatInfo().getName() << ", Address: " << flightSeats[x].getSeatInfo().getAddress() << ", Phone Number: " << flightSeats[x].getSeatInfo().getPhoneNumber();
        }
    }
    return a.str();
}


















