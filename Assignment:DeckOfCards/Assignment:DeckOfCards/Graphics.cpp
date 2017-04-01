//
//  Graphics.cpp
//  Assignment:DeckOfCards
//
//  Created by - on 2017/03/02.
//  Copyright © 2017 Eddie of the House of Ren. All rights reserved.
//

#include "Cards.h"

using namespace std;


void Card::asciiCard()
{
    
        string facevalue = face;
        
        
        char32_t heart;
        string line1;
        //line1 = &"Sad" [ facevalue] + "dsa";
        cardLine[0] += "_____  ";
        cardLine[1] += "|" + facevalue + "   | ";
        cardLine[5] += "`----` ";
        
        if (suitvalue == 3) {
            cardLine[2] += "|(\\/)| ";
            cardLine[3] += "| \\/ | ";
            cardLine[4] += "|   " + facevalue + "| ";
        } else if (suitvalue == 0) {
            //spades
            cardLine[2] += "| /\\ | ";
            cardLine[3] += "|(__)| ";
            cardLine[4] += "| /\\" + facevalue + "| ";
        } else if (suitvalue == 1) {
            //spades
            cardLine[2] += "| /\\ | ";
            cardLine[3] += "| \\/ | ";
            cardLine[4] += "|   " + facevalue + "| ";
        } else if (suitvalue == 2) {
            //spades
            cardLine[2] += "| &  | ";
            cardLine[3] += "|&|& | ";
            cardLine[4] += "| | " + facevalue + "| ";
        } else {
            
            cout << suitvalue << ": " << facevalue << "<-- THis thing (suitvalue) got messed up (suit:face) " << endl;
        }
    } else {
        cardLine[0] += "_____  ";
        cardLine[1] += "|----| ";
        cardLine[2] += "|----| ";
        cardLine[3] += "|FOLD| ";
        cardLine[4] += "|----| ";
        cardLine[5] += "`----` ";
    }
    
    
}
