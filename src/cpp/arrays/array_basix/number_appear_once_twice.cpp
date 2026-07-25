// Brute Force

#include <iostream>
#include <vector>
using namespace std;

int findimposter(vector <int> &arr, int n){
    for (int i = 0; i < n; i++) {
        int num = arr[i];
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if (arr[j] == num) cnt++;
        }
        if (cnt == 1) return num;
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.emplace_back(x);
    }
    cout << findimposter(v,n);
    return 0;
}

// TC = O(n2)
// SC = O(1)

// Better Solution Using Hashing


#include <iostream>
#include <vector>
using namespace std;

int findlargest(vector<int> &arr, int n)
{
    int largest = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > largest)
            largest = arr[i];
    }
    return largest;
}

int findimposter(vector <int> &arr, int n){
    int lar = findlargest(arr,n);
    vector<int> hash(lar+1, 0);
    // push
    for (int i = 0; i < n; i++) {
        hash[arr[i]] = hash[arr[i]] + 1;
    }
    // fetch
    for (int i = 0; i < hash.size(); i++) {
        if (hash[i] == 1) return arr[i];
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.emplace_back(x);
    }
    cout << findimposter(v,n);
    return 0;
}

// TC = O(3n)
// Downside : We need to use map data structure if the numbers were greater than 1e7

// ================= APPROACH 1: Hash Array / Vector =================
// 1. Find max element in arr[] -> tells us how big the hash array must be
// 2. Create hash array of size (max+1), initialized to 0
// 3. Pass 1: hash[arr[i]]++  -> count occurrence of every value
// 4. Pass 2: check hash[arr[i]] == 1 -> that value is the answer

// Time  : O(3n) ~ O(n)          (max-find + marking + checking = 3 passes)
// Space : O(max element)        NOT O(n) — depends on the largest value, not array size

// Limitation:
// - fails on negative numbers   (can't use as array index)
// - fails on huge numbers       (10^8, 10^12...) -> array too big to allocate


// ================= APPROACH 2: Hash Map =================
// 1. Pass 1: mp[arr[i]]++       -> map auto-inits missing key to 0, so this just works
// 2. Pass 2: loop map entries, return key whose value == 1

// Works on negatives/huge numbers too, since map hashes by KEY not by INDEX

// map<int,int>          -> ordered (tree)   -> O(log m) per op -> O(n log m) total, guaranteed
// unordered_map<int,int>-> hash table       -> O(1) avg per op -> O(n) avg, O(n^2) worst (rare)
// m = distinct keys stored ≈ n/2 + 1   (most numbers appear twice, so map is ~half the array size)

// Space : O(m) ≈ O(n/2 + 1)     only unique keys are stored, not all n elements

// Ordered map (map): TC = O(n log m + n/2) -> reliable, guaranteed worst case
// Unordered map:      TC = O(n) avg, O(n^2) worst case (rare, due to collisions)
// Interview default: use unordered_map for speed;
// switch to map only if worst-case guarantee is required




// Optimal Solution

#include <iostream>
#include <vector>
using namespace std;

int findimposter(vector <int> &arr, int n){
    int XOR = 0;
    for (int i = 0; i < n; i++) {
        XOR = XOR^arr[i];
    }
    return XOR;
}

int main()
{
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.emplace_back(x);
    }
    cout << findimposter(v,n);
    return 0;
}

// tc = O(n)