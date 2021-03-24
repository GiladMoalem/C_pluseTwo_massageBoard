#include "doctest.h"
#include "Board.hpp"
#include <string>

// #include <iostream>
using namespace std;


ariel::Board board;

TEST_CASE ("new board - filled by: _    "){   
    
    ariel::Board board1;
    
    CHECK( board1.read(0,0,ariel::Direction::Horizontal,1)=="_");
    CHECK( board1.read(100,0,ariel::Direction::Horizontal,1)=="_");
    CHECK( board1.read(0,100,ariel::Direction::Horizontal,1)=="_");
    CHECK( board1.read(8,34,ariel::Direction::Horizontal,1)=="_");
    CHECK( board1.read(35,3,ariel::Direction::Horizontal,1)=="_");
    CHECK( board1.read(90,87,ariel::Direction::Horizontal,1)=="_");
    CHECK( board1.read(234,2348,ariel::Direction::Horizontal,1)=="_");
}

TEST_CASE ("exceptions and errors"){
    /*
    CHECK_THROWS( board.read(-1,0,ariel::Direction::Horizontal,1) );
    CHECK_THROWS( board.read(0,-1,ariel::Direction::Horizontal,1) );
    CHECK_THROWS( board.read(0,0,ariel::Direction::Horizontal,-2) );

    CHECK_THROWS( board.read(0,0,ariel::Direction::Horizontal,-231) );
    CHECK_THROWS( board.read(-13,-1280,ariel::Direction::Horizontal,23) );
    */
    CHECK_NOTHROW( board.read(0,0,ariel::Direction::Horizontal,2973) );//long massage
    CHECK_NOTHROW( board.read(0,0,ariel::Direction::Horizontal,244593) );
    CHECK_NOTHROW( board.read(238992,0,ariel::Direction::Horizontal,23) );//big cordinat
    CHECK_NOTHROW( board.read(0,2897435,ariel::Direction::Horizontal,28974353) );
    CHECK_NOTHROW( board.read(29769879,238648340,ariel::Direction::Horizontal,23) );
    CHECK_NOTHROW( board.read(29769879,238648340,ariel::Direction::Vertical,23) );//same with vertical
    
    CHECK_NOTHROW( board.read(0,0,ariel::Direction::Horizontal,0) );//reads empty word
    CHECK_NOTHROW( board.read(453,32,ariel::Direction::Vertical,0) );//reads empty word
}
TEST_CASE("bild and read new board"){

    ariel::Board board2;
    CHECK_NOTHROW( board2.post(0,0,ariel::Direction::Vertical,"gilad") );
    CHECK( board2.read(0,0,ariel::Direction::Vertical,5) == "gilad" );
   
    CHECK_NOTHROW( board2.post(0,0,ariel::Direction::Horizontal,"ABCDEFGHIGKLMNOPQRSTVUWXYZ1234567890") );
    CHECK( board2.read(0,0,ariel::Direction::Vertical,2) == "Ai" );

    CHECK_NOTHROW( board2.post(100,200,ariel::Direction::Horizontal,"abcd" )   );
    CHECK( board2.read(99,201,ariel::Direction::Vertical,3 )== "_b_" );

    board2.post(99, 202, ariel::Direction::Vertical, "xyz");
    CHECK( board2.read(100,200, ariel::Direction::Horizontal, 6) == "abyd__" );
    
}


/*
TEST_CASE("minuse"){
    CHECK_THROWS(factorial(-1));
}

TEST_CASE("big number"){
    CHECK(factorial(10)== (2*3*4*5*6*7*8*9*10) );
}
*/