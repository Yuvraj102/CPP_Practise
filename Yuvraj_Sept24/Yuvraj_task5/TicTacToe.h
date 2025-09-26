#ifndef TICTACTOE_H
#define TICTACTOE_H

class TicTacToe {
public:
    TicTacToe();            // constructor initializes board
    void playGame();        // main game loop

private:
    int board[3][3];        // 0 = empty, 1 = player1, 2 = player2

    void printBoard();
    bool makeMove(int player, int row, int col);
    int checkWin();         // 0 = no win, 1 = P1 wins, 2 = P2 wins
    bool isDraw();          // true if board full and no winner
};

#endif
