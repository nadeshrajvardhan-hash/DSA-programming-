#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int partition(vector<int> &arr, int low, int high) {
    int pivot = arr[low]; // Pivot value
    int i = low;
    int j = high;

    while (i < j) {
        // Find element greater than pivot
        while (i <= high - 1 && arr[i] <= pivot) {
            i++;
        }
        // Find element smaller than pivot
        while (j >= low + 1 && arr[j] > pivot) {
            j--;
        }
        if (i < j) {
            swap(arr[i], arr[j]);
        }
    }
    // Place pivot in correct position
    swap(arr[low], arr[j]);
    return j;
}

void qs(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);
        qs(arr, low, pivotIndex - 1);
        qs(arr, pivotIndex + 1, high);
    }
}

int main() {
    vector<int> arr = {1, 5, 7, 9, 3, 2, 5, 3};
    qs(arr, 0, arr.size() - 1);

    for (int x : arr) {
        cout << x << " ";
    }
    return 0;
}