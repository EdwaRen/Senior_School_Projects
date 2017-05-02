//
//  Flight.cpp
//  Air Tycoon (Summative)
//
//  Created by - on 2017/04/12.
//  Copyright © 2017 Eddie of the House of Ren. All rights reserved.
//
#include <iostream>
#include <iomanip>
#include "Flight.hpp"
#include <string>
#include <sstream>
using namespace  std;

Flight::Flight() {
    for (int x = 0; x < SEAT_NUM; x++) {
        Seat a;
        BasicInfo b;
        
        //Creates the seat of the flight. Since there is not specified flightTag, it is set to 1. All seats therefore also have the same seatID number
        a = Seat((1*100) +1, true, b);
        flightSeats[x] = a;
    }
}
Flight::Flight(string destination, int flightTag) {
    FLIGHT_TAG = flightTag;
    flightDestination = destination;
    for (int x = 0; x < SEAT_NUM; x++) {
        Seat a;
        
        //creates a blank BasicInfo object so that the seat has no relevant information.
        BasicInfo b;
        
        //The for loop above ensures the following code produces a unique seatID for every seat on the flight.
        a = Seat((FLIGHT_TAG*100) +x, true, b); //
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
    //This function only displays passenger info by seat order. Another function in the attendant class can display by name alphabetically.
    
    stringstream a;
    a << "Passengers: " << endl;
    for (int x = 0; x < SEAT_NUM; x++) {
        if (flightSeats[x].getSeatAvail() == false) {
            a << "    Name: " << flightSeats[x].getSeatInfo().getName() << setw(15) << ", Address: " << flightSeats[x].getSeatInfo().getAddress() << setw(15) << ", Phone Number: " << setw(15) << flightSeats[x].getSeatInfo().getPhoneNumber() << endl;
        }
    }
    return a.str();
}


















