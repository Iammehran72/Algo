#include <iostream>

using namespace std;

int rob(int houses[], int size) {
    if (size == 0) return 0;
    if (size == 1) return houses[0];

    int dp[size];
    dp[0] = houses[0];
    dp[1] = max(houses[0], houses[1]);

    for (int i = 2; i < size; ++i) {
        dp[i] = max(houses[i] + dp[i-2], dp[i-1]);
    }

    return dp[size - 1];
}

int main() {
    int houses[] = {2, 7, 9, 3, 1};
    int size = sizeof(houses) / sizeof(houses[0]);
    cout << "Maximum amount that can be robbed: " << rob(houses, size) << endl;
    return 0;
}
