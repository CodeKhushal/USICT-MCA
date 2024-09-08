#include <iostream>
using namespace std;

// void displayMatrix(int arr[][50], int rows, int columns)
// {
//     for (int i = 0; i < rows; i++)
//     {
//         for (int j = 0; j < columns; j++)
//         {
//             cout << arr[i][j] << " ";
//         }
//         cout << endl;
//     }
// }

int main()
{
    int matrix[50][50], sparse[100][3];
    int nzero = 0, mr, mc, sr;

    cout << "Enter the number of rows you want in your matrix: ";
    cin >> mr;
    cout << "Enter the number of rows you want in your matrix: ";
    cin >> mc;

    for (int i = 0; i < mr; i++)
    {
        for (int j = 0; j < mc; j++)
        {
            cout << "Enter the element at position [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
            if (matrix[i][j] != 0)
                nzero++;
        }
    }
    cout << "\nNumber of non-zero elements in the matrix: " << nzero << endl;
    cout << "\nMatrix: " << endl;
    // displayMatrix(matrix, mr, mc);
    for (int i = 0; i < mr; i++)
    {
        for (int j = 0; j < mc; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    if (nzero > (mr * mc) / 4)
    {
        cout << "\nThe given matrix is not a sparse matrix!";
        return 0;
    }

    sr = nzero;
    sparse[0][0] = mr;
    sparse[0][1] = mc;
    sparse[0][2] = sr;
    int s = 1;
    for (int i = 0; i < mr; i++)
    {
        for (int j = 0; j < mc; j++)
        {
            if (matrix[i][j] != 0)
            {
                sparse[s][0] = i + 1;
                sparse[s][1] = j + 1;
                sparse[s][2] = matrix[i][j];
                s++;
            }
        }
    }
    cout << "\nSparse Matrix is:\n";
    // displayMatrix(sparse, sr,3);
    for (int i = 0; i < sr; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << sparse[i][j] << " ";
        }
        cout << endl;
    }
}
