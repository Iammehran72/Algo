#include <iostream>

using namespace std;

#define MAX 100

int maxOf(int a, int b) {
    return a > b ? a : b;
}

int knapsack(int wt[], int val[], int W, int n) {
    int T[MAX][MAX];  // dynamic storage array

    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= W; j++) {
            if (i == 0 || j == 0) {
                T[i][j] = 0;
            } else if (wt[i - 1] <= j)
                T[i][j] = maxOf(val[i - 1] + T[i - 1][j - wt[i - 1]], T[i - 1][j]);
            else
                T[i][j] = T[i - 1][j];
        }

    return T[n][W];
}

int main() {
    int wt[] = {2, 3, 4, 5};   // weight array
    int val[] = {1, 2, 5, 6};  // profit array
    int n = 4;  // total number of items
    int W = 8;  // total capacity of the knapsack

    int maxProfit = knapsack(wt, val, W, n);

    cout << maxProfit << endl;

    return 0;
}

