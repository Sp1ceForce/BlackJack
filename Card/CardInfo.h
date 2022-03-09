// Made by Sp1ceForce

#ifndef BLACKJACK_CARDINFO_H
#define BLACKJACK_CARDINFO_H
//Enum with card suits
enum CardSuit{
    CLUBS,
    DIAMONDS,
    HEARTS,
    SPADES,
};
//Enum with prices of cards
enum class Price{
    TWO=2,
    THREE=3,
    FOUR=4,
    FIVE=5,
    SIX=6,
    SEVEN=7,
    EIGHT=8,
    NINE=9,
    TEN=10,
    ACE=11,
    JACK=12,
    QUEEN=13,
    KING=14,
};
#include <string>
//Class that provides useful static methods for card enums
    class CardInfo{
    public:
        //Static method for converting suit enum to string
        static std::string SuitToString(CardSuit suit);

        //Static method for converting price enum to string
        static std::string PriceToString(Price price);
};
#endif //BLACKJACK_CARDINFO_H
