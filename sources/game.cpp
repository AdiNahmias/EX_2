#include "game.hpp"
#include "player.hpp"
#include "iostream"
#include "stdio.h"

//constructor
Game::Game(Player p1, Player p2){
    this->p1 = p1;
    this->p2 = p2;

 }


// print the last turn stats
void Game::printLastTurn() {

 }

//playes the game untill the end
void Game::playAll(){

}
// prints the name of the winning player
void Game::printWiner(){

}

// // prints all the turns played one line per turn (same format as game.printLastTurn())
void Game::printLog(){

}
//for each player prints basic statistics: win rate, cards won, <other stats you want to print>. Also print the draw rate and amount of draws that happand. (draw within a draw counts as 2 draws. )
void Game::printStats(){

}
void Game::playTurn(){

}