#include <bits/stdc++.h>
using namespace std;

int bell_numbers(int n)
{
    vector<vector<int>> bell(n + 1, vector<int>(n, -1));
    bell[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        bell[i][0] = bell[i - 1][i - 1];

        for (int j = 1; j <= i; j++)
        {
            bell[i][j] = bell[i - 1][j - 1] + bell[i][j - 1];
        }
    }
    return bell[n][0];
}

int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;
    cout << bell_numbers(n) << "\n";
    return 0;
}