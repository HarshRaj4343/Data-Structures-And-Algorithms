// Brute Force -> Just Use Merge Sort or Quick Sort

// Better + Optimal Solution

#include <iostream>
#include <vector>
using namespace std;

vector <int> better(vector <int> &arr, int n){
    int cnt0 = 0, cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == 0) cnt0 ++;
        else if (arr[i] == 1) cnt1 ++;
        else cnt2 ++;
    }
    for (int i = 0; i < cnt0; i++) {
        arr[i] = 0;
    }
    for (int i = cnt0; i < cnt0 + cnt1; i++) {
        arr[i] = 1;
    }
    for (int i = cnt0 + cnt1; i < n; i++) {
        arr[i] = 2;
    }
    return arr;
}

/*
 * Dutch National Flag Algorithm
 * -------------------------------
 * Sorts an array containing only 3 distinct values (e.g., 0, 1, 2)
 * in a single pass using 3 pointers, without extra space.
 *
 * low   -> boundary for elements equal to 0 (everything before low is 0)
 * mid   -> current element being examined
 * high  -> boundary for elements equal to 2 (everything after high is 2)
 *
 * Logic:
 * - if arr[mid] == 0: swap(arr[low], arr[mid]), low++, mid++
 * - if arr[mid] == 1: mid++
 * - if arr[mid] == 2: swap(arr[mid], arr[high]), high--  (don't increment mid,
 *                     since the swapped-in element from high needs checking)
 *
 * Loop runs while mid <= high.
 *
 * Time Complexity: O(n) — single pass - each condition - 1 element sorted (so total become O(N) iteration)
 * Space Complexity: O(1) — in-place
 */

vector <int> dutchnationalflagalgo(vector <int> &arr, int n){
    int mid = 0;
    int high = n-1;
    int low = 0;
    // arr[mid] can either be 0,1 or 2
    while (mid <= high){
        if (arr[mid] == 0){
            swap(arr[low],arr[mid]);
            mid++;
            low++;
        }
        else if (arr[mid] == 1){
            mid++;
        }
        else {
            swap(arr[mid],arr[high]);
            high--;
        }
    }
    return arr;
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
    vector <int> ans1 = better(v,n);
    for (auto it1 : ans1) cout << it1 << " ";
    cout << "\n";
    vector <int> ans2 = dutchnationalflagalgo(v,n);
    for (auto it2 : ans2) cout << it2 << " ";
    return 0;
}