//
//  GUI.cpp
//  Air Tycoon (Summative)
//
//  Created by - on 2017/04/24.
//  Copyright © 2017 Eddie of the House of Ren. All rights reserved.
//

#include "GUI.hpp"
#include <string>
#include <iostream>


GUI::GUI() {
    
}
//void GUI::setConstants() {
//    //Attendant e;
//    cout << "Please enter the amount of customers, and the number of flights separated by spaces" << endl;
//    int customerCin;
//    cin >> customerCin;
//    
//    CUSTOMER_AMOUNT = customerCin;
//    int routesCin;
//    cin >> routesCin;
//    
//    FLIGHTS_AMOUNT = routesCin;
//    cout << "Customer Amount: " << CUSTOMER_AMOUNT << " Flight AMount: " << FLIGHTS_AMOUNT << endl;
//    
//    Attendant e;
//    myAttendant = e;
//}

int GUI::guiController() {
    cout << "Please enter a letter from a-k to command the flight attendant, enter z to quit" << endl;
    string myIn;
    cin >> myIn;
    if (myIn == "a") {
        cout << "Displaying All Routes --> displayRoutes()" << endl;
        cout << myAttendant.displayRoutes() << endl;
        
    } else if (myIn == "b") {
        cout << "Researving A Seat --> reserveSeat(Passenger& a, Flight& b, int c)" << endl;
        cout << "Please enter a passenger number from 0 to " << CUSTOMER_AMOUNT << " and a flight number from 0 to " << FLIGHTS_AMOUNT << " and finally the seat number from 0 to 10. Separate these 3 values by spaces" << endl;
        int pNum = 0;
        int fNum = 0;
        int sNum = 0;
        cin >> pNum;
        cin >> fNum;
        cin >> sNum;
        myAttendant.reserveSeat(myAttendant.getCustomers(pNum), myAttendant.getRoutes(fNum), sNum);

    } else if (myIn == "c") {
        cout << "Cancelling A Seat --> cancelSeat(Passenger& a)" << endl;
        cout << "Please enter a passenger number from 0 to " << CUSTOMER_AMOUNT << endl;
        int pNum = 0;
        cin >> pNum;
        myAttendant.cancelSeat(myAttendant.getCustomers(pNum));
        
    } else if (myIn == "d") {
        cout << "Displaying A Flight --> displayMyFlight(Flight a)" << endl;
        cout << "Please enter a flight number form 0 to " << FLIGHTS_AMOUNT << endl;
        int fNum = 0;
        cin >> fNum;
        cout << myAttendant.displayMyFlight(myAttendant.getRoutes(fNum)) << endl;
        
    } else if (myIn == "e") {
        cout << "Displaying A Flight --> displayNextCustomer()" << endl;
        cout <<myAttendant.displayNextCustomer() << endl;
        
    } else if (myIn == "f") {
        cout << "Displaying Unbooked Passengers--> displayUnbookedCustomers()" << endl;
        cout << myAttendant.displayUnbookedCustomers() << endl;
        
    } else if (myIn == "g") {
        cout << "Displaying Customers By Seat Order--> displayAllCustomerBySeatOrder(Flight a)" << endl;
        cout << "Please enter a flight number form 0 to " << FLIGHTS_AMOUNT << endl;
        int fNum = 0;
        cin >> fNum;
        cout << myAttendant.displayAllCustomerBySeatOrder(myAttendant.getRoutes(fNum)) << endl;
        
    } else if (myIn == "h") {
        cout << "Displaying Customers By Alphabetical Order--> displayAllCustomerByAlphabeticOrder(Flight a)" << endl;
        cout << "Please enter a flight number form 0 to " << FLIGHTS_AMOUNT << endl;
        int fNum = 0;
        cin >> fNum;
        cout << myAttendant.displayAllCustomerByAlphabeticOrder(myAttendant.getRoutes(fNum)) << endl;

    } else if (myIn == "i") {
        cout << "Displaying All Info By Seat Order--> displayAllInfoBySeatOrder()" << endl;
        cout << myAttendant.displayAllInfoBySeatOrder() << endl;

        
    } else if (myIn == "j") {
        cout << "Cancelling A Flight--> cancelFlight(Flight& a)" << endl;
        cout << "Please enter a flight number form 0 to " << FLIGHTS_AMOUNT << endl;
        int fNum = 0;
        cin >> fNum;
        myAttendant.cancelFlight(myAttendant.getRoutes(fNum));

        
    } else if (myIn == "k") {
        cout << "Autoassigning Passengers--> autoAssignPassengers()" << endl;
        myAttendant.autoAssignPassengers();
        
    } else if (myIn == "l") {
        cout << "Displaying Ticket Sales--> getTicketSales()" << endl;
        cout << myAttendant.getTicketSales();
        
    } else if (myIn == "m") {
        cout << "Setting Ticket Sales--> setTicketSales(int a)" << endl;
        cout << "Please enter the desired number of Ticket Sales" << endl;
        int tNum = 0;
        cin >> tNum;
        myAttendant.setTicketSales(tNum);
        
    } else if (myIn == "z") {
        cout << "Thank you for flying with us!" << endl;
        return 1; //Returns 1 to stop the loop
    } 
    cout << "\n\n\n" << endl; //Makes separate commands more distinct
    return 0; //Returns 0 to continue looping
    
}


