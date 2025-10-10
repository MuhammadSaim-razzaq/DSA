#include <iostream>
#include <vector>
using namespace std;

bool isvalid(vector<vector<char>>& board, int row, int col, char num) {
    // Check row
    for (int j = 0; j < 9; j++)
        if (board[row][j] == num)
            return false;

    // Check column
    for (int i = 0; i < 9; i++)
        if (board[i][col] == num)
            return false;

    // Check 3x3 box
    int sRow = (row / 3) * 3;
    int sCol = (col / 3) * 3;
    for (int i = sRow; i < sRow + 3; i++)
        for (int j = sCol; j < sCol + 3; j++)
            if (board[i][j] == num)
                return false;

    return true;
}

bool solvesudoku(vector<vector<char>>& board, int row, int col) {
    // End of board
    if (row == 9)
        return true;

    // Move to next row if we reach end of current row
    if (col == 9)
        return solvesudoku(board, row + 1, 0);

    // Skip filled cells
    if (board[row][col] != '.')
        return solvesudoku(board, row, col + 1);

    // Try numbers 1–9
    for (char ch = '1'; ch <= '9'; ch++) {
        if (isvalid(board, row, col, ch)) {
            board[row][col] = ch;  // Place number

            // Recursive call for next cell
            if (solvesudoku(board, row, col + 1))
                return true;

            // Backtrack if failed
            board[row][col] = '.';
        }
    }

    // If no valid number found
    return false;
}

int main() {
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    if (solvesudoku(board, 0, 0)) {
        cout << "Solved Sudoku:\n";
        for (auto& row : board) {
            for (auto& ch : row)
                cout << ch << " ";
            cout << endl;
        }
    } else {
        cout << "No solution exists.\n";
    }

    return 0;
}
