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
#include "Constants.h"

class Attendant {
private:
    int ROUTES_NUM = FLIGHTS_AMOUNT;
    int SEAT_NUM = PLANE_SEATS;
    int PASSENGER_NUM = CUSTOMER_AMOUNT;
    Flight *routes = new Flight[ROUTES_NUM+1];
    Passenger *customers = new Passenger[PASSENGER_NUM];
    int ticketSales = 0;
    string routeDestinations[10] = {"Ottawa", "Toronto", "Windsor", "Waterloo", "Vancouver", "Saskatoon", "Calgary", "Mont-Royal", "Halifax", "Edmonton"};
public:
    
    Attendant();
    Attendant(int TicketSales);
    int getTicketSales();                   //l
    Passenger& getCustomers(int a);         //Not needed for GUI
    Flight& getRoutes(int a);               //Not needed for GUI
    void setTicketSales(int a);             //m
    void setCustomers(Passenger& a, int b); //Not needed for GUI
    void setRoutes(Flight& a, int b);       //Not needed for GUI
    
    void addTicketSale();                           //Automatically called within another function
    void cancelTicketSale();                        //Automatically called within another function
    string displayRoutes();                             //a)
    void reserveSeat(Passenger& a, Flight& b, int c);   //b)
    void cancelSeat(Passenger& a);                      //c)
    string displayMyFlight(Flight a);                   //d)
    string displayNextCustomer();                       //e)
    string displayUnbookedCustomers();                  //f)
    string displayAllCustomerBySeatOrder(Flight a);         //g)
    string displayAllCustomerByAlphabeticOrder(Flight a);   //h)
    string displayAllInfoBySeatOrder();                     //i)
    void cancelFlight(Flight& a);                           //j)
    void autoAssignPassengers();                            //k)
    
    
    //z For exit
    
};


#endif /* Attendant_hpp */
