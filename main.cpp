#include <iostream>
#include "Board.hpp"

using namespace std;
using namespace ariel;

int main() {

    ariel::Board board;
//void ariel::Board::post(unsigned int row, unsigned int col, ariel::Direction direction, std::string st) {
    char ch = 'c';
    char direction;
    unsigned int exit = 1;
    unsigned int col;
    unsigned int row;
    unsigned int length;
    string str;

    cout << "welcome to my message board!" << endl;

//    cout << "you have three option to choose what to do next:" << endl;
//    cout << "insert P to post a new message" << endl;
//    cout << "insert R to read a section of the message board" << endl;
//    cout << "insert S to show all message board" << endl;
//    cout << "insert E to exit message board" << endl;

    while (exit) {
        cout << "you have three option to choose what to do next:" << endl;
        cout << "insert P to post a new message" << endl;
        cout << "insert R to read a section of the message board" << endl;
        cout << "insert S to show all message board" << endl;
        cout << "insert E to exit message board" << endl;

        cin >> ch;
        //post a new message
        if (ch == 'P') {
            cout << "please choose where do you want to post," << endl;
            cout << "please insert the Row number (unsigned int)" << endl;
            cin >> col;
            cout << "please insert the Column number(unsigned int)" << endl;
            cin >> row;
            cout << "please insert your message:" << endl;
            cin >> str;
            cout << "please choose the direction, h for horizontal v for vertical" << endl;
            cin >> direction;
            if (direction == 'v') {
                board.post(row, col, Direction::Vertical, str);
            } else {
                board.post(row, col, Direction::Horizontal, str);
            }
        } else {
            //read a message
            if (ch == 'R') {
                cout << "please choose where do you want to read," << endl;
                cout << "please insert the Row number (unsigned int)" << endl;
                cin >> col;
                cout << "please insert the Column number(unsigned int)" << endl;
                cin >> row;
                cout << "please choose the how many chars you wanna read(unsigned int)" << endl;
                cin >> length;
                cout << "please choose the direction, h for horizontal v for vertical" << endl;
                cin >> direction;
                if (direction == 'v') {
                    board.post(row, col, Direction::Vertical, str);
                } else {
                    board.read(row, col, Direction::Horizontal, length);
                }
            } else {
                //show the board
                if (ch == 'S') {
                    board.show();
                } else {
                    if (ch == 'E') {
                        cout << "exiting the peogram" << endl;
                        exit = 0;
                    } else {
                        cout << "you have been entering unknown char, please try again" << endl;
                    }
                }
            }
        }

    }

    return 0;
}
