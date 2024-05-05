#include <iostream>

using namespace std;

int n = 8;
int arr[8] = {4, 6, 2, 5, 7, 9, 1, 3};

void swap(int a, int b) {
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

int partition(int l, int h) {
    int pivot = arr[l];
    int i = l;
    int j = h;

    while (i < j) {
        while (i < n && arr[i] <= pivot) i++;
        while (j >= 0 && arr[j] > pivot) j--;
        if (i < j) {
            swap(i, j);
        }
    }
    swap(j, l);
    return j;
}

void quickSort(int l, int h) {
    if (l < h) {
        int pivot = partition(l, h);
        quickSort(l, pivot - 1);
        quickSort(pivot + 1, h);
    }
}

int main() {
    quickSort(0, n - 1);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}

