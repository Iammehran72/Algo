#include <iostream>

using namespace std;

int minCoins(int coins[], int n, int amount) {
    int dp[amount + 1];
    dp[0] = 0;

    for (int i = 1; i <= amount; ++i) {
        dp[i] = amount + 1;
        for (int j = 0; j < n; ++j) {
            if (i >= coins[j] && dp[i - coins[j]] + 1 < dp[i]) {
                dp[i] = dp[i - coins[j]] + 1;
            }
        }
    }

    return dp[amount] > amount ? -1 : dp[amount];
}

int main() {
    int coins[] = {1, 3, 4};
    int n = sizeof(coins) / sizeof(coins[0]);
    int amount = 6;
    cout << "Minimum number of coins needed to make change for " << amount << " cents: " << minCoins(coins, n, amount) << endl;
    return 0;
}

