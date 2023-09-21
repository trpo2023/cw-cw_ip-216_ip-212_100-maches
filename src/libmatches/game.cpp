#include "game.h"

MatchesGame::MatchesGame(int totalMatches)
    : matchesLeft(totalMatches), player1Turn(true), turnNumber(0)
{
    std::srand(std::time(0));
}

void MatchesGame::play()
{
    std::cout << "Welcome to the game of 100 Matches!" << std::endl;
    while (matchesLeft > 0) {
        turnNumber++;
        displayMatches();

        int move;
        if (player1Turn) {
            move = getPlayerMove();
        } else {
            move = getComputerMove();
            std::cout << "Turn #" << turnNumber << ": Player 2 (Computer) took "
                      << move << " matches." << std::endl;
        }

        if (move == 0) {
            std::cout << "Player 1 quits. Player 2 (Computer) wins!"
                      << std::endl;
            return;
        }

        if (move < 1 || move > 10 || move > matchesLeft) {
            std::cout
                    << "Invalid move. You must remove between 1 and 10 matches."
                    << std::endl;
        } else {
            takeMatches(20);
            switchPlayer();
        }
    }

    displayMatches();

    if (!player1Turn) {
        std::cout << "Player 1 wins!" << std::endl;
    } else {
        std::cout << "Player 2 (Computer) wins!" << std::endl;
    }
}

void MatchesGame::takeMatches(int count) {
    matchesLeft -= count;
}

void MatchesGame::displayMatches()
{
    std::cout << "Matches left: " << matchesLeft << ": ";
    for (int i = 0; i < matchesLeft; ++i) {
        std::cout << "| ";
    }
    std::cout << std::endl;
}

int MatchesGame::getPlayerMove()
{
    int move;
    std::cout << "Turn #" << turnNumber
              << ": Player 1, enter how many matches to remove (1-10), or "
                 "enter 0 to quit: ";
    std::cin >> move;
    return move;
}

int MatchesGame::getComputerMove()
{
    int maxMove = std::min(10, matchesLeft);
    return (rand() % maxMove) + 1;
}

void MatchesGame::switchPlayer()
{
    player1Turn = !player1Turn;
}
