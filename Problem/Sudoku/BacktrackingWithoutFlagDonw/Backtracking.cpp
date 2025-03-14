#include <iostream>
using namespace std;

#define N 9


int main() {}
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