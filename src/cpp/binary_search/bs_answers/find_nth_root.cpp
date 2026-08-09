#include <iostream>
using namespace std;
// standard - linear search

int f(int n, int k) {
    int ans = 1;
    for (int i = 1; i <= k; i++) {
        ans = ans * n;
    }
    return ans;
}
// computing power using binary exponentiation - another use
int power(int n, int k) {
    int ans = 1;

    while (k > 0) {
        if (k % 2 == 1) {
            ans *= n;
        }

        n *= n;
        k /= 2;
    }

    return ans;
}

int bruteforce(int n, int k){
    for (int i = 0; i < n; i++) {
        if (f(i,k) == n) return i;
        else if (f(i,k) > n) break;
    }
    return -1;
}
// tc = o(n*m) or o(n*log2 m)


int p(int mid, int n, int k){
    long long ans = 1;
    for (int i = 1; i <= k; i++) {
        ans = ans * mid;
        if (ans > n) return 2; // mid^k > n
    }
    if (ans == n) return 0; // mid^k == n
    else return 1; // mid^k < n
}

int bs(int n, int k){
    int low = 1;
    int high = n;
    while (low <= high){
        int mid = low + (high - low)/2;
        if (p(mid,n,k) == 0) return mid;
        else if (p(mid,n,k) == 1) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

// TC = O(logm * logn)

int main() {
    int n,k;
    cin >> n >> k;
    cout << bs(n,k);
    return 0;
}