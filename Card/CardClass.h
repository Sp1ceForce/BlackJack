// Made by Sp1ceForce



//Class made for storing card data
#ifndef BLACKJACK_CARDCLASS_H
#define BLACKJACK_CARDCLASS_H
#include <string>
#include "CardInfo.h"

using namespace std;

class CardClass {

public:
    //Card's suit
    const CardSuit Suit;

    //Card's price
    const Price CardPrice;
private:


public:

    //Constructor for card, gets suit and price enum
    CardClass(CardSuit suit, Price price);

    //Method for getting card name
    string GetFullCardName();

    //Method for getting card price
    int GetPrice();
};


#endif //BLACKJACK_CARDCLASS_H
