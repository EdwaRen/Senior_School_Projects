//
//  Attendant.cpp
//  Air Tycoon (Summative)
//
//  Created by - on 2017/04/18.
//  Copyright © 2017 Eddie of the House of Ren. All rights reserved.
//
#include <iostream>

#include "Attendant.hpp"
#include <sstream>
#include <string>

using namespace std;
string createInfoName();
string createAddress();
string createPhoneNumber();
void insertion_sort (string arr[], int arr2[], int length);


//Attendant::Attendant() {
//   
//    
//}
Attendant::Attendant() {
    ticketSales = 0;
    //ticketSales = TicketSales;
    
    srand(static_cast<uint32_t>(time(0)));
    //routes[ROUTES_NUM] = Flight("UNBOOKED", ROUTES_NUM+1);

    routes[ROUTES_NUM].setFlightDestination("UNBOOKED");
    for (int x = 0; x < ROUTES_NUM; x++) {
        routes[x] = Flight(routeDestinations[rand()%10], x+1);
        
    } //Creates all the flights with a capacity of 10 passengers each
    
    
    for (int x = 0; x < CUSTOMER_AMOUNT; x++) {
        BasicInfo a;
        a.setName(createInfoName());
        a.setAddress(createAddress());
        a.setPhoneNumber(createPhoneNumber());
        a.setCustomerID(x);
        customers[x] = Passenger(a, -1, routes[ROUTES_NUM], routeDestinations[rand()%5], x);
        
    } //Creates all the passengers to be flown
    cout << "Customer Amount: " << CUSTOMER_AMOUNT << endl;
}
string createInfoName() {
    stringstream a;
    string n1[10] = {"JOHN", "KATH", "MARK", "TOM", "TIM", "NICK", "FRANK", "LIAM", "GEORGE", "JUSTIN"};
    string n2[10] = {"ATHEN", "ALEEN", "ERSON", "Y", "" , "ALOS", "EN", "", "", "IAN"};
    string n3[10] = {"SMITH", "WEST", "CAPPER", "BROWN", "JAN", "ANTON", "WINK", "COOPER", "CHER", "BAIL"};
    a << n1[rand()%10] << n2[rand()%10] << " " << n3[rand()%10];
    return a.str();
}
string createAddress() {
    stringstream a;
    string n1[10] = {"Round", "Larson", "Main", "Fox", "Woods", "Shire", "Bagle", "Cather", "Forester", "Sevelt"};
    string n2[5] = {"Avenue", "Road", "Street", "Court", "Lane"};
    a << n1[rand()%10] << " " << n2[rand()%5];
    return a.str();
}
string createPhoneNumber() {
    stringstream a;
    a << "(" << rand()%100 + 800 << ") " << rand()%900+100 << "-" << rand()%9000 + 1000;
    return a.str();
}

int Attendant::getTicketSales() {
    return ticketSales;
}
Passenger& Attendant::getCustomers(int a) {
    return customers[a];
}
Flight& Attendant::getRoutes(int a) {
    return routes[a];
}
void Attendant::setTicketSales(int a) {
    ticketSales = a;
}
void Attendant::setCustomers(Passenger& a, int b) {
    customers[b] = a;
}
void Attendant::setRoutes(Flight& a, int b) {
    routes[b] = a;
}


void Attendant::addTicketSale() {
    ticketSales++;
}
void Attendant::cancelTicketSale() {
    ticketSales--;
}
string Attendant::displayRoutes() {
    stringstream a;
    for (int x = 0; x < ROUTES_NUM; x++) {
        a << "Route #" << x+1 << ": " << routes[x].getFlightDestination() << endl;
    }
    return a.str();
}

void Attendant::reserveSeat(Passenger& a, Flight& b, int c) {
    ticketSales++;
    if (b.getFlightSeat(c).getSeatAvail() == true) {
        b.getFlightSeat(c).setSeatAvail(false);
        b.getFlightSeat(c).setSeatInfo(a.getMyInfo());
        a.setMyFlight(b);
        cout << "Reserved seat for Passenger No. "<<a.getMyID() << ", " << a.getMyInfo().toString();
    } else {
        bool reserved = false;
        for (int x = 0; x < SEAT_NUM; x++) {
            if (b.getFlightSeat(x).getSeatAvail() == true) {
                b.getFlightSeat(x).setSeatAvail(false);
                b.getFlightSeat(x).setSeatInfo(a.getMyInfo());
                a.setMyFlight(b);
                reserved = true;
                cout << "Preferred Seat Not Availible, Reserved seat for Passenger No. "<<a.getMyID() << ", " << a.getMyInfo().toString();
                break;
            }
        }
        if (reserved == false) {
            cout << "Unable to reserve seat" << endl;

        }
    }
}
void Attendant::cancelSeat(Passenger& a) {
    if (a.getMySeatNum() != -1) {
        ticketSales--;
        int seatSerialNum = 0;
        BasicInfo basicInfo;
        a.getMyFlight().getFlightSeat(a.getMySeatNum()).setSeatAvail(true);
        a.getMyFlight().getFlightSeat(a.getMySeatNum()).setSeatInfo(basicInfo);
        
        a.setMySeatNum(-1);
        a.setMyFlight(routes[ROUTES_NUM]);
        cout << "Canceled seat for Passenger No. "<<a.getMyID() << ", " << a.getMyInfo().toString();
    } else {
        cout << "Unable to cancel seat, passenger appears to already have no seat";

    }
    //Setting the passenger's seat number to -1 indicates he has nowhere to sit and thus will not board the plane
}

string Attendant::displayMyFlight(Flight a) {
    stringstream b;
    b << a.displayPassengerInfo() << endl << a.displaySeatsAvailible() << endl;
    return b.str();
}
string Attendant::displayNextCustomer() {
    stringstream a;
    for (int x = 0; x < PASSENGER_NUM; x++) {
        if (customers[x].getMySeatNum() == -1) {
            a << customers[x].toString() << endl;
            break;
        }
    }
    return a.str();
}
string Attendant::displayUnbookedCustomers() {
    stringstream a;
    a << "Displaying Unbooked Customers: "<< endl;
    for (int x = 0; x < CUSTOMER_AMOUNT; x ++) {
        if (customers[x].getMySeatNum() == -1) {
            a << customers[x].toString() << endl;
        }
    }
    return a.str();
    
}
string Attendant::displayAllCustomerBySeatOrder(Flight a) {
    stringstream b;
    b << "\nFlight to: " <<a.getFlightDestination() << endl;
    for (int x = 0; x < SEAT_NUM; x++) {
        b << a.getFlightSeat(x).toString() << endl;
    }
    return b.str();
}
string Attendant::displayAllCustomerByAlphabeticOrder(Flight a) {
    stringstream b;
    string passengerNames[10];
    int passengerNamesOrder[10];
    for (int x = 0; x < SEAT_NUM; x++) {
        passengerNames[x] = a.getFlightSeat(x).getSeatInfo().getName();
        passengerNamesOrder[x] = x;
    }
    insertion_sort(passengerNames,passengerNamesOrder, SEAT_NUM);
    for (int x = 0; x < SEAT_NUM; x++) {
        b << a.getFlightSeat(passengerNamesOrder[x]).toString() << endl;
    }
    return b.str();
} //Not fully tested yet, may not work

void Attendant::cancelFlight(Flight& a) {
    for (int x = 0; x < SEAT_NUM; x++) {
        BasicInfo b;
        if (a.getFlightSeat(x).getSeatAvail() == false) {
        int customnerNum = a.getFlightSeat(x).getSeatInfo().getCustomerID();
        //cout << "Customer num : "<<customnerNum << endl;
        customers[customnerNum].setMyFlight(routes[ROUTES_NUM]);
        customers[customnerNum].setMySeatNum(-1);
        
        a.getFlightSeat(x).setSeatAvail(true);
        a.getFlightSeat(x).setSeatInfo(b);
        }


    }
}

void Attendant::autoAssignPassengers() {
    srand(static_cast<uint32_t>(time(0)));
    int flightNumCount = 0;
    int seatNumCount = 0;
    
    for (int x = 0; x < CUSTOMER_AMOUNT; x++) {
        if (rand()%100 <= 80) {
            if (customers[x].getMySeatNum() == -1) {
                reserveSeat(customers[x], routes[flightNumCount], seatNumCount);
                customers[x].setMySeatNum(seatNumCount);
            }
            
        }
        seatNumCount++;
        if (seatNumCount >= PLANE_SEATS) {
            seatNumCount = 0;
            flightNumCount++;
        } else if (flightNumCount == FLIGHTS_AMOUNT) {
            break;
        }
    }
    
}

string Attendant::displayAllInfoBySeatOrder() {
    stringstream a;
    
    for (int x = 0; x < ROUTES_NUM; x++) {
        a << displayAllCustomerBySeatOrder(routes[x]) << endl;
    }
    
    return a.str();
}

void Attendant::addCustomers(int a) {
    for (int x = CUSTOMER_AMOUNT; x < CUSTOMER_AMOUNT+a; x++) {
        BasicInfo a;
        a.setName(createInfoName());
        a.setAddress(createAddress());
        a.setPhoneNumber(createPhoneNumber());
        a.setCustomerID(x);
        customers[x] = Passenger(a, -1, routes[ROUTES_NUM], routeDestinations[rand()%5], x);
        
    }
    CUSTOMER_AMOUNT += a;
}

void Attendant::addSeats(int a) {
    
    int FLIGHT_TAG = ROUTES_NUM;
    string flightDestination = routeDestinations[rand()%10];
    for (int x = 0; x < SEAT_NUM; x++) {
        Seat a;
        
        //creates a blank BasicInfo object so that the seat has no relevant information.
        BasicInfo b;
        
        //The for loop above ensures the following code produces a unique seatID for every seat on the flight.
        a = Seat((FLIGHT_TAG*100) +x, true, b); //
        flightSeats[x] = a;
    }
    
    PLANE_SEATS += a;
}

void Attendant::addPlane(int a) {
    
    routes[ROUTES_NUM].setFlightDestination("UNBOOKED");
    for (int x = ROUTES_NUM; x < ROUTES_NUM+a; x++) {
        routes[x] = Flight(routeDestinations[rand()%10], x+1);
        
    }
    ROUTES_NUM += a;
    cout << routes[ROUTES_NUM-4].displayPassengerInfo() << " Test"<<  endl;
}


void insertion_sort (string arr[], int arr2[], int length){
    int j;
    string temp;
    int temp2;
    for (int i = 0; i < length; i++){
        j = i;
        while (j > 0 && arr[j] < arr[j-1]){
            temp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = temp;
            temp2 = arr2[j];
            arr2[j] = arr2[j-1];
            arr2[j-1] = temp2;
            j--;
        }
    }
}



















