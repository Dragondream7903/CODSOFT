#include <iostream>
#include <vector>

// Function prototypes
void initializeBoard(std::vector<std::vector<char>>& board);
void displayBoard(const std::vector<std::vector<char>>& board);
bool makeMove(std::vector<std::vector<char>>& board, char player, int row, int col);
bool checkWin(const std::vector<std::vector<char>>& board, char player);
bool checkDraw(const std::vector<std::vector<char>>& board);
bool playAgain();

int main() {
    char currentPlayer = 'X';
    bool gameInProgress = true;

    do {
        std::vector<std::vector<char>> board(3, std::vector<char>(3, ' '));
        initializeBoard(board);

        do {
            displayBoard(board);

            int row, col;
            std::cout << "Player " << currentPlayer << ", enter your move (row and column): ";
            std::cin >> row >> col;

            row--;
            col--;

            if (makeMove(board, currentPlayer, row, col)) {
                if (checkWin(board, currentPlayer)) {
                    displayBoard(board);
                    std::cout << "Player " << currentPlayer << " wins!\n";
                    break;
                } else if (checkDraw(board)) {
                    displayBoard(board);
                    std::cout << "It's a draw!\n";
                    break;
                } else {
                    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
                }
            } else {
                std::cout << "Invalid move. Try again.\n";
            }

        } while (gameInProgress);

    } while (playAgain());

    std::cout << "Thanks for playing Tic-Tac-Toe!\n";

    return 0;
}

// Function to initialize the game board
void initializeBoard(std::vector<std::vector<char>>& board) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            board[i][j] = ' ';
        }
    }
}

// Function to display the current state of the board
void displayBoard(const std::vector<std::vector<char>>& board) {
    std::cout << "Current Board:\n";
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cout << board[i][j];
            if (j < 2) std::cout << " | ";
        }
        std::cout << std::endl;
        if (i < 2) std::cout << "---------\n";
    }
    std::cout << std::endl;
}

// Function to make a move on the board
bool makeMove(std::vector<std::vector<char>>& board, char player, int row, int col) {
    if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
        board[row][col] = player;
        return true;
    }
    return false;
}

// Function to check if the current player has won
bool checkWin(const std::vector<std::vector<char>>& board, char player) {
    // Check rows, columns, and diagonals
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }

    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }

    return false;
}

// Function to check if the game is a draw
bool checkDraw(const std::vector<std::vector<char>>& board) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

// Function to ask if the players want to play again
bool playAgain() {
    char choice;
    std::cout << "Do you want to play again? (y/n): ";
    std::cin >> choice;
    return (choice == 'y' || choice == 'Y');
}
