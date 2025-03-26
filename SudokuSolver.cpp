#include <iostream>
using namespace std;

const int SIZE = 9;

// Function to print the Sudoku grid
void printGrid(int grid[SIZE][SIZE]) {
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            cout << grid[row][col] << " ";
        }
        cout << endl;
    }
}

// Function to check if it's safe to place a number in the grid
bool isSafe(int grid[SIZE][SIZE], int row, int col, int num) {
    // Check row
    for (int x = 0; x < SIZE; x++) {
        if (grid[row][x] == num) {
            return false;
        }
    }

    // Check column
    for (int x = 0; x < SIZE; x++) {
        if (grid[x][col] == num) {
            return false;
        }
    }

    // Check 3x3 sub-grid
    int startRow = row - row % 3, startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i + startRow][j + startCol] == num) {
                return false;
            }
        }
    }

    return true; // No conflict, safe to place the number
}

// Function to find an empty location in the grid
bool findEmptyLocation(int grid[SIZE][SIZE], int &row, int &col) {
    for (row = 0; row < SIZE; row++) {
        for (col = 0; col < SIZE; col++) {
            if (grid[row][col] == 0) {
                return true; // Empty cell found
            }
        }
    }
    return false; // No empty cells left
}

// Backtracking function to solve the Sudoku
bool solveSudoku(int grid[SIZE][SIZE]) {
    int row, col;

    // If no empty location is found, the puzzle is solved
    if (!findEmptyLocation(grid, row, col)) {
        return true;
    }

    // Try placing digits 1 to 9 in the empty cell
    for (int num = 1; num <= 9; num++) {
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num; // Place the number

            // Recur to solve the rest of the grid
            if (solveSudoku(grid)) {
                return true;
            }

            // Undo the move (backtrack)
            grid[row][col] = 0;
        }
    }

    return false; // Trigger backtracking
}

int main() {
    // Example Sudoku puzzle (0 represents an empty cell)
    int grid[SIZE][SIZE] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    cout << "Original Sudoku puzzle:\n";
    printGrid(grid);

    if (solveSudoku(grid)) {
        cout << "\nSolved Sudoku puzzle:\n";
        printGrid(grid);
    } else {
        cout << "\nNo solution exists for the given Sudoku puzzle.\n";
    }

    return 0;
}
