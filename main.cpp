#include "rps.h"
using namespace std;
#include <iostream>

int main() {
    RPSGame game;
    while (true) {
        cout << "Welcome to rock, paper, scissors!" << endl;
        game.round();
        cout << "Press [1] if you would like to play again. Press any other key to stop" << endl;
        int input;
        cin >> input;
        if (input != 1) {
            return 0;
        }
    }
    return 0;
}