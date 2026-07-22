#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void InsertionSort(vector<int> &arr, int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];      
        int j = i - 1;        

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;      
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