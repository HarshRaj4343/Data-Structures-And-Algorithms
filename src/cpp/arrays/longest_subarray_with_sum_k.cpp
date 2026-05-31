// Brute Force Approach

#include <iostream>
using namespace std;
int len;
int main() {
    int n, K;
    cin >> n >> K;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i=0;i<n;i++){
        for (int j=i;j<n;j++){
            int total=0;
            for (int l=i;l<=j;l++){
                total+=arr[l];
            }
            if (total==K) len=max(len,j-i+1);
        }
    }
    cout<<len;
    return 0;
}


// Little bit Optimized Approach

#include <iostream>
using namespace std;
int main() {
    int n, K, len = 0;
    cin >> n >> K;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++) {
        int total = 0;
        for (int j = i; j < n; j++) {
            total += arr[j];
            if (total == K) len = max(len, j - i + 1);
        }
    }
    cout << len;
    return 0;
}


// Hash Map Approach (better approach)

#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int n;
    long long K;
    long long total=0;
    int maxlen=0;
    cin >> n >> K;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    map<long long, int> prefixSumIndex;
    for (int i=0;i<arr.size();i++){
        total+=arr[i];
        if (total==K){
            maxlen=max(maxlen,i+1);
        }
        long long rem=total-K;
        if (prefixSumIndex.find(rem) != prefixSumIndex.end()){
            int len=i-prefixSumIndex[rem];
            maxlen=max(maxlen,len);
        }
        prefixSumIndex[total]=i;
    }
    cout<<maxlen;
    return 0;
}


// Hash Map Approach (better approach) [for arrays with 0 elements too]

#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int n;
    long long K;
    long long total=0;
    int maxlen=0;
    cin >> n >> K;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    map<long long, int> prefixSumIndex;
    for (int i=0;i<arr.size();i++){
        total+=arr[i];
        if (total==K){
            maxlen=max(maxlen,i+1);
        }
        long long rem=total-K;
        if (prefixSumIndex.find(rem) != prefixSumIndex.end()){
            int len=i-prefixSumIndex[rem];
            maxlen=max(maxlen,len);
        }
        if (prefixSumIndex.find(total) == prefixSumIndex.end())  prefixSumIndex[total]=i;
       
    }
    cout<<maxlen;
    return 0;
}

// This will be the most optimized approach for both positive and negative numbers in the array.

// for only positive numbers in the array we can use 2 pointer approach which will be more optimized than hash map approach.

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    int n;
    long long k;
    cin >> n >> k;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int left = 0, right = 0;
    long long sum = a[0];
    int maxLen = 0;

    while (right < n) {
        // shrink window if sum exceeds k
        while (left <= right && sum > k) {
            sum -= a[left];
            left++;
        }

        // check if current window sum == k
        if (sum == k) {
            maxLen = max(maxLen, right - left + 1);
        }

        // expand window
        right++;
        if (right < n) sum += a[right];
    }

    cout << maxLen;
    return 0;
}

// TC: O(N) And SC: O(1)