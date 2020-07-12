#include <stdc++.h>
using namespace std;

int count(const vector<int> &coins, int sum)
{
    vector<int> dp(sum + 1, 0);

    dp[0] = 1;

    for (int i = 0; i < coins.size(); i++) {
        for (int j = 0; j <= sum; j++) {
            if(coins[i] <= j) {
                dp[j] += dp[j - coins[i]];
            }
        }
    }

    return dp[sum];
}

int main()
{
    vector<int> coins = {1, 5, 10};
    int sum = 12;
    cout << count(coins, sum) << "\n";
    return 0;
}