/*
(Turtle Graphics) The Logo language, which is popular among elementary school children, made the concept of turtle graphics famous. Imagine a mechanical turtle that walks around the room under the control of a C++ program. The turtle holds a pen in one of two positions, up or down. While the pen is down, the turtle traces out shapes as it moves; while the pen is up, the turtle moves about freely without writing anything. In this problem, you’ll simulate the operation of the turtle and create a computerized sketchpad as well.
Use a 20-by-20 array floor that is initialized to false. Read commands from an array that contains them. Keep track of the current position of the turtle at all times and whether the pen is currently up or down. Assume that the turtle always starts at position (0, 0) of the floor with its pen up. The set of turtle commands your program must process are shown in Fig. 7.27.
*/

#include <iostream>
#include <vector>

const int SIZE = 20;

enum Direction { RIGHT, DOWN, LEFT, UP };

int main() {
    bool floor[SIZE][SIZE] = {false};

    // initial state
    int row = 0, col = 0;
    bool penDown = false;
    Direction dir = RIGHT;

    // sample program from the book (draw 12x12 square)
    std::vector<std::pair<int,int>> commands = {
        {2,0}, {5,12}, {3,0}, {5,12}, {3,0}, {5,12}, {3,0}, {5,12},
        {1,0}, {6,0}, {9,0}
    };

    for (auto cmd : commands) {
        int command = cmd.first;
        int param = cmd.second;

        if (command == 1) {            // pen up
            penDown = false;
        } else if (command == 2) {     // pen down
            penDown = true;
        } else if (command == 3) {     // turn right
            dir = static_cast<Direction>((dir + 1) % 4);
        } else if (command == 4) {     // turn left
            dir = static_cast<Direction>((dir + 3) % 4); // +3 ≡ -1 mod 4
        } else if (command == 5) {     // move forward param steps
            for (int step = 0; step < param; ++step) {
                // mark current position if pen down
                if (penDown && row >= 0 && row < SIZE && col >= 0 && col < SIZE) {
                    floor[row][col] = true;
                }

                // move 1 step
                if (dir == RIGHT && col + 1 < SIZE) col++;
                else if (dir == DOWN && row + 1 < SIZE) row++;
                else if (dir == LEFT && col - 1 >= 0) col--;
                else if (dir == UP && row - 1 >= 0) row--;
            }
        } else if (command == 6) {     // print array
            for (int r = 0; r < SIZE; ++r) {
                for (int c = 0; c < SIZE; ++c) {
                    std::cout << (floor[r][c] ? '*' : ' ');
                }
                std::cout << "\n";
            }
            std::cout << "\n";
        } else if (command == 9) {     // end
            break;
        }
    }

    return 0;
}
