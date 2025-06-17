using namespace std;
#include <string>
#include <set>

struct RPSGame {
    const set<string> options = {"R", "P", "S"};

    string player1;
    string player2;

    void choice();

    void assign(string& player);

    string text(const string& ch);

    int whowon();

    void graphic(const string& player);

    void outcome();

    void round();

};