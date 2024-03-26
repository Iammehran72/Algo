#include <iostream>

using namespace std;

bool subsetSum(int nums[], int n, int sum) {
    bool dp[n + 1][sum + 1];


    for (int i = 0; i <= n; ++i) {
        dp[i][0] = true;
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= sum; ++j) {
            if (j < nums[i - 1]) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
            }
        }
    }

    return dp[n][sum];
}

int main() {
    int nums[] = {3, 34, 4, 12, 5, 2}; 
    int n = sizeof(nums) / sizeof(nums[0]);
    int sum = 1020; 

    if (subsetSum(nums, n, sum)) {
        cout << "Yes, there exists a subset with sum " << sum << endl;
    } else {
        cout << "No, there doesn't exist a subset with sum " << sum << endl;
    }

    return 0;
}
