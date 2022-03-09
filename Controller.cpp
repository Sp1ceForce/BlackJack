// Made by Sp1ceForce

#include "Controller.h"
#include <iostream>
#include "CardClass.h"
#include "ConsoleHelpers.h"

//Constructor that creates every card in the game
Controller::Controller() {
//For each card suit(Clubs,Diamonds,Hearts,Spades
    for(int i =0; i < 4; i++){
        CardSuit suit = static_cast<CardSuit>(i);
        //For each card price(From 2 to King/Ace)
        for(int j = static_cast<int>(Price::TWO); j <= static_cast<int>(Price::KING); j++){
            Price cardPrice = static_cast<Price>(j);
            AllCards.push_back(new CardClass(suit,cardPrice));
        }
    }
}
//Method that randomly generates deck
void Controller::GenerateDeck() {
    Deck = AllCards;
    random_device rd;
    auto rng = default_random_engine { rd()};
    shuffle(Deck.begin(), Deck.end(),rng);
}

/*
 * Game loop of the game
 * Order:
 * Before the game - start a new round
 * In the loop:
 * 1)Draw interface
 * 2)Get player input and call different methods depending on input
 * 3)
 */
void Controller::GameLoop() {
    StartARound();
    while(isPlaying){
        PrintInterface();
        GetInput();
        ProceedTurn();
    }
}

void Controller::GetInput() {
    string input;
getline(cin,input);
int command = atoi(input.c_str());
    switch (command) {
        case 1:
            Take();
            break;
        case 2:
            Pass();
            break;
        default:
            printf("WRONG COMMAND, TRY AGAIN \r\n");
            GetInput();
    }
}

void Controller::ProceedTurn() {
    isFirstPlayerTurn=!isFirstPlayerTurn;
    ConsoleHelpers::ClearConsole();
}

void Controller::PrintInterface() {
    string firstPlayerCardsStr="";
    string secondPlayerCardsStr="";
    string playerTurnStr = isFirstPlayerTurn ? "First" : "Second";

    for(auto c : FirstPlayerDeck){
        firstPlayerCardsStr+= c->GetFullCardName() + ", ";
    };
    for(auto c : SecondPlayerDeck){
        secondPlayerCardsStr+= c->GetFullCardName() + ", ";
    };
    printf("===============================\r\n");
    printf("1st Player's score: %i \r\n", FirstPlayerCount);
    printf("===============================\r\n");
    printf("1st Player's cards: %s \r\n", firstPlayerCardsStr.c_str());
    printf("===============================\r\n");

    printf("\r\n\r\n===============================\r\n");
    printf("2nd Player's score: %i \r\n", SecondPlayerCount);
    printf("===============================\r\n");
    printf("2st Player's cards: %s \r\n", secondPlayerCardsStr.c_str());
    printf("===============================\r\n");
    printf("This is %s player's turn \r\nCommands: \r\n1)Take new card \r\n2)Pass\r\n",playerTurnStr.c_str());
}

void Controller::Take() {
    auto newCard = Deck[Deck.size()-1];
    int price = newCard->GetPrice();
    Deck.pop_back();
    if(isFirstPlayerTurn){
        if(newCard->CardPrice== Price::ACE & FirstPlayerCount>=21) price = 1;
        FirstPlayerDeck.push_back(newCard);
        FirstPlayerCount+= price;
    }
    else{
        if(newCard->CardPrice== Price::ACE & SecondPlayerCount>=21) price = 1;
        SecondPlayerDeck.push_back(newCard);
        SecondPlayerCount+= newCard->GetPrice();
    }
}

void Controller::Pass() {
    //If 2 consecutive turns was passed, then check for win
    if(isLastTurnPass){
        CheckForWin();
    }
    //If this was the first passed turn, then set "isLasTurnPass" bool to true
    else{
        isLastTurnPass= true;
    }

}
//Method that decides which player won, I don't know how to make it without if statements
void Controller::CheckForWin() {
    //Type of the end screen, DRAW by default in case of errors
    GameEndType endType = GameEndType::DRAW;
    if(FirstPlayerCount == 21 && SecondPlayerCount == 21) endType = GameEndType::DRAW;
    else if(FirstPlayerCount > 21 && SecondPlayerCount > 21) endType = GameEndType::DRAW;
    else if(FirstPlayerCount==21) endType = GameEndType::FIRST_PLAYER_WIN;
    else if(FirstPlayerCount > 21) endType = GameEndType::SECOND_PLAYER_WIN;
    else if(SecondPlayerCount == 21) endType = GameEndType::SECOND_PLAYER_WIN;
    else if(SecondPlayerCount>21) endType = GameEndType::FIRST_PLAYER_WIN;
    else if((SecondPlayerCount < 21 && FirstPlayerCount < 21) && ((21-SecondPlayerCount) < (21 - FirstPlayerCount))) endType = GameEndType::SECOND_PLAYER_WIN;
    else if((SecondPlayerCount < 21 && FirstPlayerCount < 21) && ((21-SecondPlayerCount) > (21 - FirstPlayerCount))) endType = GameEndType::FIRST_PLAYER_WIN;
    else if((SecondPlayerCount < 21 && FirstPlayerCount < 21) && ((21-SecondPlayerCount) == (21 - FirstPlayerCount))) endType = GameEndType::DRAW;
    EndScreen(endType);
}

void Controller::EndScreen(GameEndType endType) {
    string result;
    ConsoleHelpers::ClearConsole();
    switch (endType){
        case GameEndType::FIRST_PLAYER_WIN:
            result = "First player won";
            break;
        case GameEndType::SECOND_PLAYER_WIN:
            result = "Second player won";
            break;
        case GameEndType::DRAW:
            result = "Draw";
            break;
        default:
            result = "ERROR";
            break;
    }
    printf("===============================\r\n");
    printf("Result of the game is: %s\r\n",result.c_str());
    printf("Available commands: \r\n1)Start new game\r\n2)Quit the game\r\n");
    string input;
    getline(cin,input);
    int command = atoi(input.c_str());
    switch (command) {
        case 1:
            StartARound();
            break;
        case 2:
            isPlaying=false;
            break;
        default:
            printf("WRONG COMMAND");
    }
}
//Method that starts new round
//It will:
//Generate new deck(shuffle all cards in "Deck" vector)
//Set player's values to default's(clear their hand vectors, reset total card price)
//Give 2 cards for each player
void Controller::StartARound() {
    GenerateDeck();
    RestoreDefaultValues();
    for (int i = 0; i < 2; ++i) {
        auto newPlayerCard =Deck[Deck.size()-1];
        FirstPlayerDeck.push_back(newPlayerCard);
        FirstPlayerCount+=newPlayerCard->GetPrice();
        Deck.pop_back();
        auto newEnemyCard = Deck[Deck.size()-1];
        SecondPlayerDeck.push_back(newEnemyCard);
        SecondPlayerCount+=newEnemyCard->GetPrice();
        Deck.pop_back();
    }

}
//Method that resets player's values to
void Controller::RestoreDefaultValues() {
    FirstPlayerDeck.clear();
    SecondPlayerDeck.clear();
    isLastTurnPass = false;
    FirstPlayerCount =0;
    SecondPlayerCount =0;
}



