#include <iostream>

using namespace std;

int minJumps(int arr[], int n) {
    if (n <= 1) return 0; // If there's only one element or none, no jumps needed

    int jumps[n]; // Initialize jumps array with maximum possible value
    jumps[0] = 0; // 0 jumps needed to reach the first element

    for (int i = 1; i < n; ++i) {
        jumps[i] = INT_MAX; // Initialize jumps to maximum possible value
        for (int j = 0; j < i; ++j) {
            if (j + arr[j] >= i && jumps[j] != INT_MAX) { // Check if we can reach i from j
                jumps[i] = min(jumps[i], jumps[j] + 1); // Update jumps if number of jumps from j is smaller
                break; // No need to check further, move to next i
            }
        }
    }

    return jumps[n - 1]; // Return the minimum number of jumps to reach the last element
}

int main() {
    int arr[] = {2, 3, 1, 1, 2, 4, 2, 0, 1, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Minimum number of jumps to reach the end: " << minJumps(arr, n) << endl;
    return 0;
}
