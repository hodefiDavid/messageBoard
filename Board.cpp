//
// Created by david on 3/23/21.
//

#include "Board.hpp"
#include <iostream>


using namespace std;
string const ROW = "R";
string const COL = "C";

void ariel::Board::post(unsigned int row, unsigned int col, ariel::Direction direction, const string &st) {
    //check if the string is empty
    if (st.length() == 0) {
        return;
    }
    maxMinRowCol(row, col, direction, st.length());

    for (char ch : st) {
        string locationInMap;
        locationInMap += ROW + to_string(row);
        locationInMap += COL + to_string(col);

        Board::mapBoard[locationInMap] = ch;

        if (direction == Direction::Vertical) {
            row++;
        } else {
            col++;
        }

    }
}

std::string ariel::Board::read(unsigned int row, unsigned int col, Direction direction, unsigned int readLength) {
    string ans;
    while (readLength > 0) {
        string locationInMap;
        locationInMap += ROW + to_string(row);
        locationInMap += COL + to_string(col);
        if (direction == Direction::Vertical) {
            row++;
        } else {
            col++;
        }
        if (mapBoard[locationInMap] != 0) {
            ans += mapBoard[locationInMap];
        } else {
            ans += '_';
        }
        readLength--;
    }


    return ans;
}

void ariel::Board::show() {
    unsigned int minusCol=0;
    unsigned int minusRow=0;
    unsigned int plusCol=0;
    unsigned int plusRow=0;

    string board;
    string boardEnd;

    if (minRow!=0){
        minusRow=1;
    }
    else{
        string underline = "_";
        string temp = "_";
        for (unsigned int col = minCol ; col <= maxCol; ++col){ temp+=underline;}
        board += to_string(-1) + ": " +temp+"\n";
    }
    if (maxRow!=MAXUSINT){
        plusRow=1;
    }
    else{
        boardEnd += "4294967296 : ";
    }
    //we run from one row below the minimum row and until we reach one row
    //leshnot et minus ahad lemasheho aher
    for (unsigned int row = minRow - minusRow; row <= maxRow + plusRow; ++row) {
        board += to_string(row) + ": ";
        if (minCol!=0){
            minusCol=1;
        }
        if (maxCol!=MAXUSINT){
            plusRow=1;
        }
        for (unsigned int col = minCol - minusCol; col <= maxCol + maxCol; ++col) {
            string locationInMap;
            locationInMap += ROW + to_string(row);
            locationInMap += COL + to_string(col);

            if (mapBoard[locationInMap] != 0) {
                board += mapBoard[locationInMap];
            } else {
                board += "-";
            }
        }
        board += "\n";
    }
    board += boardEnd+"\n";

    std::cout << board;
}


void ariel::Board::maxMinRowCol(unsigned int row, unsigned int col, ariel::Direction direction, unsigned long length) {

    if (row < minRow) {
        minRow = row;
    }
    if (col < minCol) {
        minCol = col;
    }
    unsigned int addToRow = 0;
    unsigned int addToCol = 0;

    if (direction == Direction::Vertical) {
        addToRow += length;
    } else {
        addToCol += length;
    }

    if (row + addToRow > maxRow) {
        maxRow = row + addToRow;
    }
    if (col + addToCol > maxCol) {
        maxCol = col + addToCol;
    }

}
//constructor that initialize the variables
ariel::Board::Board() : maxCol(0), maxRow(0), minCol(MAXUSINT), minRow(MAXUSINT) {}

