//
//  Attendant.hpp
//  Air Tycoon (Summative)
//
//  Created by - on 2017/04/18.
//  Copyright © 2017 Eddie of the House of Ren. All rights reserved.
//

#ifndef Attendant_hpp
#define Attendant_hpp

#include <stdio.h>
#include "Seat.hpp"
#include "Flight.hpp"
#include "Passenger.hpp"

class Attendant {
private:
    int ROUTES_NUM = 3;
    int SEAT_NUM = 10;
    int PASSENGER_NUM = 11;
    Flight *routes = new Flight[ROUTES_NUM+1];
    Passenger *customers = new Passenger[PASSENGER_NUM];
    int ticketSales = 0;
    string routeDestinations[10] = {"Ottawa", "Toronto", "Windsor", "Waterloo", "Vancouver", "Saskatoon", "Calgary", "Mont-Royal", "Halifax", "Edmonton"};
public:
    
    Attendant();
    Attendant(int TicketSales);
    int getTicketSales();
    Passenger& getCustomers(int a);
    Flight& getRoutes(int a);
    void setTicketSales(int a);
    void setCustomers(Passenger& a, int b);
    void setRoutes(Flight& a, int b);
    
    void addTicketSale();
    void cancelTicketSale();
    string displayRoutes();
    void reserveSeat(Passenger& a, Flight& b, int c);
    void cancelSeat(Passenger& a, Flight& b, int c);
    string displayMyFlight(Flight a);
    string displayNextCustomer();
    string displayAllCustomerBySeatOrder(Flight a);
    string displayAllCustomerByAlphabeticOrder(Flight a);
    void cancelFlight(Flight& a);
    void reaccomodatePassengers(Flight& a);
    
    
};


#endif /* Attendant_hpp */
