#include <iostream>
#include <iomanip>
using namespace std;

const int SIZE = 12;

// Function to print the maze
void printMaze(char maze[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << maze[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
}

// Recursive function to traverse the maze
bool mazeTraverse(char maze[SIZE][SIZE], int x, int y) {
    // If out of bounds or wall, return false
    if (x < 0 || x >= SIZE || y < 0 || y >= SIZE || maze[x][y] == '#')
        return false;

    // If we found the exit (on boundary and is a '.')
    if ((x == 0 || x == SIZE - 1 || y == 0 || y == SIZE - 1) && maze[x][y] == '.') {
        maze[x][y] = 'X';
        printMaze(maze);
        cout << "Exit found at (" << x << "," << y << ")!" << endl;
        return true;
    }

    // If already visited, return false
    if (maze[x][y] == 'X')
        return false;

    // Mark current spot
    maze[x][y] = 'X';
    printMaze(maze);

    // Try moving in all four directions (down, right, up, left)
    if (mazeTraverse(maze, x + 1, y)) return true; // down
    if (mazeTraverse(maze, x, y + 1)) return true; // right
    if (mazeTraverse(maze, x - 1, y)) return true; // up
    if (mazeTraverse(maze, x, y - 1)) return true; // left

    // Backtrack (optional, here we just mark dead-end with 'X')
    return false;
}

int main() {
    char maze[SIZE][SIZE] = {
        { '#','#','#','#','#','#','#','#','#','#','#','#' },
        { '#','.','.','.','#','.','.','.','.','.','.','#' },
        { '.','.','#','.','#','.','#','#','#','#','.','#' },
        { '#','#','#','.','#','.','.','.','.','#','.','#' },
        { '#','.','.','.','.','#','#','#','.','#','.','.' },
        { '#','#','#','#','.','#','.','#','.','#','.','#' },
        { '#','.','.','#','.','#','.','#','.','#','.','#' },
        { '#','#','.','#','.','#','.','#','.','#','.','#' },
        { '#','.','.','.','.','.','.','.','.','#','.','#' },
        { '#','#','#','#','#','#','.','#','#','#','.','#' },
        { '#','.','.','.','.','.','.','#','.','.','.','#' },
        { '#','#','#','#','#','#','#','#','#','#','#','#' }
    };

    cout << "Initial Maze:\n";
    printMaze(maze);

    
    mazeTraverse(maze, 2, 0);

    return 0;
}
