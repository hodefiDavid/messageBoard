/**
 * Test for Board.cpp
 *
 * AUTHORS: david
 *
 * Date: 2021-03
 */

#include "doctest.h"
#include "Board.hpp"


using namespace ariel;

#include <string>

using namespace std;
//          void post(unsigned int i,unsigned int i1, ariel::Direction direction, std::string st);
//
//        std::string read(unsigned i, unsigned i1, Direction direction, unsigned i2);

TEST_CASE ("CheckPost") {
    Board board;
            CHECK_NOTHROW(board.post(11, 11, Direction::Horizontal, "abcdabcd"));
            CHECK_NOTHROW(board.post(1, 1, Direction::Horizontal, "abcdabcd"));
            CHECK_NOTHROW(board.post(11, 11, Direction::Horizontal, ""));
            CHECK_NOTHROW(board.post(0, 0, Direction::Horizontal, ""));
            CHECK_NOTHROW(board.post(11, 11, Direction::Vertical, "Direction::Vertical"));
            CHECK_NOTHROW(board.post(11, 11, Direction::Vertical, "Direction::Vertical"));

            CHECK_THROWS(board.post(0, 0, Direction::Vertical, ""));
            CHECK_THROWS(board.post(1, 1, Direction::Vertical, "pp"));
            CHECK_THROWS(board.post(110, 110, Direction::Vertical, "p0p"));
            CHECK_THROWS(board.post(141, 141, Direction::Vertical, "p55p"));
            CHECK_THROWS(board.post(121, 121, Direction::Vertical, "pp"));

    /* Add more checks here */
}

TEST_CASE ("CheckRead") {
    Board board;
            CHECK_NOTHROW(board.read(11, 11, Direction::Horizontal, 555));
            CHECK_NOTHROW(board.read(1, 1, Direction::Horizontal, 555));
            CHECK_NOTHROW(board.read(11, 11, Direction::Horizontal, 555));
            CHECK_NOTHROW(board.read(0, 0, Direction::Horizontal, 555));
            CHECK_NOTHROW(board.read(11, 11, Direction::Vertical, 555));
            CHECK_NOTHROW(board.read(11, 11, Direction::Vertical, 555));

            CHECK_THROWS(board.read(0, 0, Direction::Horizontal, 555));
            CHECK_THROWS(board.read(1, 1, Direction::Horizontal, 555555));
            CHECK_THROWS(board.read(110, 110, Direction::Horizontal, 555));
            CHECK_THROWS(board.read(141, 141, Direction::Horizontal, 55555));
            CHECK_THROWS(board.read(121, 121, Direction::Horizontal, 555));

    /* Add more checks here */
}


TEST_CASE ("throws checks (good and bad snowman)") {


//            CHECK_THROWS(snowman(i));
}

/* Add more test cases here */
//add test for each body part
