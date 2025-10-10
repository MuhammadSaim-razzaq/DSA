#include<iostream>
#include<vector>
using namespace std;

bool isSafe(vector<vector<char>> &board, int row, int col, int n) {
    // Check upper column
    for (int i = 0; i < row; i++)
        if (board[i][col] == 'Q') return false;

    // Check upper left diagonal
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 'Q') return false;

    // Check upper right diagonal
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
        if (board[i][j] == 'Q') return false;

    return true;
}

void nQueenWrong(int row, int n, vector<vector<char>> &board) {
    if (row == n) {
        cout << "✅ One configuration:\n";
        for (auto &r : board) {
            for (char c : r) cout << c << " ";
            cout << endl;
        }
        cout << "--------------------\n";
        return;
    }

    for (int j = 0; j < n; j++) {
        if (isSafe(board, row, j, n)) {
            board[row][j] = 'Q';
        }
    }

    // ❌ recursion outside the loop
    nQueenWrong(row + 1, n, board);
}

int main() {
    int n = 4;
    vector<vector<char>> board(n, vector<char>(n, '.'));

    cout << "❌ Wrong Version (recursion outside loop):\n";
    nQueenWrong(0, n, board);
}




