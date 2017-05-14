//
//  Cards.cpp
//  Assignment:DeckOfCards
//
//  Created by - on 2017/02/14.
//  Copyright © 2017 Eddie of the House of Ren. All rights reserved.
//

#include <iostream>
#include <string>
#include "Cards.h"
#include <sstream>

using namespace std;

string Card::toString(Card){
    
    //stringstream a ;
    //a << Card::face << "of" << Card::suit;
    //return a.str();
    
    return "opih";
    
}


void Card::CardC(int face, int suit) {
    
    Card::face = face;
    Card::suit = suit;
    
}
