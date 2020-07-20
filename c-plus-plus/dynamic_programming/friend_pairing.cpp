/**

Problem Statement: Given n friends, each one can remain single or can be paired up with some other friend. 
Each friend can be paired only once. Find out the total number of ways in which friends can remain single 
or can be paired up.

Solution: For each person, there are two possibilities:
1. Person is alone ==> f(n-1)
2. Person is paired ==> (n-1)*f(n-2)

*/

#include <bits/stdc++.h>
using namespace std;

int friends_pairing(int n)
{
    vector<int> dp(n + 1);
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i++)
    {
        dp[i] = dp[i - 1] + (i - 1) * dp[i - 2];
    }
    return dp[n];
}

int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;
    cout << friends_pairing(n) << "\n";
    return 0;
}