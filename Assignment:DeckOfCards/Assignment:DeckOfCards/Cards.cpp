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

string Card::toString(){
    
    stringstream a ;
    stringstream b;
    stringstream c;
    if (face <= 9){
        b <<face + 1;
    } else if (face == 10){
        b << "J";
    } else if (face == 11) {
        b << "Q";
    } else if (face == 12) {
        b << "K";
    } else if (face == 50) {
        b << "N";
    } else if (face == 1 or face == 13) {
        b << "A";
    }
    
    if (suit == 0) {
        c << "Hearts";
    } else if (suit == 1) {
        c << "Diamonds";
    } else if (suit == 2) {
        c << "Spades";
    } else if (suit == 3) {
        c << "Clover";
    }
    
    a << b.str() << " of " << c.str();
    return a.str();
    
    return "opih";
    
}
Card::Card() {
    
}

Card::~Card() {
    
}


Card::Card(int face, int suit) {
    
    Card::face = face;
    Card::suit = suit;
    
}

void Card::ChangeFace(int newFace) {
    
    face = newFace;
    
}

void Card:: ChangeSuit(int newSuit) {
    
    suit = newSuit;
    
}

int Card::FindFace() {
    int a;
    a = face;
    return a;
    
}

int Card::FindSuit() {
    
    return suit;
}

void Card::AsciiCard(string cardLine[])
{
    
    string facevalue;
    facevalue = to_string(face + 1);
    if (facevalue == "10") {
        facevalue = "X";
    } else if (facevalue == "11") {
        facevalue = "J";
    }   else if (facevalue == "12") {
        facevalue = "Q";
    }   else if (facevalue == "13") {
        facevalue = "K";
    }   else if (facevalue == "1" or facevalue == "14") {
        facevalue = "A";
    }
    
    
    string line1;
    //line1 = &"Sad" [ facevalue] + "dsa";
    cardLine[0] += "_____  ";
    cardLine[1] += "|" + facevalue + "   | ";
    cardLine[5] += "`----` ";
    
    if (suit == 0) {
        cardLine[2] += "|(\\/)| ";
        cardLine[3] += "| \\/ | ";
        cardLine[4] += "|   " + facevalue + "| ";
    } else if (suit == 2) {
        //spades
        cardLine[2] += "| /\\ | ";
        cardLine[3] += "|(__)| ";
        cardLine[4] += "| /\\" + facevalue + "| ";
    } else if (suit == 1) {
        //spades
        cardLine[2] += "| /\\ | ";
        cardLine[3] += "| \\/ | ";
        cardLine[4] += "|   " + facevalue + "| ";
    } else if (suit == 3) {
        //spades
        cardLine[2] += "| &  | ";
        cardLine[3] += "|&|& | ";
        cardLine[4] += "| | " + facevalue + "| ";
    } else {
        
        cout << suit << ": " << face << "<-- THis thing (suitvalue) got messed up (suit:face) " << endl;
    }


}


DeckOfCards::DeckOfCards() {
    
}

void DeckOfCards::DeckConstruct(int SIZE_OF_DECK){
    
    srand((unsigned)(time(0)));
    int sumCount = 0;
    for (int x = 0; x < 13; x++) {
        for (int i= 0; i < 4; i++)
        {
            deck[sumCount] = Card(x, i);
            sumCount++;
        }
        
    }
    
    
}

void DeckOfCards::DeckDestruct(){

    delete[] deck;
    
}




string DeckOfCards::DeckCardString(int size){
    
    stringstream a ;
    
    for (int x = 0; x<size; x++) {
        a << deck[x].toString() << endl;
    }
    
    
    return a.str();
    
    
}

void DeckOfCards::shuffle(int size) {
    cout << "Assistant: Everyday I'm shufflin! "<< endl;
    srand(static_cast<uint32_t>(time(0)));
    
    for (int x = 0; x < size ; x++) {
        
        int k;
        k = rand()%size;
        
        Card c;
        c = deck[x];
        deck[x] = deck[k];
        deck[k] = c;
        
        
        
    }
    cout << endl;

}

Card DeckOfCards::NextCard(){
    //stringstream a;
    //a << deck[intNextCard].toString() ;
    Card a;
    a = deck[intNextCard];
    
    intNextCard++;
    if (intNextCard == SIZE_OF_DECK-1){
        intNextCard = 0;
    }
    
    return a;
    
    
}

bool DeckOfCards::MoreCards() {
    bool a = false;
    
    
    if (intNextCard == SIZE_OF_DECK-1){
        intNextCard = 0;
        a = true;
    }
    
    
    return a;
}

Dealer:: Dealer() {
    cout << "Dealer: Love. Game. Intuition. Play the cards with spades to start\n" << endl;
    myDeckObj.DeckConstruct(52);
    myDeckObj.shuffle(52);
    //cout << "Heres the deck: \n"<<myDeckObj.DeckCardString(52) << endl;
    
}

string Dealer:: DealCards() {
    stringstream a;
    a <<"\nTable:" << endl;
    {
        for (int x = 0; x < 5; x++) {
            table[x] = myDeckObj.NextCard();
            table[x].AsciiCard(cardLine);
            
        }
        for (int x = 0; x<7; x++) {
            a << cardLine[x] << endl;
            cardLine[x] = "";
        }
    }
    {
        a << "Player 1:" << endl;
        for (int x = 0; x < 5; x++) {
            player1[x] = myDeckObj.NextCard();
            player1[x+5] = table[x];
            player1[x].AsciiCard(cardLine);
        }
        for (int x = 0; x<7; x++) {
            a << cardLine[x] << endl;
            cardLine[x] = "";
        }
    }
    {
        a <<"Player 2:" << endl;
        for (int x = 0; x < 5; x++) {
            player2[x] = myDeckObj.NextCard();
            player2[x+5] = table[x];
            player2[x].AsciiCard(cardLine);
        }
        for (int x = 0; x<7; x++) {
            a << cardLine[x] << endl;
            cardLine[x] = "";
        }
    }
    return a.str();
    
}

void Dealer::AceToBig(Card player[]) {
    int count = 1;
    for (int x = 0; x< 4; x++) {
        player[10+x] = Card(50, 50);
    }
    for (int x = 0; x < 10; x++) {
        if (player[x].FindFace() == 0) {
            player[9+count].ChangeFace(13);
            player[9+count].ChangeSuit(player[x].FindSuit());
            count++;
        }
    }
}

void Dealer::FindWinner() {
    
    string winner;
    SortCards(player1);
    SortCards(player2);
    AceToBig(player1);
    AceToBig(player2);
    cout << " " << endl;
    for (int x = 0; x < 14; x++) {
        //cout << player1[x].FindFace() << " ";
    }
    SortCardsSuit(player1);
    //cout << endl;
    for (int x = 0; x < 14; x++) {
        //cout << player1[x].FindFace() << " ";
    }
    //cout << endl;
    for (int x = 0; x < 14; x++) {
        //cout << player1[x].FindSuit() << " ";
    }
    SortCards(player1);
    //cout << "\nprinting player2 " << endl;
    for (int x = 0; x < 14; x++) {
        //cout << player2[x].FindFace() << " ";
    }
    /*
    cout << "\nSF" << endl;
    cout << checkStraightFlush(player1) << endl;
    cout << checkStraightFlush(player2) << endl ;
    cout << "\n4p" << endl;
    cout << checkFourPair(player1) << endl;
    cout << checkFourPair(player2) << endl;
     
    cout << "\nFH" << endl;
    cout << "FH: "<<checkHouse(player1) << endl;
    cout << "FH: "<< checkHouse(player2) << endl;
    
    cout << "\nF" << endl;
    cout << "FL: "<< checkFlush(player1) << endl;
    cout << "FL: "<< checkFlush(player2) << endl;
    
    cout << "\nS" << endl;
    cout << "S1: " <<checkStraight(player1) << endl;
    cout << "S2: " << checkStraight(player2) << endl;
    
    cout << "\n3p" << endl;
    cout << checkThreePair(player1) << endl;
    cout << checkThreePair(player2) << endl;
    cout << "\nps" << endl;
    cout << checkPairs(player1) << endl;
    cout << checkPairs(player2) << endl;
    cout << "\n2p" << endl;
    cout << checkTwoPair(player1) << endl;
    cout << checkTwoPair(player2) << endl;
    */
    
    int SF1 = checkStraightFlush(player1);
    int SF2 = checkStraightFlush(player2);
    int P41 = checkFourPair(player1);
    int P42 = checkFourPair(player2);
    int FH1 = checkHouse(player1);
    int FH2 = checkHouse(player2);
    int FL1 = checkFlush(player1);
    int FL2 = checkFlush(player2);
    int ST1 = checkStraight(player1);
    int ST2 = checkStraight(player2);
    int P31 = checkThreePair(player1);
    int P32 = checkThreePair(player2);
    int PS1 = checkPairs(player1);
    int PS2 = checkPairs(player2);
    int P21 = checkTwoPair(player1);
    int P22 = checkTwoPair(player2);


    
    if ((SF1) > (SF2)) {
        winner = "Player 1 won with a straight flush";
        playerWinner = 1;
    } else if ((SF1) < (SF2)) {
        winner = "Player 2 won with a straight flush";
        playerWinner = 2;
    } else if (SF1 == (SF2) and SF2 != -1) {
        playerWinner = 0;
    } else {
        
        if ((P41) > (P42)) {
            winner = "Player 1 won with a four pair";
            playerWinner = 1;
        } else if (P41 < (P42)) {
            winner = "Player 2 won with a four pair";
            playerWinner = 2;
        } else if ( P41 == P42 and P41 != -1) {
            playerWinner = 0;
        } else {
            
            if ((FH1) > (FH2)) {
                winner = "Player 1 won with a full house";
                playerWinner = 1;
            } else if ((FH1) < (FH2)) {
                winner = "Player 2 won with a full house";
                playerWinner = 2;
            } else if (FH1 == FH2 and FH2 != -1) {
                playerWinner = 0;
            } else {
                
                if ((FL1) > (FL2)) {
                    winner = "Player 1 won with a flush";
                    playerWinner = 1;
                } else if ((FL1) < (FL2)) {
                    winner = "Player 2 won with a flush";
                    playerWinner = 2;
                } else if (FL1 == FL2 and FL2 != -1) {
                    playerWinner = 0;
                } else {
                    
                    if ((ST1) > (ST2)) {
                        winner = "Player 1 won with a straight";
                        playerWinner = 1;
                    } else if ((ST1) < (ST2)) {
                        winner = "Player 2 won with a straight";
                        playerWinner = 2;
                    } else if (ST1 == ST2 and ST2 != -1) {
                        playerWinner = 0;
                    } else {
                        
                        if ((P31) > (P32)) {
                            winner = "Player 1 won with a three pair";
                            playerWinner = 1;
                        } else if ((P31) < (P32)) {
                            winner = "Player 2 won with a three pair";
                            playerWinner = 2;
                        } else if (P31 == P32 and P31 != -1) {
                            playerWinner = 0;
                        } else {
                            
                            if ((PS1) > (PS2)) {
                                winner = "Player 1 won with two pairs";
                                playerWinner = 1;
                            } else if ((PS1) < (PS2)) {
                                winner = "Player 2 won with two pairs";
                                playerWinner = 2;
                            }else if (PS1 == PS2 and PS2 != -1) {
                                playerWinner = 0;
                            } else {
                                
                                if ((P21) > (P22)) {
                                    winner = "Player 1 won with a two pair";
                                    playerWinner = 1;
                                } else if ((P21) < (P22)) {
                                    winner = "Player 2 won with a two pair";
                                    playerWinner = 2;
                                } else if (P21 == P22 and P22 != -1) {
                                    playerWinner = 0;
                                } else {
                                    
                                    if (checkHighCard(player1) > checkHighCard(player2)) {
                                        winner = "Player 1 won with high card";
                                        playerWinner = 1;
                                    } else if (checkHighCard(player1) < checkHighCard(player2)) {
                                        winner = "Player 2 won with high card";
                                        playerWinner = 2;
                                    } else {
                                        playerWinner = 0;
                                    }
                                    
                                }
                                
                            }
                            
                        }
                        
                    }
                    
                    
                }
                
            }
            
            
        }
        
    }
    if (playerWinner == 0) {
        winner = "Tied";
    }
    cout << winner << endl;
    
    
}

void Dealer::SortCards(Card hands[]) {
    int pos_min;
    Card temp;
    for (int i=0; i < 9; i++) {
        pos_min = i;//set pos_min to the current index of array
        for (int j=i+1; j < 10; j++) {
            if (hands[j].FindFace() < hands[pos_min].FindFace()){
                pos_min=j;
            }
        }
        if (pos_min != i) {
            temp = hands[i];
            hands[i] = hands[pos_min];
            hands[pos_min] = temp;
        }
    }
}
void Dealer::SortCardsSuit(Card hands[]) {
    int n,i,j;
    Card temp;
    for(i=1;i<14;++i) {
        for(j=0;j<(14-i);++j)
            if(hands[j].FindSuit()>hands[j+1].FindSuit()) {
                temp=hands[j];
                hands[j]=hands[j+1];
                hands[j+1]=temp;
            }
    }
}


int Dealer::checkStraight(Card player[]) {
    int highest = -1;
    
    for (int x = 0; x <=5 ; x++ ) {
        int counts[5] = {0, 1, 2, 3, 4};

        int a = player[x].FindFace();
        int b = player[x+counts[1]].FindFace();
        int c = player[x+counts[2]].FindFace();
        int d = player[x+counts[3]].FindFace();
        int e = player[x+counts[4]].FindFace();

        while (a==b and a != 50) {
            counts[1]++;counts[2]++;counts[3]++;counts[4]++;
            b = player[x+counts[1]].FindFace();
            c = player[x+counts[2]].FindFace();
            d = player[x+counts[3]].FindFace();
            e = player[x+counts[4]].FindFace();
            if (a != b) {
                break;
            }

        }
        while (b == c and c != 50) {
            counts[1]++;counts[2]++;counts[3]++;
            c = player[x+counts[2]].FindFace();
            d = player[x+counts[3]].FindFace();
            e = player[x+counts[4]].FindFace();

        }
        while (c == d and d != 50) {
            counts[3]++;counts[4]++;
            d = player[x+counts[3]].FindFace();
            e = player[x+counts[4]].FindFace();

        }
        while ( d == e and e != 50) {
            counts[4]++;
            e = player[x+counts[4]].FindFace();

        }
        //cout << endl;
        for (int i = 0 ; i < 14; i++) {
            //cout << player[i].FindFace() << " ";
        }
        //cout << endl;
        //cout << a << " " << b << " " << c << " " << d << " " << e << endl;
        
        if (b-a == 1 and c-b == 1 and d-c == 1 and e-d == 1) {
            
            highest = e;
        }
    }
    return highest;
    
}

int Dealer::checkFlush(Card player[]) {
    int highest = -1;
    SortCardsSuit(player);
    for (int x = 0; x <= 6; x++) {
        int a = player[x].FindSuit();
        int b = player[x+1].FindSuit();
        int c = player[x+2].FindSuit();
        int d = player[x+3].FindSuit();
        int e = player[x+4].FindSuit();
        
        if (a == b and b == c and c == d and d == e) {
            if (player[x].FindFace()!=0 and player[x+4].FindFace()!=13){
                highest = player[x+4].FindFace();
            }
        }
    }
    SortCards(player);
    return highest;
}

int Dealer::checkStraightFlush(Card player[]) {
    int highest = -1;
    for (int x = 0; x <=5 ; x++ ) {
        int counts[5] = {0, 1, 2, 3, 4};

        int a = player[x].FindFace();
        int b = player[x+counts[1]].FindFace();
        int c = player[x+counts[2]].FindFace();
        int d = player[x+counts[3]].FindFace();
        int e = player[x+counts[4]].FindFace();
        
        while (a==b and a != 50) {
            counts[1]++;counts[2]++;counts[3]++;counts[4]++;
            b = player[x+counts[1]].FindFace();
            c = player[x+counts[2]].FindFace();
            d = player[x+counts[3]].FindFace();
            e = player[x+counts[4]].FindFace();
            if (a != b) {
                break;
            }
            
        }
        while (b == c and c != 50) {
            counts[1]++;counts[2]++;counts[3]++;
            c = player[x+counts[2]].FindFace();
            d = player[x+counts[3]].FindFace();
            e = player[x+counts[4]].FindFace();
            
        }
        while (c == d and d != 50) {
            counts[3]++;counts[4]++;
            d = player[x+counts[3]].FindFace();
            e = player[x+counts[4]].FindFace();
            
        }
        while ( d == e and e != 50) {
            counts[4]++;
            e = player[x+counts[4]].FindFace();
            
        }
        
        if (b-a == 1 and c-b == 1 and d-c == 1 and e-d == 1) {
            SortCardsSuit(player);
            int f = player[x].FindSuit();
            int g = player[x+counts[1]].FindSuit();
            int h = player[x+counts[2]].FindSuit();
            int i = player[x+counts[3]].FindSuit();
            int j = player[x+counts[4]].FindSuit();
            if (g-f == 0 and h-g == 0 and i-h == 0 and j-i == 0) {
                highest = e;
            }
            SortCards(player);
        }
    }
    return highest;
    
}

int Dealer::checkFourPair(Card player[]) {
    int highest = -1;
    for (int x = 0; x <= 10; x++) {
        int a = player[x].FindFace();
        int b = player[x+1].FindFace();
        int c = player[x+2].FindFace();
        int d = player[x+3].FindFace();
        if (a == b and b == c and c == d and a != 50) {
            highest = a;
        }
    }
    return highest;
}

int Dealer::checkThreePair(Card player[]) {
    int highest = -1;
    for (int x = 0; x <= 11; x++) {
        int a = player[x].FindFace();
        int b = player[x+1].FindFace();
        int c = player[x+2].FindFace();
        if (a == b and b == c and a != 50) {
            highest = a;
        }
    }
    return highest;
}

int Dealer::checkTwoPair(Card player[]) {
    int highest = -1;
    for (int x = 0; x <= 12; x++) {
        int a = player[x].FindFace();
        int b = player[x+1].FindFace();
        if (a == b and a != 50) {
            highest = a;
        }
    }
    return highest;
}

int Dealer::checkHighCard(Card player[]) {
    int highest = -1;
    for (int x = 0; x <= 11; x++) {
        int a = player[x].FindFace();
        if (a > highest and a != 50) {
            highest = a;
        }
    }
    return highest;
}

int Dealer::checkHouse(Card player[]){
    
    int highest = -1;
    for (int x = 0; x <= 11; x++) {
        int a = player[x].FindFace();
        int b = player[x+1].FindFace();
        int c = player[x+2].FindFace();
        if (a == b and b == c and a != 50) {
            for (int x = 0; x <= 12; x++) {
                int d = player[x].FindFace();
                int e = player[x+1].FindFace();
                if (d == e and d != a and d != 50) {
                    if ( a > highest) {
                        highest = a;
                    }
                    
                }
            }
        }
    }
    return highest;
    
}

int Dealer::checkPairs(Card player[]) {
    
    int highest = -1;
    for (int x = 0; x <= 12; x++) {
        int a = player[x].FindFace();
        int b = player[x+1].FindFace();
        
        if (a == b and a != 50) {
                for (int i = 0; i <= 12; i++) {
                int c = player[i].FindFace();
                int d = player[i+1].FindFace();
                    
                if (c == d and c != 50 and c != a) {
                    highest = a;
                }
            }
        }
    }
    return highest;
    
}

void Dealer::BetMoney() {
    FoldCards = false;
    cout << "Your money "<< money1 << endl;
    cout << "Dealer's money "<< money2 << endl;
    srand(static_cast<uint32_t>(time(0)));
    int playerbet = 0;
    int dealerbet = 0;

    if (money2 <= 200) {
        dealerbet = 200;
    } else if (checkHighCard(player2) > 12) {
        dealerbet = 450 + rand()%50;
    } else if (checkHighCard(player2) > 10) {
        dealerbet = 150 + rand()%50;
    } else {
        dealerbet = 25 + rand()%25;
    }
    
    cout << "Dealer: I have just bet " << dealerbet <<", what about you?" << endl;
    
    cout << "Please enter a bet between $0 and $" << money1 << endl;
    cin >> playerbet;
    
    if (playerbet > money1 or playerbet < 0) {
        ThisIsTheEnd();
    } else if (playerbet > dealerbet) {
        
        if (checkHighCard(player2) > 11) {
            //Fold = false;
            dealerbet = playerbet;
            money1 = money1 - playerbet;
            money2 = money2 - dealerbet;
            finalBet = playerbet;
        } else {
            FoldCards = true;
        }
        
    } else if (playerbet < dealerbet) {
        FoldCards = true;
    } else if (playerbet == dealerbet) {
        money1 = money1 - playerbet;
        money2 = money2 - dealerbet;
        finalBet = playerbet;
    }
}

void Dealer::Aftermath(){
    if (playerWinner == 1) {
        cout << "\nDealer: -_-"<< endl;
        money1 = money1 + 2*finalBet;
    } else if (playerWinner == 2) {
        cout << "\nDealer: Take your bank before I pay you out!\n"<< endl;
        money2 = money2 + 2*finalBet;
    } else {
        money1 = money1 + finalBet;
        money2 = money2 + finalBet;

    }
    finalBet = 0;
}

int Dealer::getMoney1() {
    
    return money1;
}
int Dealer::getMoney2() {
    
    return money2;
}
bool Dealer::getFold() {
    
    return FoldCards;
}

void Dealer::ThisIsTheEnd() {
    endTriggered = true;
   // cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nEVERYBODY" << endl;
    //cout << "JUST" << endl;
    //cout << "HAVE" << endl;
    //cout << "A" << endl;
    //cout << "GOOD" << endl;
    //cout << "TIME!!!!!!!!!!" << endl;





}

bool Dealer::getEndTriggered() {
    return endTriggered;
}
















