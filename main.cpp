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
    unsigned int printInstructions;

    string str;

    cout << "welcome to my message board!" << endl;
    cout << "do you want to show the option every time? y/n" << endl;
    cin >> ch;
    if (ch == 'y') {
        printInstructions = 1;
    } else {
        printInstructions = 0;
    }


    while (exit) {
        if (printInstructions) {
            cout << "you have a few option to choose what to do next:" << endl;
            cout << "insert P to post a new message" << endl;
            cout << "insert R to read a section of the message board" << endl;
            cout << "insert S to show all message board" << endl;
            cout << "insert E to exit message board" << endl;
        }

        cin >> ch;
        //post a new message
        if (ch == 'P') {
            if (printInstructions) {
                cout << "please choose where do you want to post," << endl;

                cout << "please insert the Row number (unsigned int)" << endl;
            }
            cin >> col;
            if (printInstructions) {
                cout << "please insert the Column number(unsigned int)" << endl;
            }
            cin >> row;
            if (printInstructions) {
                cout << "please insert your message:" << endl;
            }
            cin >> str;
            if (printInstructions) {
                cout << "please choose the direction, h for horizontal v for vertical" << endl;
            }
            cin >> direction;
            if (direction == 'v') {
                board.post(row, col, Direction::Vertical, str);
            } else {
                board.post(row, col, Direction::Horizontal, str);
            }
        } else {
            //read a message
            if (ch == 'R') {
                if (printInstructions) {
                    cout << "please choose where do you want to read," << endl;

                    cout << "please insert the Row number (unsigned int)" << endl;
                }
                cin >> col;
                if (printInstructions) {

                    cout << "please insert the Column number(unsigned int)" << endl;
                }
                cin >> row;
                if (printInstructions) {

                    cout << "please choose the how many chars you wanna read(unsigned int)" << endl;
                }
                cin >> length;
                if (printInstructions) {
                    cout << "please choose the direction, h for horizontal v for vertical" << endl;
                }
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
                        if (printInstructions) {
                            cout << "you have been entering unknown char, please try again" << endl;
                        }
                    }
                }
            }
        }

    }

    return 0;
}
