#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
//@TODO reattempt question later

// Function to move the tortoise using pointer
void moveTortoise(int* pos) {
    int i = 1 + std::rand() % 10; // random 1–10
    if (i >= 1 && i <= 5) {          // Fast plod (50%)
        *pos += 3;
    } else if (i == 6 || i == 7) {   // Slip (20%)
        *pos -= 6;
    } else {                         // Slow plod (30%)
        *pos += 1;
    }
    if (*pos < 1) *pos = 1;          // reset if below start
}

// Function to move the hare using pointer
void moveHare(int* pos) {
    int i = 1 + std::rand() % 10; // random 1–10
    if (i == 1 || i == 2) {          // Sleep (20%)
        // no move
    } else if (i == 3 || i == 4) {   // Big hop (20%)
        *pos += 9;
    } else if (i == 5) {             // Big slip (10%)
        *pos -= 12;
    } else if (i >= 6 && i <= 8) {   // Small hop (30%)
        *pos += 1;
    } else {                         // Small slip (20%)
        *pos -= 2;
    }
    if (*pos < 1) *pos = 1;          // reset if below start
}

// Function to print race track
void printRace(int tortoisePos, int harePos) {
    for (int i = 1; i <= 70; ++i) {
        if (i == tortoisePos && i == harePos) {
            std::cout << "OUCH!!!";
            i += 5; // skip because OUCH!!! took 6 chars
        } else if (i == tortoisePos) {
            std::cout << "T";
        } else if (i == harePos) {
            std::cout << "H";
        } else {
            std::cout << " ";
        }
    }
    std::cout << "\n";
}

int main() {
    std::srand(static_cast<unsigned>(std::time(0)));

    int tortoisePos = 1;
    int harePos = 1;

    std::cout << "BANG !!!!!\n";
    std::cout << "AND THEY'RE OFF !!!!!\n";

    // Run the race
    while (tortoisePos < 70 && harePos < 70) {
        moveTortoise(&tortoisePos);
        moveHare(&harePos);

        if (tortoisePos > 70) tortoisePos = 70;
        if (harePos > 70) harePos = 70;

        printRace(tortoisePos, harePos);
    }

    // Determine winner
    if (tortoisePos >= 70 && harePos >= 70) {
        std::cout << "It's a tie. (Tortoise favored!)\n";
    } else if (tortoisePos >= 70) {
        std::cout << "TORTOISE WINS!!! YAY!!!\n";
    } else {
        std::cout << "Hare wins. Yuch.\n";
    }

    return 0;
}
