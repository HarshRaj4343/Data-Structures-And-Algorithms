#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int f(vector<int> &arr, int n, int g) {
    int ans = 0;
    // perform ceiling division
    for (int i = 0; i < n; i++) {
        ans += (arr[i] + g - 1) / g;
    }

    return ans;
}

int bruteforce(vector<int> &arr, int n, int h) {
    int maxi = *max_element(arr.begin(), arr.end());

    for (int i = 1; i <= maxi; i++) {
        int reqtime = f(arr, n, i);

        if (reqtime <= h)
            return i;
    }

    return -1;
}


int binarysearch(vector<int> &arr, int n, int h){
    int low = 1;
    int maxi = *max_element(arr.begin(), arr.end());
    int high = maxi;

    while (low <= high) {
        int mid = (low + high) / 2;
        int reqtime = f(arr, n, mid);

        if (reqtime <= h)
            high = mid - 1;
        else
            low = mid + 1;
    }

    return low;
}

int main() {
    int n, h;
    cin >> n >> h;

    vector<int> v;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.emplace_back(x);
    }

    cout << bruteforce(v, n, h);
    cout << binarysearch(v,n,h);

    return 0;
}