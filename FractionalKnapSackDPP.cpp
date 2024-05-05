#include<iostream>
using namespace std;

// Function declarations
void swap(int& a, int& b);
void sort(int profit[], int weight[], int size);
double maximizeProfit(int profit[], int weight[], int size, int sackCapacity);

// Main driver function
int main() {
    int weight[] = {10, 20, 30};  // sample object weights
    int profit[] = {60, 100, 120};  // sample object profits
    int capacity = 50;  // capacity of the knapsack
    int size = sizeof(weight) / sizeof(weight[0]);  // total number of objects

    cout << "Maximum Value : " << maximizeProfit(profit, weight, size, capacity) << endl;

    return 0;
}

// Basic Swap function
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Sorting function that sorts the weight and profits of the object based on the profit-to-weight ratio
void sort(int profit[], int weight[], int size) {
    double profitToWeightRatio[20];  // array that stores the profit-to-weight ratio for all objects
    for (int i = 0; i < size; i++) {
        profitToWeightRatio[i] = (double)profit[i] / weight[i];
    }

    // sorts the profits and weights arrays
    for (int i = 0; i < size - 1; i++) {
        int maxRatioIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (profitToWeightRatio[j] > profitToWeightRatio[maxRatioIndex])
                maxRatioIndex = j;
        }

        swap(profit[i], profit[maxRatioIndex]);
        swap(weight[i], weight[maxRatioIndex]);
    }
}

double maximizeProfit(int profit[], int weight[], int size, int sackCapacity) {
    // Sorting
    sort(profit, weight, size);

    double answer = 0;  // Stores the maximum profit
    for (int i = 0; i < size; i++) {
        int currentItemWeight = weight[i];  // weight of the current object
        int currentItemProfit = profit[i];  // profit of the current object

        double profitToWeightRatio = (double)profit[i] / weight[i];  // calculate the profit-to-weight ratio for the current object

        // checks for capacity in the bag
        if (sackCapacity >= currentItemWeight) {
            answer += currentItemProfit;
            sackCapacity -= currentItemWeight;
        } else {
            answer += profitToWeightRatio * sackCapacity;
            sackCapacity = 0;
            break;
        }
    }

    return answer;
}

