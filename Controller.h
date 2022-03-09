//
// Made by Sp1ceForce
//

#ifndef BLACKJACK_CONTROLLER_H
#define BLACKJACK_CONTROLLER_H
#include <vector>
#include <string>
#include <random>
#include <algorithm>
class CardClass;
using namespace std;
enum class GameEndType{
    FIRST_PLAYER_WIN,
    SECOND_PLAYER_WIN,
    DRAW
};
class Controller {
private:
    //Bool that is responsible for game loop
    bool isPlaying = true;

    //Vector with all cards in the game
    vector<CardClass*> AllCards;

    //Vector with deck of cards, gets shuffled
    vector<CardClass*> Deck;

    //Vector with first player's hand
    vector<CardClass*> FirstPlayerDeck;
    //Total card score of first player
    int FirstPlayerCount=0;

    //Vector with second player's hand
    vector<CardClass*> SecondPlayerDeck;
    //Total card score of second player
    int SecondPlayerCount=0;

public:
    Controller();
    void GameLoop();

private:
    bool isLastTurnPass = false;
    bool isFirstPlayerTurn = true;
    void StartARound();
    void Take();
    void Pass();
    void PrintInterface();
    void GetInput();
    void CheckForWin();
    void ProceedTurn();
    void EndScreen(GameEndType endType);
    void GenerateDeck();

    void RestoreDefaultValues();
};


#endif //BLACKJACK_CONTROLLER_H
