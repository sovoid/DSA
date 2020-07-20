/**

Problem Statement: Given a rod of length n inches and an array of prices that contains prices of all pieces of 
size smaller than n. Determine the maximum value obtainable by cutting up the rod and selling the pieces.

Solution: For rod of length n,

dp[n] = max(prices[i] + dp[n-i-1]) for i=0...n-1

*/

#include <bits/stdc++.h>
using namespace std;

int rod_cutting(const vector<int> &prices, int n)
{
    vector<int> dp(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            dp[i] = max(dp[i], prices[j] + dp[i - j - 1]);
        }
    }

    return dp[n];
}

int main()
{
    vector<int> prices = {1,
                          5,
                          8,
                          9,
                          10,
                          17,
                          17,
                          20};
    int n = 8;
    cout << rod_cutting(prices, n) << "\n";
    return 0;
}