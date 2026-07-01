#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int largestnum(int arr[], int n) {
    int largest = arr[0];
    for (int i = 0; i < n; i++) {
        if (arr[i] > largest) {
            largest = arr[i];
        }
    }
    cout << "The largest number is : " << largest << endl;
    return largest;
}

int secondlargest(int arr[], int n) {
    if (n < 2) {
        cout << "Need at least two values to find the second largest" << endl;
        return INT_MIN;
    }

    int largest = arr[0];
    int slargest = INT_MIN;
    for (int i = 1; i < n; i++) {
        if (arr[i] > largest) {
            slargest = largest;
            largest = arr[i];
        } else if (arr[i] > slargest && arr[i] != largest) {
            slargest = arr[i];
        }
    }

    if (slargest == INT_MIN) {
        cout << "No second largest value found" << endl;
    } else {
        cout << "The second largest number is : " << slargest << endl;
    }
    return slargest;
}

int ssmallestnum(int arr[], int n) {
    if (n < 2) {
        cout << "Need at least two values to find the second smallest" << endl;
        return INT_MAX;
    }

    int smallest = arr[0];
    int ssmallest = INT_MAX;
    for (int i = 1; i < n; i++) {
        if (arr[i] < smallest) {
            ssmallest = smallest;
            smallest = arr[i];
        } else if (arr[i] < ssmallest && arr[i] != smallest) {
            ssmallest = arr[i];
        }
    }

    if (ssmallest == INT_MAX) {
        cout << "No second smallest value found" << endl;
    } else {
        cout << "The second smallest number is : " << ssmallest << endl;
    }
    return ssmallest;
}

bool arrsorted(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            cout << "The array is not sorted" << endl;
            return false;
        }
    }
    cout << "The array is sorted" << endl;
    return true;
}

int removeduplicates(int arr[], int n) {
    int i = 0;
    for (int j = 1; j < n; j++) {
        if (arr[i] != arr[j]) {
            i++;
            arr[i] = arr[j];
        }
    }
    return i + 1;
}

void leftrotation(int arr[], int n, int d) {
    if (n <= 1 || d <= 0) return;

    d %= n;
    vector<int> temp(d);
    for (int i = 0; i < d; i++) {
        temp[i] = arr[i];
    }

    for (int i = d; i < n; i++) {
        arr[i - d] = arr[i];
    }

    for (int i = 0; i < d; i++) {
        arr[n - d + i] = temp[i];
    }
}

void reverse(int arr[], int start, int end) {
    while (start < end) {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

void optimalleftrotation(int arr[], int n, int d) {
    if (n <= 1 || d <= 0) return;

    d %= n;
    reverse(arr, 0, d - 1);
    reverse(arr, d, n - 1);
    reverse(arr, 0, n - 1);
}

void movezeros(int arr[], int n) {
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] != 0) {
            swap(arr[j], arr[i]);
            j++;
        }
    }
}

int main() {
    int n;
    cout << "Enter the number of values you entered : ";
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    largestnum(arr.data(), n);
    secondlargest(arr.data(), n);
    ssmallestnum(arr.data(), n);
    arrsorted(arr.data(), n);
    leftrotation(arr.data(), n, 2);

    cout << "After left rotation: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}