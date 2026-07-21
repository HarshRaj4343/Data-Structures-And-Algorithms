#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// Push the max element to the last by adjacent swaps

void BubbleSort(vector<int> &arr, int n) {
    for (int i = n - 1; i > 0; i--) {
        bool swapped = false;
        for (int j = 0; j < i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break; // already sorted, no need to continue
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
    BubbleSort(v,n);
    for (auto it : v) cout << it << " ";
    return 0;
}