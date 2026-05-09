#include <iostream>
using namespace std;

void printBoard(int board[9][9]) {
    for (int r = 0; r < 9; r++) {
        for (int c = 0; c < 9; c++) {
            cout << board[r][c] << " ";
        }
        cout << endl;
    }
}

bool safe(int board[9][9], int r, int c, int n) {
    for (int i = 0; i < 9; i++) {
        if (board[r][i] == n) return false;
    }
    
    for (int j = 0; j < 9; j++) {
        if (board[j][c] == n) return false;
    }
    
    int startR = r - r % 3;
    int startC = c - c % 3;
    for (int x = 0; x < 3; x++) {
        for (int y = 0; y < 3; y++) {
            if (board[x + startR][y + startC] == n) return false;
        }
    }
    
    return true;
}

bool solveSudoku(int board[9][9]) {
    int r = -1;
    int c = -1;
    bool empty = false;
    
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] == 0) {
                r = i;
                c = j;
                empty = true;
                break;
            }
        }
        if (empty) break;
    }
    
    if (!empty) return true;
    
    for (int n = 1; n <= 9; n++) {
        if (safe(board, r, c, n)) {
            board[r][c] = n;
            
            if (solveSudoku(board)) return true;
            
            board[r][c] = 0;
        }
    }
    
    return false;
}

int main() {
    int board[9][9];
    
    cout << "Enter the Sudoku board:" << endl;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> board[i][j];
        }
    }
    cout << endl;
    
    if (solveSudoku(board)) {
        cout << "Solved Board:" << endl;
        printBoard(board);
    }
    
    return 0;
}