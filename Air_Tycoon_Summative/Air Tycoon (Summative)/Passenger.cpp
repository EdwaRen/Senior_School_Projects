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

Passenger::Passenger(BasicInfo a, int pSeatNum, Flight pFlight, string pPreference) {
    myInfo = a;
    mySeatNum  = pSeatNum;
    myFlight = pFlight;
    myPreference = pPreference;

}
string Passenger::getMyPreference() {
    return myPreference;
}
Seat Passenger::getMySeat() {
    return myFlight.getFlightSeat(mySeatNum);
}
Flight Passenger::getMyFlight() {
    return myFlight;
}
BasicInfo Passenger::getMyInfo() {
    return myInfo;
}
int Passenger::getMySeatNum() {
    return mySeatNum;
}
void Passenger::setMyPreference(string a) {
    myPreference = a;
}
void Passenger::setMySeat(int b) {
    myFlight.getFlightSeat(b).setSeatAvail(false);
    myFlight.getFlightSeat(b).setSeatInfo(myInfo);

    mySeatNum = b;
}
void Passenger::setMyFlight(Flight a) {
    myFlight = a;
}
void Passenger::setMyInfo(BasicInfo a) {
    myInfo = a;
}
void Passenger::setMySeatNum(int a) {
    mySeatNum = a;
}
string Passenger::toString() {
    stringstream a;
    a << "     Name: " << myInfo.getName() << ", Phone Number: " << myInfo.getPhoneNumber() << ", Address: " << myInfo.getPhoneNumber() << ", Seat Number: " <<myFlight.getFlightSeat(mySeatNum).getSeatNumber() << ", Flight Destination: " << myFlight.getFlightDestination() << ", Preferred Destination: " << myPreference;
    return a.str();
}


















