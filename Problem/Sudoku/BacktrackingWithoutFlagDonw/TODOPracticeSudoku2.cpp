#include <iostream>
#include <random>
#include <chrono>

using namespace std;
using namespace chrono;

int N = 9;
/*
int boardArr[9][9] = {{0, 0, 9, 0, 2, 3, 0, 0, 0},
                      {0, 8, 0, 0, 0, 0, 5, 0, 3},
                      {7, 0, 0, 0, 8, 0, 0, 0, 0},
                      {0, 0, 0, 0, 4, 0, 1, 5, 0},
                      {0, 0, 0, 2, 0, 6, 0, 0, 8},
                      {8, 0, 2, 1, 0, 0, 0, 0, 0},
                      {0, 6, 0, 3, 0, 2, 0, 0, 0},
                      {0, 4, 0, 0, 0, 0, 0, 3, 9},
                      {1, 0, 7, 0, 0, 0, 2, 0, 0}};
                      */
int boardArr[9][9] = {{5, 1, 9, 0, 2, 3, 8, 4, 0},
         {6, 8, 4, 9, 1, 7, 5, 2, 3},
         {7, 2, 0, 5, 8, 4, 9, 6, 1},
         {3, 9, 6, 7, 4, 8, 1, 5, 2},
         {4, 7, 1, 2, 5, 6, 3, 9, 8},
         {8, 5, 2, 1, 3, 0, 6, 7, 4},
         {9, 6, 8, 3, 7, 2, 4, 1, 5},
         {2, 4, 5, 8, 6, 1, 7, 3, 9},
         {1, 0, 7, 4, 9, 5, 2, 8, 0}};

void printArr(); // Function prototype

bool check_row(int arr[9][9], int row, int number) {
    bool flag = false;
    int num = 0;

    for (int col = 0; col < N; col++) {
        if (number == arr[row][col]) {
            num += 1;
        }
        if (num >= 1) {
            flag = true;
        }
    }

    return flag;
}

bool check_col(int arr[9][9], int column, int number) {
    bool flag = false;
    int num = 0;

    for (int row = 0; row < N; row++) {
        if (number == arr[row][column]) {
            num += 1;
        }
        if (num >= 1) {
            flag = true;
        }
    }

    return flag;
}

bool check_block(int arr[9][9], int row, int column, int number) {
    bool flag = false;
    int num = 0;

    int row_start = (int)(row / 3) * 3;
    int row_end = (int)(row / 3) * 3 + 3;
    int column_start = (int)(column / 3) * 3;
    int column_end = (int)(column / 3) * 3 + 3;
    // cout << row_start << ", " << column_start << endl;
    // cout << row_end << ", " << column_end << endl;

    for (int r = row_start; r < row_end; r++) {
        for (int c = column_start; c < column_end; c++) {
            if (number == arr[r][c]) {
                num += 1;
            }
            if (num >= 1) {
                flag = true;
            }
        }
    }

    return flag;
}

bool isSafe(int arr[9][9], int row, int column, int number) {
    if (check_block(arr, row, column, number) || check_row(arr, row, number) || check_col(arr, column, number)) {
        return false;
    }

    return true;
}
bool flag_done = false;

void solver(int (&arr)[9][9], int row, int column) {
    if (flag_done==false) {
        // If the last box is checked, break out of the solver function
        if ((row == N-1) && (column == N-1)) {
            flag_done = true;
            return;
        }

        // if the last column is checked, move to the next row and set column to 0 again
        /*
        if (column == N) {
            row += 1;
            column = 0;
        }
        */
        // check if the box is already have a number
        if (arr[row][column] != 0) {
            solver(arr, row, column+1);
        }

        /* check if the one of the number from 1-9 is able to fit in the box
        if one of the following checkRow, checkCol, checkBlock is true
        */
        for (int number = 1; number <= N; number++) {
            if (isSafe(arr, row, column, number)) {
                arr[row][column] = number;
                if (column == N) {
                    solver(arr, row+1, 0);
                } else {
                    solver(arr, row, column+1);
                }

                if (flag_done==false) {
                    arr[row][column] = 0;
                }
                
            }
        }

        return;
    }
}

int main() {
    solver(boardArr, 0, 0);
    printArr();
    
    return 0;
}

void printArr() {
    for (int x = 0; x < N; x++) {
        cout << endl;
        for (int y = 0; y < N; y++) {
            cout << boardArr[x][y] << ", ";
        }
    }
}