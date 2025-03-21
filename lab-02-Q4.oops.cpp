#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class HittingGame {
private:
    int teamPlayers;
    int teamHits;
    int enemyHits;

public:
    HittingGame() {
        srand(time(0)); //ye seed for random number generation
        teamPlayers = rand() % 5 + 1;  
        teamHits = 0;
        enemyHits = 0;
    }

    void play() {
        cout << "Total No. Of Players in your team: " << teamPlayers << endl;
        for (int i = 0; i < teamPlayers; i++) {
            int num1 = rand() % 10 + 1;
            int num2 = rand() % 10 + 1;

            cout << "\nPair of numbers:\n";
            cout << "Number1: " << num1 << endl;
            cout << "Number2: " << num2 << endl;

            if (num1 == num2) {
                cout << "Enemy got hit by your team!" << endl;
                teamHits++;
            } else {
                cout << "You got hit by the enemy team!" << endl;
                enemyHits++;
            }
        }
        displayResult();
    }

    void displayResult() {
        cout << "\nGame Over!" << endl;
        if (teamHits > enemyHits)
            cout << "You won!" << endl;
        else if (teamHits < enemyHits)
            cout << "You lost!" << endl;
        else
            cout << "It's a draw!" << endl;
    }
};

int main() {
    HittingGame game;
    game.play();
    return 0;
}
