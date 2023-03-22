#include "doctest.h"
#include <stdexept>
#include "iostream"
#include "stdio.h"
#include "player.hpp"
#include "game.hpp"
#include "card.hpp"
using namespace std;


TEST_CASE("Amount of cards per player at the start of the game"){
    Player p1("Alice");
    Player p2("Bob");
    //create new game
    Game game(p1, p2);
    bool division;
    if(p1.stacksize() == 26 && p2.stacksize() == 26){
        division = true;
    }else{
        division = false;
    }
    CHECK(division);
}

TEST_CASE("Amount of cards per player at the end of the game"){
    Player p1("Alice");
    Player p2("Bob");
    //create new game
    Game game(p1, p2);
    game.playAll();
    bool win;
    if(p1.stacksize() == 0 && p2.stacksize() == 0) {
        win = true;
    }else{
        win = false;
    }
    CHECK(win);

}

TEST_CASE("Amount of cards per player in the middle of the game"){
    Player p1("Alice");
    Player p2("Bob");
    //create new game
    Game game(p1, p2);
    // After 5 game turns
    for (int i=0; i<5; i++) {
    game.playTurn();
    }
    bool sum;
    if(p1.stacksize() + p1.cardesTaken() + p2.stacksize() + p2.cardesTaken() == 52){
        sum = true;
    }else{
        sum = false;
    }
    CHECK(sum);
}

TEST_CASE("Amount of cards after one turn"){
    Player p1("Alice");
    Player p2("Bob");
    //create new game
    Game game(p1, p2);
    game.playTurn();
    bool division;
    if((p1.cardesTaken() > p2.cardesTaken()) || (p1.cardesTaken() < p2.cardesTaken())){
        division = true;
    }else{
        division = false;
    }
    CHECK(division);

}

TEST_CASE("5"){
    Player p1("Alice");
    Player p2("Bob");
    //create new game
    Game game(p1, p2);
    

}

