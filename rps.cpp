#include "rps.h"
#include <cctype>
#include <iostream>
#include <algorithm>
using namespace std;

void RPSGame::choice() {
    cout << "Player 1's Turn\n"
            "Please input a character: [r] for rock, [p] for paper, or [s] for scissors." << endl;
    assign(player1);
    cout << "Player 2's Turn\n"
            "Please input a character: [r] for rock, [p] for paper, or [s] for scissors." << endl;
    assign(player2);
}

string RPSGame::text(const string& ch) {
    if (ch == "P")
        return "paper";
    else if (ch == "R")
        return "rock";
    else if (ch == "S")
        return "scissors";
    else
        return "";
}

void RPSGame::assign(string& player) {
    while (true){
        string input;
        getline(cin, input);
        transform(input.begin(), input.end(), input.begin(), ::toupper);
        auto it = options.find(input);
        if (it != options.end()) {
            string choice = text(input);
            cout << "You chose " << choice << endl;
            player = {input};
            graphic(player);
            return;
        } else {
            cout << "Please enter a valid character" << endl;
        }
    }
}

void RPSGame::graphic(const string& player) {
    if (player == "P") {
        cout << "         _______________" << '\n';
        cout << "    ()==(              (@==()" << '\n';
        cout << "         '______________'|" << '\n';
        cout << "           |             |" << '\n';
        cout << "           |             |" << '\n';
        cout << "         __)_____________|" << '\n';
        cout << "    ()==(               (@==()" << '\n';
        cout << "         '--------------'" << '\n';

    }
    if (player == "R") {
        cout << "       ,--.--._" << '\n';
        cout << "------\" _, \\___)" << '\n';
        cout << "        / _/____)" << '\n';
        cout << "        \\//(____)" << '\n';
        cout << "------\\     (__)" << '\n';
        cout << "       `-----\"" << '\n';
    }
    if (player == "S") {
        cout << "    _    _" << '\n';
        cout << "   (_)  / )" << '\n';
        cout << "     | (_/ " << '\n';
        cout << "    _+/  " << '\n';
        cout << "   //|\\" << '\n';
        cout << "  // | )" << '\n';
        cout << " (/  |/ " << '\n';
    }
}

int RPSGame::whowon() {
    if (player1 == player2) {
        return 0; 
    }
    if (player1 == player2)
        return 0; 
    
    if ((player1 == "R" && player2 == "P") || (player1 == "S" && player2 == "R"))
      return 2;

    return 1;
}

void RPSGame::outcome() {
    int winner = whowon();
    switch(winner){
        case(0):
            cout << "It's a Tie!" << endl;
            break;
        case(1):
            cout << "Player 1 Wins!" << endl;
            break;
        case(2):
            cout << "Player 2 Wins!" << endl;
            break;
        default: 
            cout << "Winner Undetermined!" << endl;
    }
    return;
}

void RPSGame::round() {
    choice();
    outcome();
}