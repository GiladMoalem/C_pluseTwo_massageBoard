#include "Board.hpp"
#include <iostream>
#include <string>

namespace ariel{

    void Board::post(unsigned row, unsigned col, Direction direction, std::string str){
        std::cout << "POST" <<std::endl;
    }

    string Board::read(unsigned row, unsigned col, Direction direction, unsigned length){
        return "READ";
    }
    
    
    void Board::show(){
        std::cout << "SHOW" << std::endl;
    }
}