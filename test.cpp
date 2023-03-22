#include "doctest.h"
#include <stdexept>
#include "iostream"
#include "stdio.h"
#include "player.hpp"
#include "game.hpp"
#include "card.hpp"
using namespace std;


TEST_CASE("when we start the game"){
    Player p1;
    Player p2;
    //create new game
    Game game(p1, p2);
    bool division;
    if(p1.stacksize == 26 && p2.stacksize == 26){
        division = true;
    }
    CHECK(division);
}