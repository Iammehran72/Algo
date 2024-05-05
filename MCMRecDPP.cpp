#include <iostream>
#include <limits.h>

using namespace std;

int MCM(int mat[], int low, int high) {
    if (low == high) {
        return 0;
    }

    int minCost = INT_MAX;
    for (int k = low; k < high; k++) {
        int cost = MCM(mat, low, k) + MCM(mat, k + 1, high) + mat[low - 1] * mat[k] * mat[high];
        if (cost < minCost)
            minCost = cost;
    }

    return minCost;
}

int main() {
    int mat[] = {2, 4, 6, 8, 6};
    int size = 5;

    cout << "Minimum Cost: " << MCM(mat, 1, size - 1);
    return 0;
}

