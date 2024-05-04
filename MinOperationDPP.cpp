#include <iostream>

using namespace std;

int min_operations(int n) {
    int dp[n + 1];
    dp[1] = 0;

    for (int i = 2; i <= n; ++i) {
        dp[i] = dp[i - 1] + 1;

        if (i % 2 == 0) {
            dp[i] = min(dp[i], dp[i / 2] + 1);
        }
        if (i % 3 == 0) {
            dp[i] = min(dp[i], dp[i / 3] + 1);
        }
    }

    return dp[n];
}

int main() {
    int n = 10;
    cout << "Minimum number of operations to reach " << n << " is " << min_operations(n) << endl;
    return 0;
}

