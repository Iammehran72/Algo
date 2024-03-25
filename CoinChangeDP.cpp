#include <iostream>

using namespace std;

int coinChange(int coins[], int coinsSize, int amount) {
    int dp[amount + 1];
    dp[0] = 0; // Base case: 0 coins needed to make 0 amount

    for (int i = 1; i <= amount; ++i) {
        dp[i] = amount + 1; // Initialize with amount + 1 (maximum value)
        for (int j = 0; j < coinsSize; ++j) {
            if (coins[j] <= i) {
                dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
            }
        }
    }

    return dp[amount] > amount ? -1 : dp[amount]; // If dp[amount] > amount, amount cannot be made up with given coins
}

int main() {
    int coins[] = {1, 2, 5};
    int coinsSize = sizeof(coins) / sizeof(coins[0]);
    int amount = 11;
    cout << "Minimum number of coins needed: " << coinChange(coins, coinsSize, amount) << endl;
    return 0;
}
