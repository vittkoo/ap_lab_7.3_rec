#include <iostream>
#include <iomanip>
using namespace std;

void InputRow(int** a, const int rowNo, const int colCount, int colNo);
void InputRows(int** a, const int rowCount, const int colCount, int rowNo);
void PrintRow(int** a, const int rowNo, const int colCount, int colNo);
void PrintRows(int** a, const int rowCount, const int colCount, int rowNo);
void FindEqualRowAndColumn(int** a, const int n, int k);
bool CheckEquality(int** a, int k, const int n, int j);
int SumNegativeRow(int** a, const int n, int rowNo, int colNo, bool hasNegative, int rowSum);

int main()
{
    int n;
    cout << "n = ";
    cin >> n;

    int** a = new int* [n];
    for (int i = 0; i < n; i++)
        a[i] = new int[n];

    InputRows(a, n, n, 0);
    PrintRows(a, n, n, 0);

    FindEqualRowAndColumn(a, n, 0);

    int sum = SumNegativeRow(a, n, 0, 0, false, 0);
    cout << "sum = " << sum << endl;

    for (int i = 0; i < n; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}

void InputRow(int** a, const int rowNo, const int colCount, int colNo)
{
    cout << "a[" << rowNo << "][" << colNo << "] = ";
    cin >> a[rowNo][colNo];
    if (colNo < colCount - 1)
        InputRow(a, rowNo, colCount, colNo + 1);
    else
        cout << endl;
}

void InputRows(int** a, const int rowCount, const int colCount, int rowNo)
{
    InputRow(a, rowNo, colCount, 0);
    if (rowNo < rowCount - 1)
        InputRows(a, rowCount, colCount, rowNo + 1);
    else
        cout << endl;
}

void PrintRow(int** a, const int rowNo, const int colCount, int colNo)
{
    cout << setw(4) << a[rowNo][colNo];
    if (colNo < colCount - 1)
        PrintRow(a, rowNo, colCount, colNo + 1);
    else
        cout << endl;
}

void PrintRows(int** a, const int rowCount, const int colCount, int rowNo)
{
    PrintRow(a, rowNo, colCount, 0);
    if (rowNo < rowCount - 1)
        PrintRows(a, rowCount, colCount, rowNo + 1);
    else
        cout << endl;
}

bool CheckEquality(int** a, int k, const int n, int j)
{
    if (j == n)
        return true;
    if (a[k][j] != a[j][k])
        return false;
    return CheckEquality(a, k, n, j + 1);
}

void FindEqualRowAndColumn(int** a, const int n, int k)
{
    if (k == n)
        return;

    if (CheckEquality(a, k, n, 0))
        cout << "Row " << k << " is equal to Column " << k << endl;

    FindEqualRowAndColumn(a, n, k + 1);
}

int SumNegativeRow(int** a, const int n, int rowNo, int colNo, bool hasNegative, int rowSum)
{
    if (rowNo == n)
        return 0;

    if (colNo < n) {
        if (a[rowNo][colNo] < 0)
            hasNegative = true;
        rowSum += a[rowNo][colNo];
        return SumNegativeRow(a, n, rowNo, colNo + 1, hasNegative, rowSum);
    }
    else {
        int sum = 0;
        if (hasNegative)
            sum = rowSum;
        return sum + SumNegativeRow(a, n, rowNo + 1, 0, false, 0);
    }
}
