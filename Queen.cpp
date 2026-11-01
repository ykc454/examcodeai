#include <iostream>
#include <cmath>
using namespace std;

int board[20];
int n;

bool safe(int row, int col) {
    for (int i = 0; i < row; i++) {
        if (board[i] == col ||
            abs(board[i] - col) == abs(i - row)) {
            return false;
        }
    }
    return true;
}

bool solve(int row) {
    if (row == n)
        return true;

    for (int col = 0; col < n; col++) {
        if (safe(row, col)) {
            board[row] = col;

            if (solve(row + 1))
                return true;
        }
    }
    return false;
}


int main() {
    cout << "Enter board size (1-20): ";
    cin >> n;

    if (n < 1 || n > 20) {
        cout << "Invalid board size!";
        return 0;
    }

    if (solve(0)) {
        cout << "\nSolution:\n";

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i] == j)
                    cout << "Q ";
                else
                    cout << ". ";
            }
            cout << endl;
        }
    } else {
        cout << "No solution exists for board size " << n;
    }

    return 0;
}