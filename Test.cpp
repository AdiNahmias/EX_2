#include "doctest.h"
#include <stdexcept>
#include "iostream"
#include <stdio.h>
#include "player.hpp"
#include "game.hpp"
#include "card.hpp"
using namespace std;


TEST_CASE("Checking the amount of cards for each player before creating a game"){
    Player p1("Alice");
    Player p2("Bob");
    CHECK(p1.stacksize() == 0);
    CHECK(p2.stacksize() == 0);
    CHECK(p1.cardesTaken() == 0);
    CHECK(p2.cardesTaken() == 0);
}

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

TEST_CASE("Check if the players got there names"){
    Player p1("Alice");
    Player p2("Bob");
    CHECK(p1.getname() == "Alice");
    CHECK(p2.getname() == "Bob");
    
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
    if(p1.cardesTaken() > 0){
        CHECK(p2.cardesTaken() == 0);
    }
    if(p2.cardesTaken() > 0){
        CHECK(p1.cardesTaken() == 0);
    }else{
        // No one has any cards in cardesTaken
        //cheking if we finish the game after one turn
        CHECK(((p1.stacksize() == 0) || (p2.stacksize() == 0)));
    } 

}


TEST_CASE("Checking whether after a maximum of 26 turns the game is over"){
    Player p1("Alice");
    Player p2("Bob");
    //create new game
    Game game(p1, p2);
    int turns = 0;
    while (p1.stacksize() > 0 && turns <= 26){

        game.playTurn();
        turns++;
    }
    CHECK(p1.stacksize() == 0);
    CHECK(p2.stacksize() == 0);
    CHECK(turns <= 26);
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
        //Throwing an error if the game is still in progress
        CHECK_THROWS(game.playTurn()); 
    }else{
        win = false;
        //If no one won the function that prints a winner will throw an error
        CHECK_THROWS(game.printWiner());
    }
    CHECK(win);

}

TEST_CASE("Checking if the game is over after playALL()"){
    Player p1("Alice");
    Player p2("Bob");
    //create new game
    Game game(p1, p2);
    game.playAll();
    CHECK(p1.stacksize() == 0);
    CHECK(p2.stacksize() == 0);

}







