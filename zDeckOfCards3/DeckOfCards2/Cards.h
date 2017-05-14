
//
//  Header.h
//  Assignment:DeckOfCards
//
//  Created by - on 2017/02/14.
//  Copyright © 2017 Eddie of the House of Ren. All rights reserved.
//

#ifndef Cards_h
#define Cards_h


using namespace std;

string arrFace[52];
string arrSuit[52];

class Card{
    
public:
    
    void Cards();
    void CardC(int face, int suit);
    
    string toString(Card);
    
private:
    int face;
    int suit;
    
};

class DeckOfCards{
    
private:
    
    int length = 0;
    int currentCard = 0;
    const int SIZE_OF_DECK = 52;
    
public:
    //Card *deck = new Card[SIZE_OF_DECK];
    //void DeckConstruct(int size);
    //void DeckDestruct(int size);
    //void shuffle();
    
    
    
    
    
};


#endif /* Header_h */
