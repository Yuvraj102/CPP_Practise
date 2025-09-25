/*
(Craps Game Modification) Modify the program of Fig. 6.11 to play 1000 games of craps. The program should keep track of the statistics and answer the following questions:
a) How many games are won on the 1st roll, 2nd roll, ..., 20th roll, and after the 20th roll?
b) Howmanygamesarelostonthe1stroll,2ndroll,...,20throll,andafterthe20throll?
c) What are the chances of winning at craps? [Note: You should discover that craps is one
of the fairest casino games. What do you suppose this means?]
d) What’stheaveragelengthofagameofcraps?
e) Do the chances of winning improve with the length of the game?
*/


#include <iostream>
#include <cstdlib>
#include <ctime>

enum Status { CONTINUE, WON, LOST };

int rollDice() {
    int die1 = 1 + std::rand() % 6;
    int die2 = 1 + std::rand() % 6;
    return die1 + die2;
}

int main() {
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    const int GAMES = 1000;
    int wins[21] = {0};   // index 1..19 = exact roll, 20 = "20 or more"
    int losses[21] = {0};
    int totalWins = 0, totalLosses = 0;
    int totalRollsAllGames = 0;

    for (int game = 0; game < GAMES; ++game) {
        int rollCount = 1;
        int myPoint = 0;
        Status gameStatus;

        int sum = rollDice();

        // first roll outcome
        switch (sum) {
            case 7: case 11:
                gameStatus = WON;
                break;
            case 2: case 3: case 12:
                gameStatus = LOST;
                break;
            default:
                gameStatus = CONTINUE;
                myPoint = sum;
                break;
        }

        // continue rolling until win or loss
        while (gameStatus == CONTINUE) {
            sum = rollDice();
            ++rollCount;

            if (sum == myPoint) gameStatus = WON;
            else if (sum == 7) gameStatus = LOST;
        }

        int bucket = (rollCount <= 20) ? rollCount : 20;
        if (gameStatus == WON) { ++wins[bucket]; ++totalWins; }
        else { ++losses[bucket]; ++totalLosses; }

        totalRollsAllGames += rollCount;
    }

    // Print breakdown for wins and losses
    std::cout << "\n--- Craps simulation: " << GAMES << " games ---\n\n";

    std::cout << "Wins by roll number:\n";
    for (int i = 1; i <= 20; ++i) {
        if (i < 20)
            std::cout << "  Roll " << i << ": " << wins[i] << '\n';
        else
            std::cout << "  After 20 rolls: " << wins[i] << '\n';
    }

    std::cout << "\nLosses by roll number:\n";
    for (int i = 1; i <= 20; ++i) {
        if (i < 20)
            std::cout << "  Roll " << i << ": " << losses[i] << '\n';
        else
            std::cout << "  After 20 rolls: " << losses[i] << '\n';
    }

    std::cout << "\nTotals:\n";
    std::cout << "  Total wins:  " << totalWins << '\n';
    std::cout << "  Total losses:" << totalLosses << '\n';

    double winChance = (static_cast<double>(totalWins) / GAMES) * 100.0;
    std::cout << "\nChance of winning (empirical): " << winChance << " %\n";

    double avgLength = static_cast<double>(totalRollsAllGames) / GAMES;
    std::cout << "Average game length (rolls): " << avgLength << '\n';

    std::cout << "\nObservation=\n";
    std::cout << "   (a) & (b) are listed above.\n";
    std::cout << "   (c) Overall win chance is about 49.3% in theory (close to fair).\n";
    std::cout << "   (d) Average game length ≈ 3.38 rolls.\n";
    std::cout << "   (e) Win chance does not improve with game length.\n";

    return 0;
}
