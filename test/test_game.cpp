#include <ctest.h>
#include <libmatches/game.h>

CTEST(MatchesGameSuite, MatchesCountInit) {
    MatchesGame game(20);
    ASSERT_EQUAL(20, game.matchesLeft);
}

CTEST(MatchesGameSuite, MatchesTake) {
    MatchesGame game(10);
    game.takeMatches(9);
    ASSERT_EQUAL(1, game.matchesLeft); 
}

CTEST(MatchesGameSuite, MatchesTakeMultiple) {
    MatchesGame game(20);
    game.takeMatches(9);
    ASSERT_EQUAL(11, game.matchesLeft); 
    game.takeMatches(5);
    ASSERT_EQUAL(6, game.matchesLeft); 
    game.takeMatches(6);
    ASSERT_EQUAL(0, game.matchesLeft); 
}


CTEST(MatchesGameSuite, SwitchPlayer) {
    MatchesGame game(20);
    ASSERT_EQUAL(true, game.player1Turn); 
    game.switchPlayer();
    ASSERT_EQUAL(false, game.player1Turn);
    game.switchPlayer();
    ASSERT_EQUAL(true, game.player1Turn);  
}