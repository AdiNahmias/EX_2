#ifndef CARD_HPP
#define CARD_HPP
#include "iostream"
#include "stdio.h"
using namespace std;
namespace ariel{

};

class Card{

    private:
        int num;
        string shape;
        


    public:
        Card(){}
        Card(int num, string shape);
        string getshape();
        int getnum();
        
       
};







#endif
