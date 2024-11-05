#include <iostream>
#include <vector>

using namespace std;

bool isSafe(const vector<vector<int>>& board, int row, int col, int n) {
    // Check the column
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1) return false;
    }

    // Check the upper left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) return false;
    }

    // Check the upper right diagonal
    for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 1) return false;
    }

    return true;
}

void solveNQueensUtil(vector<vector<int>>& board, int row, int n, vector<vector<vector<int>>>& solutions) {
    // If all queens are placed
    if (row == n) {
        solutions.push_back(board); // Store the solution
        return;
    }

    // Try placing the queen in each column of the current row
    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col, n)) {
            board[row][col] = 1; // Place queen

            solveNQueensUtil(board, row + 1, n, solutions); // Recur to place the next queen

            board[row][col] = 0; // Backtrack
        }
    }
}

void printBoard(const vector<vector<int>>& board) {
    for (const auto& row : board) {
        for (int col : row) {
            cout << (col == 1 ? "Q " : ". ");
        }
        cout << endl;
    }
    cout << endl; // Separate solutions with a newline
}

void solveNQueens(int n) {
    vector<vector<int>> board(n, vector<int>(n, 0));
    
    // Place the first queen at (0, 0)
    board[0][0] = 1;

    vector<vector<vector<int>>> solutions; // To store all the solutions

    // Start solving from the second row
    solveNQueensUtil(board, 1, n, solutions);

    // Print all solutions
    if (solutions.empty()) {
        cout << "No solution exists." << endl;
    } else {
        for (const auto& solution : solutions) {
            printBoard(solution);
        }
    }
}

int main() {
    int n;
    cout << "Enter the size of the board (n): ";
    cin >> n;

    if (n < 1) {
        cout << "Please enter a valid size." << endl;
        return 1;
    }
    
    solveNQueens(n);
    return 0;
}