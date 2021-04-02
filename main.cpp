#include <iostream>
#include "Board.hpp"
using namespace std;
using namespace ariel;
int main() {
    std::cout << "Hello, World!" << std::endl;
    ariel::Board board;
//void ariel::Board::post(unsigned int row, unsigned int col, ariel::Direction direction, std::string st) {
    board.post(0,0,ariel::Direction::Vertical,"david");
    board.post(2,0,ariel::Direction::Vertical,"kk");
    board.post(2,2,ariel::Direction::Vertical,"k2k");
    board.show();
    return 0;
}
