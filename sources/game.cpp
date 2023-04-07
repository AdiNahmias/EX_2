#include "game.hpp"
#include "player.hpp"
#include "iostream"
#include "stdio.h"
#include <vector>
#include <algorithm>
#include <random>



void Game::print_card_stack(vector <Card> &vec) {
    for (size_t i = 0; i < vec.size(); i++) {
        std::cout << vec.at(i).getnum_string()<< " of " << vec.at(i).getshape() << std::endl;
    }
}

void Game::reset_num_cards(){
    this->num_cards[0] = "Ace";
    this->num_cards[1] = "2";
    this->num_cards[2] = "3";
    this->num_cards[3] = "4";
    this->num_cards[4] = "5";
    this->num_cards[5] = "6";
    this->num_cards[6] = "7";
    this->num_cards[7] = "8";
    this->num_cards[8] = "9";
    this->num_cards[9] = "10";
    this->num_cards[10] = "Jack";
    this->num_cards[11] = "Queen";
    this->num_cards[12] = "King";
}

void Game::reset_card_stack(vector <Card> &vec){
    for(size_t i=1; i<=13; i++){
        vec.push_back(Card(i,this->num_cards[i-1],"Heart"));  
    }
    for(size_t i = 1; i<=13; i++){
        vec.push_back(Card(i,this->num_cards[i-1],"Diamond"));   
    }
    for(size_t i = 1; i<=13; i++){
        vec.push_back(Card(i,this->num_cards[i-1],"Spades"));
    }
    for(size_t i = 1; i<=13; i++){
        vec.push_back(Card(i,this->num_cards[i-1],"Clubs"));
    }

 }


void Game::shuffleCardStack(vector<Card>& vec) {
    // Create a random number generator
    random_device rd;
    mt19937 g(rd());

    // Shuffle the vector using the random number generator
    shuffle(vec.begin(), vec.end(), g);
}

void Game::division_card(){
    for(size_t i= 0; i < vec.size(); i++){
        if(i % 2 == 0){
            this->p1->set_card_to_stack(vec[i]);
        }else{
            this->p2->set_card_to_stack(vec[i]);
        }
    }
}

//constructor
Game::Game(Player &player_1, Player &player_2){
    this->p1 = &player_1;
    this->p2 = &player_2;

    // if(this->p1->getname() == this->p2->getname()){
    //     throw std::runtime_error("ERROR: THERE IS ONE PLAYER");
    // }
    reset_num_cards();
    //reset the stack card
    reset_card_stack(this->vec);
    //std::cout << "--------before shuffle---------" << std::endl;
    //print_card_stack(this->vec);
    //shuffle cards in the Stack
    shuffleCardStack(this->vec);
    //std::cout << "--------after shuffle---------" << std::endl;
    //print_card_stack(this->vec);

    if (vec.size() < 52) {
    std::cout << "Error: Not enough cards in the deck\n";
    return;
    }
    //division cards
    division_card();
    std::cout << "--------player 1 stack---------" << std::endl;
    this->p1->print_card_stack_player();
    std::cout << "--------player 2 stack---------" << std::endl;
    this->p2->print_card_stack_player();

 }


//print the last turn stats
void Game::printLastTurn() {
    string str = "";
    str = this->turns.back();
    std::cout <<"LAST TURN : " << str << std::endl;
}

//playes the game untill the end
void Game::playAll(){
    while((this->p1->stacksize() != 0) && (this->p2->stacksize() != 0)){
        playTurn();
    }
}

// prints the name of the winning player
void Game::printWiner(){

    if(this->p1->stacksize() == 0 && this->p2->stacksize() == 0){

        if(this->p1->cardesTaken() > this->p2->cardesTaken()){
            std::cout << this->p1->getname()<< " is the WINNER of the game!! " << std::endl; 
            return;

        }if(this->p1->cardesTaken() < this->p2->cardesTaken()){
            std::cout << this->p2->getname()<< " is the WINNER of the game!! "  << std::endl; 
            return;

        }else{
            throw std::runtime_error("ERROR: THERE IS NO WINNER - DRAW!");
        }
    }else{

        std::cout << "--------THE GAME IS NOT OVER---------" << std::endl;
    }
}


//prints all the turns played one line per turn (same format as game.printLastTurn())
void Game::printLog(){
    string str = "";
    for(size_t i = 0; i < this->turns.size(); i++){
        str = turns[i];
        std::cout << "TURN " << i+1 << " : " << str << std::endl;
    }

}


//for each player prints basic statistics: 
// win rate, cards won, <other stats you want to print>
// Also print the draw rate and amount of draws that happand.
void Game::printStats(){
    //How many cards each player wins
    std::cout << this->p1->getname()<< " has won " << this->p1->cardesTaken() << " cards" << std::endl;
    std::cout << this->p2->getname()<< " has won " << this->p2->cardesTaken() << " cards" << std::endl;
    //win rate
    std::cout << this->p1->getname()<< " won in " << this->player_1_win << " turns out of " << 
    (this->player_1_win + this->player_2_win) << " turns" <<std::endl;

    std::cout << this->p2->getname()<< " won in " << this->player_2_win << " turns out of " << 
    (this->player_1_win + this->player_2_win) << " turns" <<std::endl;
    //draw
    std::cout << "During these " << ((this->player_1_win + this->player_2_win)) << " turns we got draw " 
    << this->draw << " times"<<std::endl;
    //how many cards each player have
    std::cout <<"Each player has " << this->p1->stacksize() << " cards left" << std::endl;
}

//play one turn
void Game::playTurn(){

if(this->p1->getname() == this->p2->getname()){
        throw std::runtime_error("ERROR: THERE IS ONE PLAYER");
}

//check if the players have cards in his stack
if((this->p1->stacksize() > 0) && (this->p2->stacksize() >0) ){

    Card arr1[26];
    Card arr2[26];
    int i = 0;

    Card card1 = this->p1->get_card_from_stack();
    Card card2 = this->p2->get_card_from_stack();

    string c1 = this->p1->getname()+" : "+card1.getnum_string()+" of "+card1.getshape();
    string c2 = this->p2->getname()+" : "+card2.getnum_string()+" of "+card2.getshape();
    
//--------------------------------------------------------------------------
    if(card1.getnum() > card2.getnum()){
        this->p1->set_card_to_cardesTaken(card1);
        this->p1->set_card_to_cardesTaken(card2);

        //std::cout << "--------p1 won in this turn---------" << std::endl;
        //std::cout << "--------p1 cards Taken---------" << std::endl;
        //this->p1->print_cardesTaken();

        string c3 = this->p1->getname()+" took the cards in this turn";
        string turn = c1 + " , "+ c2 + " - " + c3;
        std::cout <<turn<< std::endl;
        this->turns.push_back(turn);
        this->player_1_win++;
        return;
    }

//--------------------------------------------------------------------------

    if(card1.getnum() < card2.getnum()){
        this->p2->set_card_to_cardesTaken(card1);
        this->p2->set_card_to_cardesTaken(card2);

        //std::cout << "--------p2 won in this turn---------" << std::endl;
        //std::cout << "--------p2 cards Taken---------" << std::endl;
        //this->p2->print_cardesTaken();

        string c3 = this->p2->getname()+" took the cards in this turn";
        string turn = c1 + " , "+ c2 + " - " + c3;
        std::cout <<turn<< std::endl;
        this->turns.push_back(turn);
        this->player_2_win++;
        return;
    }

//--------------------------------------------------------------------------
    
    //if the players put the same number card
    else{
        vector<string> draw_turn;
        while((card1.getnum() == card2.getnum()) && (this->p1->stacksize()> 0)){
        //std::cout << "--------p1 and p2 have the same card---------" << std::endl;
        this->draw++;
        string c3 = "| DRAW! | - The players put a card face down and then - ";
        string turn = c1 + " , "+ c2 + " - " + c3;
        //std::cout <<turn<< std::endl;
        draw_turn.push_back(turn);
        
        //put the same card in the arr----------------
        arr1[i] = card1;
        arr2[i] = card2;
        i++;


        //put the close cards in the arr---------------
        //std::cout << "--------p1 and p2 put 2 close cards---------" << std::endl;
        arr1[i] = this->p1->get_card_from_stack();
        arr2[i] = this->p2->get_card_from_stack();
        
        if((this->p1->stacksize() == 0) && (this->p2->stacksize()==0) ){
            break;
        }

        //again open cards----------------------------
        //if the 2 cards is the same we going back to the beginning of while
        //std::cout << "--------p1 and p2 put 2 open cards---------" << std::endl;

        card1 = this->p1->get_card_from_stack();
        card2 = this->p2->get_card_from_stack();
        string c1 = this->p1->getname()+" : "+card1.getnum_string()+" of "+card1.getshape();
        string c2 = this->p2->getname()+" : "+card2.getnum_string()+" of "+card2.getshape();
        i++;
        }//end while

//--------------------------------------------------------------------------
        //the 2 cards are not the same
        arr1[i] = card1;
        arr2[i] = card2;
        
        if((this->p1->stacksize()== 0) && (card1.getnum() == card2.getnum())){
            std::cout << "--------GAME OVER WITH DRAW---------" << std::endl;

            //Each player takes the cards he played with in the last turn

            for(size_t k = 0; k <= i; k++){
                this->p1->set_card_to_cardesTaken(arr1[k]);
            }
            for(size_t k = 0; k <= i; k++){
                this->p2->set_card_to_cardesTaken(arr2[k]);
            }
            //put in temp the last turn if it is draw
            string temp = "";
            for(size_t i = 0; i < draw_turn.size(); i++){
                temp = temp + draw_turn[i];
            }
            this->turns.push_back(temp);


            return;
        }
//--------------------------------------------------------------------------
        if(card1.getnum() > card2.getnum()){

            //player1 takes all the cards in the 2 arr
            //std::cout << "--------p1 won in this turn---------" << std::endl;
            for(size_t k = 0; k <= i; k++){
                this->p1->set_card_to_cardesTaken(arr1[k]);
            }
            for(size_t k = 0; k <= i; k++){
                this->p1->set_card_to_cardesTaken(arr2[k]);
            }

            string c1 = this->p1->getname()+" : "+card1.getnum_string()+" of "+card1.getshape();
            string c2 = this->p2->getname()+" : "+card2.getnum_string()+" of "+card2.getshape();
            string c3 = this->p1->getname()+" took the cards in this turn";
            string turn = c1 + " , "+ c2 + " - " + c3;
            //std::cout <<turn<< std::endl;
            draw_turn.push_back(turn);
            string temp = "";
            for(size_t i = 0; i<draw_turn.size(); i++){
                temp = temp + draw_turn[i];
            }

            this->turns.push_back(temp);
            this->player_1_win++;
            //std::cout << "--------p1 cards Taken---------" << std::endl;
            //this->p1->print_cardesTaken();
            return;
//--------------------------------------------------------------------------
        }if(card1.getnum() < card2.getnum()){

            //player2 takes all the cards in the 2 arr
            //std::cout << "--------p2 won in this turn---------" << std::endl;
            for(size_t k = 0; k <= i; k++){
                this->p2->set_card_to_cardesTaken(arr1[k]);
            }
            for(size_t k = 0; k <= i; k++){
                this->p2->set_card_to_cardesTaken(arr2[k]);
            }

            string c1 = this->p1->getname()+" : "+card1.getnum_string()+" of "+card1.getshape();
            string c2 = this->p2->getname()+" : "+card2.getnum_string()+" of "+card2.getshape();
            string c3 = this->p2->getname()+" took the cards in this turn";
            string turn = c1 + " , "+ c2 + " - " + c3;
            //std::cout <<turn<< std::endl;
            draw_turn.push_back(turn);
            string temp = "";
            for(size_t i = 0; i < draw_turn.size(); i++){
                temp = temp + draw_turn[i];
            }
            this->turns.push_back(temp);
            this->player_2_win++;
            //std::cout << "--------p2 cards Taken---------" << std::endl;
            //this->p2->print_cardesTaken();
            return;
    
        }
//--------------------------------------------------------------------------
    }//end else if we have the same cars
}else{

    throw std::runtime_error("ERROR: There is no cards in players stack");
    
    }

}
   

