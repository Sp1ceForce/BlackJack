// Made by Sp1ceForce

#include "CardInfo.h"

std::string CardInfo::SuitToString(CardSuit suit) {
    //Would really like to create better implementation but don't know how

    switch (suit) {
        case CardSuit::CLUBS:
            return "Clubs";
        case CardSuit::DIAMONDS:
            return "Diamonds";
        case CardSuit::HEARTS:
            return "Hearts";
        case CardSuit::SPADES:
            return "Spades";
    }
}
//Method that converts Price enum to string
std::string CardInfo::PriceToString(Price price) {
    //Same thing as SuitToStringMethod, maybe I will create better version someday
    switch (price) {
        case Price::TWO: return "Two";
        case Price::THREE: return "Three";
        case Price::FOUR: return "Four";
        case Price::FIVE: return "Five";
        case Price::SIX: return "Six";
        case Price::SEVEN: return "Seven";
        case Price::EIGHT: return "Eight";
        case Price::NINE: return "Nine";
        case Price::TEN: return "Ten";
        case Price::JACK: return "Jack";
        case Price::ACE: return "Ace";
        case Price::QUEEN: return "Queen";
        case Price::KING: return "King";
    }
}
