#include "Direction.hpp"
#include <string>
using namespace std;

namespace ariel{
    class Board{

        //properties
        
        public:
            void post(unsigned row, unsigned col, Direction direction, string str);
            string read(unsigned row, unsigned col, Direction direction, unsigned length);
            void show();
    };
}