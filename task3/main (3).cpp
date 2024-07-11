#include <iostream>
#include <vector>

using namespace std;

class TicTacToe {
private:
    vector<vector<char>> board;
    char currentPlayer;

    void initializeBoard() {
        board = vector<vector<char>>(3, vector<char>(3, ' '));
    }

    void printBoard() {
        cout << "Current Board:\n";
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                cout << board[i][j];
                if (j < 2) cout << " | ";
            }
            cout << endl;
            if (i < 2) cout << "--|---|--\n";
        }
    }

    bool isBoardFull() {
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                if (board[i][j] == ' ') return false;
        return true;
    }

    bool checkWin() {
        // Check rows and columns
        for (int i = 0; i < 3; ++i) {
            if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer)
                return true;
            if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)
                return true;
        }

        // Check diagonals
        if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer)
            return true;
        if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)
            return true;

        return false;
    }

    void switchPlayer() {
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    bool isValidMove(int row, int col) {
        return (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ');
    }

public:
    TicTacToe() : currentPlayer('X') {
        initializeBoard();
    }

    void playGame() {
        bool gameWon = false;
        bool draw = false;

        while (!gameWon && !draw) {
            printBoard();
            int row, col;
            cout << "Player " << currentPlayer << ", enter your move (row and column): ";
            cin >> row >> col;

            if (isValidMove(row, col)) {
                board[row][col] = currentPlayer;
                gameWon = checkWin();
                draw = isBoardFull();
                if (!gameWon && !draw) switchPlayer();
            } else {
                cout << "Invalid move. Try again.\n";
            }
        }

        printBoard();
        if (gameWon) {
            cout << "Player " << currentPlayer << " wins!\n";
        } else if (draw) {
            cout << "The game is a draw!\n";
        }
    }
};

int main() {
    char playAgain;
    do {
        TicTacToe game;
        game.playGame();
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');

    return 0;
}