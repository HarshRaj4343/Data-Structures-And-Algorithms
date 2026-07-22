#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void Merge(vector<int> &arr,int low,int mid, int high){
    vector <int> temp;
    int left_pointer = low;
    int right_pointer = mid+1;
    while(left_pointer<=mid&&right_pointer<=high){
        if (arr[left_pointer]<=arr[right_pointer]){
            temp.emplace_back(arr[left_pointer]);
            left_pointer++;
        }
        else{
            temp.emplace_back(arr[right_pointer]);
            right_pointer++;
        }
    }
    while (left_pointer<=mid){
        temp.emplace_back(arr[left_pointer]);
        left_pointer++;
    }
    while (right_pointer<=high){
        temp.emplace_back(arr[right_pointer]);
        right_pointer++;
    }
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i-low];
    }
}

void MergeSort(vector<int> &arr, int low, int high){
    if (low>=high) return;
    int mid = (low+high)/2;
    MergeSort(arr,low,mid);
    MergeSort(arr,mid+1,high);
    Merge(arr,low,mid,high);
}


int main() {
    int n;
    cin >> n;
    vector <int> v;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.emplace_back(x);
    }
    MergeSort(v,0,n-1);
    for (auto it : v) cout << it << " ";
    return 0;
}