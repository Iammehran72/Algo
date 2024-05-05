#include <iostream>

using namespace std;

#define MAX 10

int n = 5;
int arr[] = {1, 3, 4, 2, 0};

void merge(int left, int mid, int right) {
    int leftArraySize = mid - left + 1;
    int rightArraySize = right - mid;
    int leftArray[MAX], rightArray[MAX];

    for (int i = 0; i < leftArraySize; i++) {
        leftArray[i] = arr[left + i];
    }

    for (int i = 0; i < rightArraySize; i++) {
        rightArray[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0;
    int k = left;

    while (i < leftArraySize && j < rightArraySize) {
        if (leftArray[i] < rightArray[j]) {
            arr[k] = leftArray[i];
            i++;
        } else {
            arr[k] = rightArray[j];
            j++;
        }
        k++;
    }

    while (i < leftArraySize) {
        arr[k] = leftArray[i];
        i++;
        k++;
    }

    while (j < rightArraySize) {
        arr[k] = rightArray[j];
        j++;
        k++;
    }
}

void mergeSort(int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(left, mid);
        mergeSort(mid + 1, right);
        merge(left, mid, right);
    }
}

int main() {
    mergeSort(0, n - 1);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}

