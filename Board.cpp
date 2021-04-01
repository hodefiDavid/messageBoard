//
// Created by david on 3/23/21.
//

#include "Board.hpp"

using namespace std;
string const ROW= "R";
string const COL= "C";


std::string ariel::Board::read(unsigned int row, unsigned int col, Direction direction, unsigned int readLength) {
    string ans = "";
    while (readLength>0){
        string locationInMap = "";
        locationInMap += ROW+to_string(row);
        locationInMap += COL+to_string(col);
        if (direction == Direction::Vertical) {
            row++;
        }
        else{
            col++;
        }

        if (mapBoard[locationInMap]){
            ans+= mapBoard[locationInMap];
        }
        else{
            ans+='_';
        }
        readLength--;
    }


    return ans;
}

void ariel::Board::post(unsigned int row, unsigned int col, ariel::Direction direction, std::string st) {
   //check if the string is empty
    if(st.length()==0){
        return;
    }
    maxMinRowCol(row,col,direction,st.length());

    for (char & ch : st) {
        string locationInMap = "";
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

    string board = "";
    //need to create the route thiniking on start form min\min -> max\min
    //                                                  min\min -> max\min
    //                                                   also need to add a few _____
//                                                                              __x__
//                                                                              _____
//
//    unsigned long long index=0;
//    if(maxRow>0){
//
//        index = maxRow
//    }

    string locationInMap = "";
    locationInMap += ROW+to_string(minRow);
    locationInMap += COL+to_string(minCol);

    if (mapBoard[locationInMap]){


    }

void ariel::Board::maxMinRowCol(unsigned int row, unsigned int col, ariel::Direction direction, unsigned long length) {

    if(row<minRow){
        minRow=row;
    }
    if(col<minCol){
        minCol=col;
    }
    unsigned int addToRow=0,addToCol=0;
    if (direction==Direction::Vertical){
        addToRow+=length;
    } else{
        addToCol+=length;
    }

    if(row+addToRow>maxRow){
        minRow=row;
    }
    if(row+addToCol>maxCol){
        minCol=col;
    }

}

