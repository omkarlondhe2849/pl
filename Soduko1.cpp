#include <iostream>
using namespace std;
#define SIZE 4

class Sudoku {
public:
    int grid[SIZE][SIZE];
    Sudoku() {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                grid[i][j] = 0;
            }
        }
    }
    void inputSudoku();
    void displaySudoku();
    bool isPresentInRow(int row, int num);
    bool isPresentInCol(int col, int num);
    bool isPresentInSubGrid(int row, int col, int num);
    bool solveSudoku(int row, int col);
    bool isValid(int row, int col, int num);
};

void Sudoku::inputSudoku() {
    int r, c, value;
    char ch;
    do {
        cout << "Enter row number (0-3), column number (0-3) and value (1-4):\n";
        cin >> r >> c >> value;
        if (r >= 0 && r < SIZE && c >= 0 && c < SIZE && value >= 1 && value <= SIZE) {
            grid[r][c] = value;
        } else {
            cout << "Invalid input! Please try again.\n";
        }
        cout << "Continue (y/n): ";
        cin >> ch;
    } while (ch == 'y');
}

void Sudoku::displaySudoku() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

bool Sudoku::isValid(int row, int col, int num) {
    return isPresentInRow(row, num) && isPresentInCol(col, num) && isPresentInSubGrid(row, col, num);
}

bool Sudoku::isPresentInRow(int row, int num) {
    for (int j = 0; j < SIZE; j++) {
        if (num == grid[row][j]) {
            return false;
        }
    }
    return true;
}

bool Sudoku::isPresentInCol(int col, int num) {
    for (int i = 0; i < SIZE; i++) {
        if (num == grid[i][col]) {
            return false;
        }
    }
    return true;
}

bool Sudoku::isPresentInSubGrid(int row, int col, int num) {
    int startRow = row - row % 2;
    int startCol = col - col % 2;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            if (grid[startRow + i][startCol + j] == num) {
                return false;
            }
        }
    }
    return true;
}

bool Sudoku::solveSudoku(int row, int col) {
    if (row == SIZE - 1 && col == SIZE) {
        return true;
    }
    if (col == SIZE) {
        row++;
        col = 0;
    }
    if (grid[row][col] > 0) {
        return solveSudoku(row, col + 1);
    }
    for (int num = 1; num <= SIZE; num++) {
        if (isValid(row, col, num)) {
            grid[row][col] = num;
            if (solveSudoku(row, col + 1)) {
                return true;
            }
            grid[row][col] = 0;
        }
    }
    return false;
}

int main() {
    Sudoku s;
    s.inputSudoku();
    if (s.solveSudoku(0, 0)) {
        cout << "Sudoku Solution:\n";
        s.displaySudoku();
    } else {
        cout << "No solution\n";
    }
    return 0;
}
