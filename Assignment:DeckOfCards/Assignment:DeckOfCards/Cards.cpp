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
#include <ctime>

using namespace std;

string Card::toString(Card){
    
    stringstream a ;
    a << Card::face << "of" << Card::suit;
    return a.str();
    
    return "opih";
    
}


Card::Card(int face, int suit) {
    
    Card::face = face;
    Card::suit = suit;
    
}

void DeckOfCards::DeckConstruct(int size){
    
    srand((unsigned)(time(0)));
    for (int x = 0; x < size; x++) {
        deck[x] = new Card::Card(rand()%52, rand()%4);
        
        
    }
    
}
