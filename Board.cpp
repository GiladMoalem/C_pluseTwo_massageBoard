#include "Board.hpp"
#include <iostream>
#include <string>

namespace ariel{

    void Board::post(unsigned int row, unsigned int col, Direction direction, std::string str){
        this->min_col = min(this->min_col,col);
        this->min_row = min(this->min_row,row);
        if(direction== Direction::Horizontal){
            for(char c:str){
                this->B[row][col++] = c;
            }
        }else{
            for(char c:str){
                this->B[row++][col] = c;
            }
        }
        this->max_row = max(this->max_row,row);
        this->max_col = max(this->max_col,col);
        
        std::cout << "POST" <<std::endl;
    }

    string Board::read(unsigned int row, unsigned int col, Direction direction, unsigned int length){
        string result="";
        char c=0;
        for(unsigned int i =0; i<length;i++){
            if( (this->B.find(row) != this->B.end())&& (this->B[row].find(col) != this->B[row].end()) ){
                c=this->B[row][col];
            }else {
                c='_';
            }
            result += c;
            direction == Direction::Horizontal ? col++ : row++;
        }
        return result;
    }
    
    
    void Board::show(){
        std::cout << "SHOW:" << std::endl;
        for(unsigned int i=this->min_row; i<this->max_row; i++){
            for (unsigned int j = this->min_col; j < this->max_col; j++)
            {
                if(this->B.find(i)!=this->B.end() && this->B[i].find(j)!=this->B[i].end()){
                    cout << this->B[i][j];
                }else{
                    cout << "_";
                }
            }
            cout << endl;
            
        }
    }
}