#include <iostream>
#include <string>
using namespace std;

#define N 5

char grid[N][N] = {
    {'P','A','R','R','O'},
    {'L','I','O','N','E'},
    {'E','A','T','O','P'},
    {'R','T','P','A','R'},
    {'O','N','E','T','L'}
};

int visited[N][N];
int solution[N][N];
int totalPaths = 0;

// Directions (up, down, left, right)
int dirRow[] = {-1, 1, 0, 0};
int dirCol[] = {0, 0, -1, 1};

void printSolution(char mark)
{
    cout << "\nPath " << totalPaths << ":\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (solution[i][j]) cout << mark << " ";
            else cout << "- ";
        }
        cout << endl;
    }
}

void searchWord(string word, int i, int j, int index, char mark)
{
    if (i < 0 || j < 0 || i >= N || j >= N) return;
    if (visited[i][j] || grid[i][j] != word[index]) return;

    // Mark visited
    visited[i][j] = 1;
    solution[i][j] = 1;

    // If word is found completely
    if (index == word.size() - 1) {
        totalPaths++;
        printSolution(mark);
        visited[i][j] = 0;
        solution[i][j] = 0;
        return;
    }

    // Explore 4 directions
    for (int d = 0; d < 4; d++) {
        searchWord(word, i + dirRow[d], j + dirCol[d], index + 1, mark);
    }

    // Backtrack
    visited[i][j] = 0;
    solution[i][j] = 0;
}

void findWord(string word, char mark)
{
    totalPaths = 0;
    cout << "\nSearching for word: " << word << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (grid[i][j] == word[0])
                searchWord(word, i, j, 0, mark);
        }
    }
    cout << "Total paths for " << word << ": " << totalPaths << endl;
}

int main()
{
    findWord("LION", 'L');
    findWord("PARROT", 'P');
    findWord("EAT", 'E');

    return 0;
}
