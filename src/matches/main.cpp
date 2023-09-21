#include <iostream>
#include <libmatches/game.h>

int main(void)
{
    MatchesGame game = MatchesGame(100);
    game.play();
    return 0;
}