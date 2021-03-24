//
// Created by david on 3/23/21.
//

#pragma once

#include <string>
#include "Direction.hpp"
namespace ariel {

    class Board {

    public:
        void post(unsigned int i,unsigned int i1, ariel::Direction direction, std::string st);

        std::string read(unsigned i, unsigned i1, Direction direction, unsigned i2);

        void show();

    };
}


