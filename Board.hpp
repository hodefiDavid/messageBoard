//
// Created by david on 3/23/21.
//

#pragma once

#include <string>
#include<map>
#include "Direction.hpp"
unsigned int const MAXUSINT = 4294967295;
namespace ariel {
/**
 * this class manage a bulletin board.
 * in this bulletin board message can be writing over each other.
 * The department support the following functions:
 * post, read and show - you can read more about them in their description
 */
    class Board {
    public:
        Board();
        //Variables that hold the current minimum and maximum row and column, in order to print
        //only the places that has been used
        unsigned int minRow;
        unsigned int maxRow;
        unsigned int minCol;
        unsigned int maxCol;

        std::map<std::string,char> mapBoard;
        /**
         * post - receives a position (line and column), direction (horizontal or vertical),
         * and a string representing an ad, And post the string on the board in the appropriate place.
         * @param row - unsigned int that represent the starting row number
         * @param col - unsigned int that represent the starting column number
         * @param direction - ariel::Direction thet represent direction Horizontal or Vertical
         * @param st - const std::string that represent the message that the user want to post
         */
        void post(unsigned int row, unsigned int col, ariel::Direction direction, const std::string &st);

        /**
         * read - receives a position (line and column), direction (horizontal or vertical),
         * and a number of characters, reads what is written on the board in the nanton position
         * and the length, and returns a string. The letter in each slot on the board is the last
         * letter pasted there.
         * @param row - unsigned int that represent the starting row number
         * @param col - unsigned int that represent the starting column number
         * @param direction - ariel::Direction thet represent direction Horizontal or Vertical
         * @param length - length of chars you want to read (limited to the size of unsigned int)
         * @return
         */
        std::string read(unsigned row, unsigned col, ariel::Direction direction, unsigned length);
        /**
         * Displays the current bulletin board in a convenient way to read.
         * The function add underline (_) where the bulletin board empty.
         * Displays only rows with messege inside them (not including the frame)
         */
        void show();
        /**
         * The function maxMinRowCol mange the minimum and maximum row and column.
         * the function update the value of the variables according each post
         *
         * @param row - unsigned int that represent the row number
         * @param col - unsigned int that represent the column number
         * @param direction - ariel::Direction thet represent direction Horizontal or Vertical
         * @param length - the length of chars the user posted
         */
        void maxMinRowCol(unsigned int row, unsigned int col, Direction direction, unsigned long length);
    };
}


