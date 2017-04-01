
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


//int arrFace[52];
//int arrSuit[52];
class Card{
    
    
public:
    
    Card();
    Card(int face, int suit);
    ~Card();
    string toString();
    int FindFace();
    int FindSuit();
    void ChangeFace(int newFace);
    void ChangeSuit(int newSuit);
    void AsciiCard(string cardLine[]);
    
private:
    int face;
    int suit;

};

class DeckOfCards{
    
private:
    
    int length = 0;
    int currentCard = 0;
    const int SIZE_OF_DECK = 52;
    int intNextCard = 0;
    Card *deck = new Card[SIZE_OF_DECK];
    
    
public:
    DeckOfCards();
    void DeckConstruct(int SIZE_OF_DECK);
    void DeckDestruct();
    void shuffle(int size);
    Card NextCard();
    bool MoreCards();
    
    string DeckCardString(int SIZE_OF_DECK);
    
};

class Dealer {
    
private:
    Card player1[14] = {};
    Card player2[14] = {};
    Card table[5] = {};
    string cardLine[7];
    int playerWinner = 0;
    int money1 = 1000;
    int money2 = 1000;
    int finalBet = 0;
    bool Fold = false;
    bool FoldCards = false;
    bool endTriggered = false;

public:
    
    Dealer();
    string DealCards();
    DeckOfCards myDeckObj;
    void FindWinner();
    void SortCards(Card hands[]);
    void SortCardsSuit(Card hands[]);
    void AceToBig(Card player[]);
    void BetMoney();
    int getMoney1();
    int getMoney2();
    bool getFold();
    void Aftermath();
    void ThisIsTheEnd();
    bool getEndTriggered();
    
    int checkStraightFlush(Card player[]);
    int checkStraight(Card player[]);
    int checkFlush(Card player[]);
    int checkFourPair(Card player[]);
    int checkThreePair(Card player[]);
    int checkTwoPair(Card player[]);
    int checkHighCard(Card player[]);
    int checkHouse(Card player[]);
    int checkPairs(Card player[]);
    
    
};

#endif /* Header_h */
