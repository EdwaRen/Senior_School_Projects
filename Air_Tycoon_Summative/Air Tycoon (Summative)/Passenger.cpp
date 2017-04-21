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

Passenger::Passenger(BasicInfo& a, int pSeatNum, Flight& pFlight, string pPreference, int myIDNum) {
    myInfo = a;
    mySeatNum  = pSeatNum;
    myFlight = pFlight;
    myPreference = pPreference;
    myID = myIDNum;

}
string Passenger::getMyPreference() {
    return myPreference;
}
Seat& Passenger::getMySeat() {
    return myFlight.getFlightSeat(mySeatNum);
}
Flight& Passenger::getMyFlight() {
    return myFlight;
}
BasicInfo& Passenger::getMyInfo() {
    return myInfo;
}
int Passenger::getMySeatNum() {
    return mySeatNum;
}
int Passenger::getMyID() {
    return myID;
}
void Passenger::setMyPreference(string a) {
    myPreference = a;
}
void Passenger::setMySeat(int b) {
    myFlight.getFlightSeat(b).setSeatAvail(false);
    myFlight.getFlightSeat(b).setSeatInfo(myInfo);

    mySeatNum = b;
}
void Passenger::setMyFlight(Flight& a) {
    myFlight = a;
}
void Passenger::setMyInfo(BasicInfo& a) {
    myInfo = a;
}
void Passenger::setMySeatNum(int a) {
    mySeatNum = a;
}
void Passenger::setMyID(int a) {
    myID = a;
}
string Passenger::toString() {
    stringstream a;
    int localSeatNum = -1;
    if (mySeatNum != -1) {
        myFlight.getFlightSeat(mySeatNum);
        localSeatNum = myFlight.getFlightSeat(mySeatNum).getSeatNumber();
    }
    
    a << "      Passenger No. " << myID<< ", Name: " << myInfo.getName() << ", Phone Number: " << myInfo.getPhoneNumber() << ", Address: " << myInfo.getPhoneNumber() << ", Seat Number: " << localSeatNum << ", Flight Destination: " << myFlight.getFlightDestination() << ", Preferred Destination: " << myPreference;
    return a.str();
}


















