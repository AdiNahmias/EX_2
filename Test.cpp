#include "doctest.h"
#include <stdexcept>
#include "iostream"
#include <stdio.h>
#include "player.hpp"
#include "game.hpp"
#include "card.hpp"
using namespace std;


TEST_CASE("Amount of cards per player at the start of the game"){
    Player p1("Alice");
    Player p2("Bob");
    //create new game
    Game game(p1, p2);
    CHECK(p1.stacksize() == 26);
    CHECK(p2.stacksize() == 26);
    CHECK(p1.cardesTaken() == 0);
    CHECK(p2.cardesTaken() == 0);
}

TEST_CASE("Checking if the 2 players are not the same player"){
    
}


TEST_CASE("Amount of cards per player after 5 turns"){
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
    CHECK(p1.stacksize() <= 21);
    CHECK(p2.stacksize() <= 21);
}

TEST_CASE("Amount of cards after one turn"){
    Player p1("Alice");
    Player p2("Bob");
    //create new game
    Game game(p1, p2);
    game.playTurn();
    bool cards;
    if((p1.cardesTaken() > p2.cardesTaken()) || (p1.cardesTaken() < p2.cardesTaken())){
        cards = true;
    }else{
        cards = false;
    }
    CHECK(cards);

}
TEST_CASE("Checking whether after a maximum of 26 turns the game is over"){
    Player p1("Alice");
    Player p2("Bob");
    //create new game
    Game game(p1, p2);
    int count = 0;
    while (p1.stacksize() > 0 && count <= 26){

        game.playTurn();
        count++;
    }
    CHECK(p1.stacksize() == 0);
    CHECK(p2.stacksize() == 0);
    CHECK(count <= 26);
}


TEST_CASE("Checks if someone won"){
    Player p1("Alice");
    Player p2("Bob");
    //create new game
    Game game(p1, p2);
    game.playAll();
    bool win;
    if(p1.stacksize() == 0 && p2.stacksize() == 0 && p1.cardesTaken() != p2.cardesTaken()) {
        win = true;
    }else{
        win = false;
    }
    CHECK(win);

}






