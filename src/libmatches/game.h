#pragma once
#include <iostream>

#include <cstdlib>
#include <ctime>
#include <iostream>

class MatchesGame {
public:
    int matchesLeft;
    bool player1Turn;
    int turnNumber;

    MatchesGame(int totalMatches);
    void play();
    void displayMatches();
    int getPlayerMove();
    int getComputerMove();
    void switchPlayer();
};