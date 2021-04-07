#include "Direction.hpp"
#include <string>
#include <map>
using namespace std;


namespace ariel{
    class Board{
        unsigned int max_row;
        unsigned int min_row;
        unsigned int max_col;
        unsigned int min_col;
        map<uint, map<uint,char>> B;
        
        public:
            Board(){
                max_row=0;
                max_col=0;
                min_row=UINT16_MAX;
                min_col=UINT16_MAX;
            }
            ~Board(){}
            void post(unsigned int row, unsigned int col, Direction direction, string str);
            string read(unsigned int row, unsigned int col, Direction direction, unsigned int length);
            void show();
    };
}