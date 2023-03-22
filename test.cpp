#include "doctest.h"
#include <stdexept>
#include "iostream"
#include "stdio.h"
#include "player.hpp"
#include "game.hpp"
#include "card.hpp"
using namespace std;


TEST_CASE("when we start the game"){
    Player p1("Alice");
    Player p2("Bob");
    //create new game
    Game game(p1, p2);
    bool division;
    if(p1.stacksize == 26 && p2.stacksize == 26){
        division = true;
    }else{
        division = false;
    }
    CHECK(division);
}

TEST_CASE("when we finish the game"){
    Player p1("Alice");
    Player p2("Bob");
    //create new game
    Game game(p1, p2);
    bool division;
    if((p1.stacksize == 52 && p2.stacksize == 0) || (p2.stacksize == 52 && p1.stacksize == 0)){
        division = true;
    }else{
        division = false;
    }
    CHECK(division);



}