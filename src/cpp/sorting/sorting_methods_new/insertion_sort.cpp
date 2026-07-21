#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void InsertionSort(vector<int> &arr, int n) {
    for (int i = 0; i < n; i++) {
        
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
    InsertionSort(v,n);
    for (auto it : v) cout << it << " ";
    return 0;
}