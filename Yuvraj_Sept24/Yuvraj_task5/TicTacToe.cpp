#include <iostream>
#include "TicTacToe.h"

TicTacToe::TicTacToe() {
    // initialize all cells to 0 (empty)
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = 0;
}

void TicTacToe::printBoard() {
    std::cout << "\nBoard:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            char mark = ' ';
            if (board[i][j] == 1) mark = 'X';
            else if (board[i][j] == 2) mark = 'O';

            std::cout << " " << mark;
            if (j < 2) std::cout << " |";
        }
        std::cout << "\n";
        if (i < 2) std::cout << "---+---+---\n";
    }
    std::cout << "\n";
}

bool TicTacToe::makeMove(int player, int row, int col) {
    if (row < 0 || row > 2 || col < 0 || col > 2) {
        std::cout << "Invalid move! Out of bounds.\n";
        return false;
    }
    if (board[row][col] != 0) {
        std::cout << "Invalid move! Square already taken.\n";
        return false;
    }
    board[row][col] = player;
    return true;
}

int TicTacToe::checkWin() {
    // rows
    for (int i = 0; i < 3; i++)
        if (board[i][0] != 0 &&
            board[i][0] == board[i][1] &&
            board[i][1] == board[i][2])
            return board[i][0];

    // columns
    for (int j = 0; j < 3; j++)
        if (board[0][j] != 0 &&
            board[0][j] == board[1][j] &&
            board[1][j] == board[2][j])
            return board[0][j];

    // diagonals
    if (board[0][0] != 0 &&
        board[0][0] == board[1][1] &&
        board[1][1] == board[2][2])
        return board[0][0];

    if (board[0][2] != 0 &&
        board[0][2] == board[1][1] &&
        board[1][1] == board[2][0])
        return board[0][2];

    return 0; // no winner yet
}

bool TicTacToe::isDraw() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] == 0)
                return false;
    return checkWin() == 0;
}

void TicTacToe::playGame() {
    int currentPlayer = 1;
    while (true) {
        printBoard();
        std::cout << "Player " << currentPlayer << " (" << (currentPlayer == 1 ? "X" : "O")
                  << "), enter row and column (0-2): ";
        int row, col;
        std::cin >> row >> col;

        if (!makeMove(currentPlayer, row, col))
            continue; // invalid move, retry

        int winner = checkWin();
        if (winner != 0) {
            printBoard();
            std::cout << "Player " << winner << " wins!\n";
            break;
        }

        if (isDraw()) {
            printBoard();
            std::cout << "It's a draw!\n";
            break;
        }

        currentPlayer = (currentPlayer == 1) ? 2 : 1; // switch player
    }
}
