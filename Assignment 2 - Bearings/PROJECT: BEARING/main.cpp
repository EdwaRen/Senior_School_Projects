//
//  main.cpp
//  Assignment 2 - Bearings
//
//  Created by - on 2016/09/27.
//  Copyright © 2016 Eddie Of the Ren. All rights reserved.
//
#include <iostream>
//#include "stdafx.h"
using namespace std;
#include <stdio.h>      /* printf */
#include <math.h>
//#include <boost/lexical_cast.hpp>
#include <string>

int cardinalNum1 = 0;
int cardinalNum2 = 0;

//This function converts the cardinal string to a number that can fit in an array
int cardinalStrToNum(string cardinalStr) {
    int cardinalNum = 0;
    if (cardinalStr== "N") {
        cardinalNum = 2;
    } else if (cardinalStr == "E") {
        cardinalNum = 3;
    } else if (cardinalStr == "S") {
        cardinalNum = 4;
    } else if (cardinalStr == "W") {
        cardinalNum = 5;
    }
    return cardinalNum;
    
}

//This checks if a string is a number that is composed only of "-.0123456789"
bool is_number(const std::string& s)
{
    return( strspn( s.c_str(), "-.0123456789" ) == s.size() );
}

//If the user enters a bearing that is not within 0 to 359, this converts it to within that limit
int getBearing(int x) {
    double customBearing = 0;
    //Turning negative values positive
    while (x < 0) {
        x = x + 360;
    }
    //Turning overweight values smaller
    while (x >= 360) {
        x = x - 360;
    }
    customBearing = x;
    
    return (customBearing);
}

//This function will accept a bearing direction and turn it into a compass direction
int bearingToCompass(double bearing, string gameChoice) {
    double choiceInt = 0;
    
    int quadrant = 0;
    bool CW = false;
    string cardinals [6] = {"W", "N", "E", "S", "W", "N"};
    
    //getBearing will convert the user entered value into a value between 1 and 360, discrimination is currently enforced to favor 0° over 360°
    
    //These two lines turn the bearing into a value between 0 and 359 and finds the inverse quadrant it resides in. The quadrants are counted clockwise, NOT counter-clockwise
    bearing = getBearing(bearing);
    quadrant = floor(bearing/90);
    
    //If this if statement is true, that means the degree applies in a clockwise direction relative to the first cardinal. Ex: N32E. the direciton is 32 east (clockwise) FROM north
    if ((bearing - 90*quadrant) <45) {
        CW = false;
        cout << cardinals[(quadrant + 1)] << (bearing - 90*quadrant) << cardinals[(quadrant+2)] <<endl;
        if (gameChoice == "1") {
            
            cout << "Primary compass direction:             " << cardinals[(quadrant + 1)] << endl;
            cout << "Compass angle relative to direction:   " << (bearing - 90*quadrant) << endl;
            cout << "Secondary compass direction:           " << cardinals[(quadrant+2)]<< endl;
        }
    
    }
    //If this if statement is true, that means the degree applies in a counter-clockwise direction relative to the first cardinal. Ex: N65E. The direction is 65 north (counterclockwise) FROM east. This is equivalent to E25N which is a better way of representing the direction.
    else if ((bearing - 90*quadrant) >45) {
        CW = true;
        cout << cardinals[(quadrant + 2)] << (90-(bearing - 90*quadrant)) << cardinals[(quadrant+1)] <<endl;
        
        if (gameChoice == "1") {
            cout << "Primary compass direction:             " << cardinals[(quadrant + 2)] << endl;
            //The line of code below ensures that the angle is between 1° and 44°
            cout << "Compass angle                          " << (90-(bearing - 90*quadrant)) << "°" <<     endl;
            cout << "Secondary compass direction:           "<< cardinals[(quadrant+1)]<< endl;
        }
    }
    //When the angle is 45° or exactly between two cardinals, the bearing is not displayed
    else if ((bearing - 90*quadrant) == 45) {
        cout << cardinals[(quadrant + 1)]  << cardinals[(quadrant+2)] <<endl;
        
        if (gameChoice == "1") {
            cout << "Primary compass direction:             " << cardinals[(quadrant + 1)] << endl;
            cout << "Compass angle relative to direction:   " << endl;
            cout << "Secondary compass direction:           " << cardinals[(quadrant+2)]<< endl;
        }
    }
    
    //cout << cardinals[(quadrant+1)] << endl;
    //cout << bearing<< endl;
    return 0;
    
}

//This functions checks the cardinals and angle the user entered are valid or not.
bool cardinalCheck (string primaryCardinal, string secondaryCardinal, string angleStr) {
    bool redo = false;
    if (primaryCardinal != "N"&& primaryCardinal!= "E" && primaryCardinal != "W" && primaryCardinal != "S") {
        redo = true;
        cout << "Your primary cardinal direciton is not one of N, E, S, W " << endl;
    } else if (secondaryCardinal != "N"&& secondaryCardinal!= "E" && secondaryCardinal != "W" && secondaryCardinal != "S") {
        redo = true;
        cout << "Your secondary cardinal direciton is not one of N, E, S, W " << endl;
    } else if (is_number(angleStr) == 0)  {
        redo = true;
        cout << "Your angle is not a number " << endl;
    } else {
        //following statements ensure that the user has not entered two identical or opposite cardinals, such as N20N or N20S
        cardinalNum1 = cardinalStrToNum(primaryCardinal);
        cardinalNum2 = cardinalStrToNum(secondaryCardinal);
        if (cardinalNum1 - cardinalNum2 >= 0) {
            if ((cardinalNum1-cardinalNum2)%2 == 0) {
                redo = true;
                cout<< "These coordinates are invalid"<< endl;
            }
        } else if (cardinalNum1 - cardinalNum2 < 0) {
            if ((-(cardinalNum1-cardinalNum2))%2 == 0) {
                redo = true;
                cout<< "These coordinates are invalid"<< endl;
            }
        }
    }
    return redo;
}


//This is the main function
int main() {
    
    //Getting user to choose which game mode to play
    cout << "You have been unfortunately chosen by the OCDSB to mark Eddie's compass project" << endl;
    cout << "" << endl;
    cout << "To begin choose whether you want to play in:" << endl;
    cout << "     ENTER 1 to play in BEARING mode (bearing to compass)" << endl;
    cout << "     ENTER 2 to play in COMPASS mode (compass to bearing, one step)" << endl;
    cout << "     ENTER 3 to play in COMPASS mode (compass to bearing, three step)" << endl;
    
    
    string gameChoice = "3";
    bool correctInput = false;
    cin >> gameChoice;
    
    do  {
        //This do while loop ensures that the user has entered a value between 1 and 3
        if ((gameChoice == "1") || (gameChoice == "2" || gameChoice == "3")) {
            correctInput = true;
        } else {
            cout << "You have not entered a valid input, please try again" << endl;
            cin >> gameChoice;
        }
        cout << correctInput << endl;
    } while (correctInput == false);
    
    if (gameChoice == "3") {
        //These are the critical variable inputs
        string primaryCardinal = "derp";
        string angleStr = "derp";
        string secondaryCardinal = "derp";
        
        double angle;
        double originalAngle = 0;
        bool redo = false;
        
        do {
            //Asks the user for necessary inputs and checks the inputs to see if they are valid
            cout <<"Please enter your compass direction: " << endl;
            cin >> primaryCardinal;
            cout <<"Please enter your angle: " << endl;
            cin >> angleStr;
            cout <<"Please enter your secondary direciton: " << endl;
            cin >> secondaryCardinal;
            
            redo = cardinalCheck(primaryCardinal, secondaryCardinal, angleStr);
            
        } while (redo == true);
        
        //Some necessary calculations
        angle = stod(angleStr);
        angle = getBearing(angle);
        originalAngle = angle;
        cout << angle << endl;
        string cardinals [6] = {"W", "N", "E", "S", "W", "N"};
        int cardinalNumSave = 0;
        
        //Turns the cardinals into bearing values
        if (secondaryCardinal == cardinals[cardinalNum1]) {
            angle = ((cardinalNum1-2)*90) + angle;
        } else if (secondaryCardinal == cardinals[cardinalNum1-2]) {
            angle = ((cardinalNum1-2)*90) - angle;
        } else {
            cout << "Something went here calculating the bearing angle" << endl;
        }
        //Makes sure the bearing values are between 0° and 359°
        angle = getBearing(angle);
        cout << "Your bearing is "<<angle<< "°C right fron North. Your direction is:  "<< bearingToCompass(angle, gameChoice)<< endl;
        
    } else if (gameChoice == "2") {
        
        cout << "You have been unfortunately chosen by the OCDSB to mark Eddie's compass project" << endl;
        bool redo = false;
        string directionStr = "bleBLERPBLERPrp";
        string primaryCardinal = "blerp";
        string secondaryCardinal = "blBLERPerp";
        string angleStr = "0";
        double angle = 0;
        
        
        do {
            //Gets input for the direction
            cout << "Please enter your direction in the form of N40E starting with a cardinal, bearing and secondary cardinal." << endl;
            cin >> directionStr;
            
            //Segments this direction into cardinals and angle
            primaryCardinal = directionStr[0];
            secondaryCardinal = directionStr[directionStr.length()-1];
            angleStr = directionStr.substr(1, directionStr.length()-2);
            
            //Checks if these are valid entries
            redo = cardinalCheck(primaryCardinal, secondaryCardinal, angleStr);
        } while (redo == true);
        
        angle = stod(angleStr);
        angle = getBearing(angle);
        double originalAngle = angle;
        cout << angle << endl;
        string cardinals [6] = {"W", "N", "E", "S", "W", "N"};
        int cardinalNumSave = 0;
        
        //Converts cardinals to proper angle measures which are added to the inputted angle
        if (secondaryCardinal == cardinals[cardinalNum1]) {
            angle = ((cardinalNum1-2)*90) + angle;
        } else if (secondaryCardinal == cardinals[cardinalNum1-2]) {
            angle = ((cardinalNum1-2)*90) - angle;
        } else {
            cout << "Something went here calculating the bearing angle" << endl;
        }
        //Makes sure the bearing is between 0° and 359°
        angle = getBearing(angle);
        
        //Outputs the bearing and a correct direction
        cout << "Your bearing is "<<angle<< "°C right fron North. Your direction is:  "<< bearingToCompass(angle, gameChoice)<< endl;
        
    } else if (gameChoice == "1") {
        cout << "Please enter your bearing in degrees"<< endl;
        double bearing = 0;
        string bearingStr = "hi";
        
        do {
            //Gets user to input a bearing and checks if it is a number
            cin >> bearingStr;
            if (is_number(bearingStr) == 0) {
                cout << "You have not entered a numeric value for the bearing, please try again my friend" << endl;
            }
        } while (is_number(bearingStr) == 0);
        std::string str = "3.14";
        double strVal;
        
        bearing = stod(bearingStr);
        cout << bearing << endl;
        //Converts bearing to compass direction
        bearingToCompass(bearing, gameChoice);
        
        
        //cin >> gameChoice;
        
        return 0;
    }
}
