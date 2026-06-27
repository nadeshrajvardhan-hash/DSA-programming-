#include<iostream>
using namespace std;

void selectionSort(int arr[],int n){
    for (int i = 0 ; i < n ;i++){
        int mini = i;
        for (int j = i ; j < n; j++){
            if (arr[j] < arr[mini]){
                mini = j;
            }
        }
        swap(arr[mini],arr[i]);
    }
}

void bubbleSort(int arr[],int n){
    for (int i = 0 ; i < n ;i++){
        for (int j = 0 ; j < n-i-1; j++){
            if (arr[j] > arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}

void insertionSort(int arr[],int n){
    for (int i = 1 ; i < n ;i++){
        int key = arr[i];
        int j = i-1;
        while (j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

int main(){
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cout << "Enter element " << i + 1 << ": ";
        cin >> arr[i];
    }
    selectionSort(arr, n);
    bubbleSort(arr, n);
    insertionSort(arr, n);
    cout << "Sorted array: ";
    
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
}