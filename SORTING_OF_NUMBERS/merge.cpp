#include<iostream>
#include<vector>
using namespace std;

class solution{
public:
    void merge(vector<int> &arr,int low,int mid,int high){
        vector<int>temp;
            int left = low;
            int right = mid + 1;
            while(left <= mid  && right <= high ){
                if(arr[left] <= arr[right]){
                    temp.push_back(arr[left]);
                    left++;
                }
                else{
                    temp.push_back(arr[right]);
                    right++;
                }
            }
            while(left <= mid){
                temp.push_back(arr[left]);
                left++;
            }
            while(right <= high){
                temp.push_back(arr[right]);
                right++;
            }
            for(int i = 0;i < temp.size();i++){
                arr[i] = temp[i - low];
            }
        }
    void ntg1(vector<int> &arr,int low ,int high){
        if(low  == high){
            return;
        }
        int mid = (low + high)/2;
        ntg1(arr,low,mid);
        ntg1(arr,mid+1,high);
        merge(arr,low,mid,high);
    }

    void ntg2(vector<int> &arr,int n){
        ntg1(arr,0,n-1);
    }
};

int main(){
    int n;
    cout << "Enter the number of elements: ";   
    cin >> n;
    vector<int> arr(n); 
    cout << "Enter the elements: ";
    for(int i = 0;i < n;i++){
        cin >> arr[i];
    }
    solution s;
    s.ntg2(arr,n);
    cout << "Sorted array: ";
    for(int i = 0;i < n;i++){
        cout << arr[i] << " ";
    }
    return 0;
}