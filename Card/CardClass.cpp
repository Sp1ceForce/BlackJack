//
// Made by Sp1ceForce
//

#include "CardClass.h"


string CardClass::GetFullCardName() {
    string result =CardInfo::PriceToString(CardPrice) + " of " + CardInfo::SuitToString(Suit);
    return result;
}

int CardClass::GetPrice() {
    if(static_cast<int>(CardPrice) > 11){
        return 10;
    }
    return static_cast<int>(CardPrice);
}

CardClass::CardClass(CardSuit suit, Price price) : Suit(suit), CardPrice(price)
{}
