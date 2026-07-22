#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int f(vector<int> &arr, int low, int high){
    int pivot = arr[low];
    int i = low;
    int j = high;
    while (i < j){
        while (arr[i] <= pivot && i <= high-1) i++;
        while (arr[j] > pivot && j >= low+1) j--;
        if (i < j) swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);
    return j;
}

void QuickSort(vector<int> &arr, int low, int high){
    if (low < high){
        int partition_idx = f(arr, low, high);
        QuickSort(arr, low, partition_idx - 1);
        QuickSort(arr, partition_idx + 1, high);
    }
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
    QuickSort(v,0,n-1);
    for (auto it : v) cout << it << " ";
    return 0;
}