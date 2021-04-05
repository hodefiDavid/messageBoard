//
// Created by david on 3/23/21.
//

#include "Board.hpp"
#include <iostream>


using namespace std;
string const ROW= "R";
string const COL= "C";


std::string ariel::Board::read(unsigned int row, unsigned int col, Direction direction, unsigned int readLength) {
    string ans;
    while (readLength>0){
        string locationInMap;
        locationInMap += ROW+to_string(row);
        locationInMap += COL+to_string(col);
        if (direction == Direction::Vertical) {
            row++;
        }
        else{
            col++;
        }
        if (mapBoard[locationInMap] != 0){
            ans+= mapBoard[locationInMap];
        }
        else{
            ans+='_';
        }
        readLength--;
    }


    return ans;
}

void ariel::Board::post(unsigned int row, unsigned int col, ariel::Direction direction, const string &st) {
   //check if the string is empty
    if(st.length()==0){
        return;
    }
    maxMinRowCol(row,col,direction,st.length());

    for (char ch : st) {
        string locationInMap;
        locationInMap += ROW+to_string(row);
        locationInMap += COL+to_string(col);

        Board::mapBoard[locationInMap] = ch;

        if (direction == Direction::Vertical) {
            row++;
        }
        else{
            col++;
        }

    }
}

void ariel::Board::show() {

    string board;

    for (unsigned int row = minRow - 1; row < maxRow + 1; ++row) {
        board+=to_string(row)+": ";
        for (unsigned int col = minCol - 1; col <= maxCol + 1 ; ++col) {
            string locationInMap;
            locationInMap += ROW+to_string(row);
            locationInMap += COL+to_string(col);

            if (mapBoard[locationInMap] != 0){
                board+=mapBoard[locationInMap];
            }
            else{
            board+="-";}
        }
        board+="\n";
        }

    std::cout<<board;
    }


void ariel::Board::maxMinRowCol(unsigned int row, unsigned int col, ariel::Direction direction, unsigned long length) {

    if(row<minRow){
        minRow=row;
    }
    if(col<minCol){
        minCol=col;
    }
    unsigned int addToRow=0;
    unsigned int addToCol=0;

    if (direction==Direction::Vertical){
        addToRow+=length;
    } else{
        addToCol+=length;
    }

    if(row+addToRow>maxRow){
        maxRow=row+addToRow;
    }
    if(col+addToCol>maxCol){
        maxCol=col+addToCol;
    }

}

ariel::Board::Board(): maxCol(0), maxRow(0),minCol(MAXUSINT),minRow(MAXUSINT) {

}

