#include <iostream>

using namespace std;

int maxOf(int a, int b) {
    return a > b ? a : b;
}

int knapsack(int wt[], int val[], int W, int n) {
    if (n == 0 || W == 0)
        return 0;

    if (wt[n - 1] <= W) {
        return maxOf(val[n - 1] + knapsack(wt, val, W - wt[n - 1], n - 1), knapsack(wt, val, W, n - 1));
    } else {
        return knapsack(wt, val, W, n - 1);
    }
}

int main() {
    int wt[] = {2, 3, 4, 5};
    int val[] = {1, 2, 5, 6};
    int n = 4;
    int W = 7;

    int maxProfit = knapsack(wt, val, W, n);

    cout << maxProfit << endl;

    return 0;
}

