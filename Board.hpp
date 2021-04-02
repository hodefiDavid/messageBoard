//
// Created by david on 3/23/21.
//

#pragma once

#include <string>
#include<map>
#include "Direction.hpp"
unsigned int const MAXUSINT = 4294967295;
namespace ariel {

    class Board {
    public:
//        Board()= default;
        unsigned int minRow=MAXUSINT;
        unsigned int maxRow=0;
        unsigned int minCol=MAXUSINT;
        unsigned int maxCol=0;

        std::map<std::string,char> mapBoard;

        void post(unsigned int row,unsigned int col, ariel::Direction direction, std::string st);

        std::string read(unsigned row, unsigned col, ariel::Direction direction, unsigned length);

        void show();

        void maxMinRowCol(unsigned int row, unsigned int col, Direction direction, unsigned long length);
    };
}


