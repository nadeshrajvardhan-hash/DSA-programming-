#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int largestnum(int arr[],int n){
    int largest = arr[0];
    for (int i = 0 ; i < n ; i++){
        if (arr[i] > largest){
            largest = arr[i];
        }
    }
    cout <<"The largest number is : " << largest <<endl;
}





int secondlargest(int arr[],int n){
    if (n < 2){
        cout << "Need at least two values to find the second largest" << endl;
        return INT_MIN;
    }

    int largest = arr[0];
    int slargest = INT_MIN;
    for(int i = 1 ; i < n ; i++){
        if (arr[i] > largest){
            slargest = largest;
            largest = arr[i];
        }
        else if (arr[i] > slargest && arr[i] != largest){
            slargest = arr[i];
        }
    }
    if(slargest == INT_MIN){
        cout << "No second largest value found" << endl;
    } else {
        cout << "The second largest number is : " << slargest << endl;
    }
    return slargest;
}




int ssmallestnum(int arr[],int n){
    if (n < 2){
        cout << "Need at least two values to find the second smallest" << endl;
        return INT_MAX;
    }

    int smallest = arr[0];
    int ssmallest = INT_MAX;
    for (int i = 1 ; i < n ; i++){
        if (arr[i] < smallest){
            ssmallest = smallest;
            smallest = arr[i];
        }
        else if (arr[i] < ssmallest && arr[i] != smallest){
            ssmallest = arr[i];
        }
    }
    if (ssmallest == INT_MAX){
        cout << "No second smallest value found" << endl;
    } else {
        cout << "The second smallest number is : " << ssmallest << endl;
    }
    return ssmallest;
}




int arrsorted(int arr[], int n){
    for (int i =0 ; i < n ; i++){
        if (arr[i] > arr[i+1]){
            cout << "The array is not sorted" << endl;
            return false;
        }
    }
    return true;
}





int removeduplicates(int arr[],int n){
    int i = 0 ;
    for (int j = 1 ; j < n ; j++){
        if (arr[i] != arr[j]){
            i++;
            arr[i] = arr[j];
        }
    }
    return i+1;
}





int main(){
    int n ;
    cout << "Enter the number of values you entered : ";
    cin >> n;
    int arr[n];
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }
    largestnum(arr, n);
    secondlargest(arr, n);
    ssmallestnum(arr, n);
}