#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void Create(int** Q, const int rowCount, const int colCount, const int Low, const int High, int row = 0, int col = 0);
void Print(int** Q, const int rowCount, const int colCount, int row = 0, int col = 0);
void Calc(int** Q, const int rowCount, const int colCount, int& S, int& k, int row = 0, int col = 0);
void Sort(int** Q, const int rowCount, const int colCount, int col = 0);
void SortColumn(int** Q, int col, int rowCount, int i0 = 0, int i1 = 0);

int main() {
    srand((unsigned)time(NULL));
    const int Low = -26;
    const int High = 23;
    const int rowCount = 8;
    const int colCount = 6;

    int** Q = new int* [rowCount];
    for (int i = 0; i < rowCount; i++)
        Q[i] = new int[colCount];

    Create(Q, rowCount, colCount, Low, High);
    Print(Q, rowCount, colCount);

    int S = 0;
    int k = 0;
    Calc(Q, rowCount, colCount, S, k);

    cout << "S = " << S << endl;
    cout << "k = " << k << endl;
    Print(Q, rowCount, colCount);

    Sort(Q, rowCount, colCount);
    Print(Q, rowCount, colCount);

    for (int i = 0; i < rowCount; i++)
        delete[] Q[i];
    delete[] Q;

    return 0;
}

void Create(int** Q, const int rowCount, const int colCount, const int Low, const int High, int row, int col) {
    if (row == rowCount) return;
    Q[row][col] = Low + rand() % (High - Low + 1);
    if (col + 1 < colCount)
        Create(Q, rowCount, colCount, Low, High, row, col + 1);
    else
        Create(Q, rowCount, colCount, Low, High, row + 1, 0);
}

void Print(int** Q, const int rowCount, const int colCount, int row, int col) {
    if (row == rowCount) {
        cout << endl;
        return;
    }
    if (col < colCount) {
        cout << setw(4) << Q[row][col];
        Print(Q, rowCount, colCount, row, col + 1);
    }
    else {
        cout << endl;
        Print(Q, rowCount, colCount, row + 1, 0);
    }
}

void Calc(int** Q, const int rowCount, const int colCount, int& S, int& k, int row, int col) {
    if (row == rowCount) return;
    if (Q[row][col] > 0 && Q[row][col] % 2 != 0) {
        S += Q[row][col];
        k++;
        Q[row][col] = 0;
    }
    if (col + 1 < colCount)
        Calc(Q, rowCount, colCount, S, k, row, col + 1);
    else
        Calc(Q, rowCount, colCount, S, k, row + 1, 0);
}

void Sort(int** Q, const int rowCount, const int colCount, int col) {
    if (col == colCount - 1) return;
    SortColumn(Q, col, rowCount);
    Sort(Q, rowCount, colCount, col + 1);
}

void SortColumn(int** Q, int col, int rowCount, int i0, int i1) {
    if (i0 == rowCount - 1) return;
    if (i1 < rowCount - i0 - 1) {
        if (Q[i1][col] > Q[i1 + 1][col]) {
            int tmp = Q[i1][col];
            Q[i1][col] = Q[i1 + 1][col];
            Q[i1 + 1][col] = tmp;
        }
        SortColumn(Q, col, rowCount, i0, i1 + 1);
    }
    else {
        SortColumn(Q, col, rowCount, i0 + 1, 0);
    }
}
