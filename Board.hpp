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
        unsigned int minRow=MAXUSINT;
        unsigned int maxRow=0;
        unsigned int minCol=MAXUSINT;
        unsigned int maxCol=0;

        std::map<std::string,char> mapBoard;

        void post(unsigned int i,unsigned int i1, ariel::Direction direction, std::string st);

        std::string read(unsigned i, unsigned i1, Direction direction, unsigned i2);

        void show();


        void maxMinRowCol(unsigned int row, unsigned int col, Direction direction, unsigned long length);
    };
}


