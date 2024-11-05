#include <iostream>
#include <string>
using namespace std;

void findLCS(string X, string Y)
{
    int m = X.length();
    int n = Y.length();
    int dp[m + 1][n + 1];

    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
        }
    }

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (X[i - 1] == Y[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    cout << "Length of Longest Common Subsequence: " << dp[m][n] << "\n";

    int index = dp[m][n];
    string lcs(index, '\0');

    int i = m, j = n;
    while (i > 0 && j > 0)
    {
        if (X[i - 1] == Y[j - 1])
        {
            lcs[index - 1] = X[i - 1];
            i--;
            j--;
            index--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }

    cout << "Longest Common Subsequence: " << lcs << "\n";
}

int main()
{
    int choice;
    while (choice != 0)
    {
        cout << "Press 0 To Exit!\n";
        cout << "\nPress 1 to find Longest Common Subsequence\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 0:
            cout << "Exiting the program.\n";
            break;
        case 1:
        {
            string X, Y;
            cout << "Enter the first sequence: ";
            cin >> X;
            cout << "Enter the second sequence: ";
            cin >> Y;
            findLCS(X, Y);
            break;
        }
        default:
            cout << "Invalid choice. Please try again.\n";
            break;
        }
    }

    return 0;
}
