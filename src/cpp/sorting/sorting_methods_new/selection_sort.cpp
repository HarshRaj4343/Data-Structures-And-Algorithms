#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// Find the minimum and then swap and make the minimum element to the extreme left

void SelectionSort(vector<int> &arr, int n){
    for (int i = 0; i < n-1; i++) {
        int mini = i;
        for (int j = i+1; j < n; j++) {
            if (arr[mini] > arr[j]){
                mini = j;
            }
        }
        swap(arr[mini],arr[i]);
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
    SelectionSort(v,n);
    for (auto it : v) cout << it << " ";
    return 0;
}