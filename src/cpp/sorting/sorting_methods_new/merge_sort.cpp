#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


void MergeSort(vector<int> &arr, int n){
    
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
    MergeSort(v,n);
    for (auto it : v) cout << it << " ";
    return 0;
}