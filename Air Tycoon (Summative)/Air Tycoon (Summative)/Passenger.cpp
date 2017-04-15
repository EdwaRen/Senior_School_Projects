//
//  Passenger.cpp
//  Air Tycoon (Summative)
//
//  Created by - on 2017/04/13.
//  Copyright © 2017 Eddie of the House of Ren. All rights reserved.
//

#include "Passenger.hpp"

#include <string>
#include <sstream>

using namespace std;

Passenger::Passenger() {}

Passenger::Passenger(BasicInfo a, Seat pSeat, Flight pFlight, string pPreference) {
    BasicInfo::setName(a.getName());
    BasicInfo::setAddress(a.getAddress());
    BasicInfo::setPhoneNumber(a.getPhoneNumber());
    mySeat  = pSeat;
    myFlight = pFlight;
    myPreference = pPreference;

}
string Passenger::getMyPreference() {
    return myPreference;
}
Seat Passenger::getMySeat() {
    return mySeat;
}
Flight Passenger::getMyFlight() {
    return myFlight;
}
void Passenger::setMyPreference(string a) {
    myPreference = a;
}
void Passenger::setMySeat(Seat a) {
    mySeat = a;
}
void Passenger::setMyFlight(Flight a) {
    myFlight = a;
}
string Passenger::toString() {
    stringstream a;
    a << "     Name: " << BasicInfo::getName() << ", Phone Number: " << BasicInfo::getPhoneNumber() << ", Address: " << BasicInfo::getPhoneNumber() << ", Seat Number: " <<mySeat.getSeatNumber() << ", Flight Destination: " << myFlight.getFlightDestination() << ", Preferred Destination: " << myPreference;
    return a.str();
}


















