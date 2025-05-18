#include <iostream>
using namespace std;

void printMatrix(int arr[100][100], int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int a1[100][100], a2[100][100], sum[100][100], rows, columns;
    cout << "Enter the number of rows in matrices: ";
    cin >> rows;

    cout << "Enter the number of columns in matrices: ";
    cin >> columns;

    cout << "Enter the elements of matrix 1:" << endl;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            cout << "Enter the value of a[" << i << j << "]: ";
            cin >> a1[i][j];
        }
    }
    printMatrix(a1, rows, columns);

    cout << "\nEnter the elements of matrix 2:" << endl;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            cout << "Enter the value of a[" << i << j << "]: ";
            cin >> a2[i][j];
        }
    }
    printMatrix(a2, rows, columns);

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            sum[i][j] = a1[i][j] + a2[i][j];
        }
    }
    cout << "\nSum of both the matrices is:\n";
    printMatrix(sum, rows, columns);
    return 0;
}