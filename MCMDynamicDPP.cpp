#include <iostream>
#include <limits.h>

#define MAX 100

using namespace std;

int MCM(int mat[], int n) {
    int M[MAX][MAX];
    int S[MAX][MAX];

    int cost;

    for (int d = 1; d < n - 1; d++) {
        for (int i = 1; i < n - d; i++) {
            int j = i + d;
            int minCost = INT_MAX;
            for (int k = i; k <= j - 1; k++) {
                cost = M[i][k] + M[k + 1][j] + mat[i - 1] * mat[k] * mat[j];
                if (cost < minCost) {
                    minCost = cost;
                    S[i][j] = k;
                }
            }

            M[i][j] = minCost;
        }
    }

    return M[1][n - 1];
}

int main() {
    int mat[] = {2, 4, 6, 8, 6};
    int size = 5;

    cout << MCM(mat, size);

    return 0;
}

