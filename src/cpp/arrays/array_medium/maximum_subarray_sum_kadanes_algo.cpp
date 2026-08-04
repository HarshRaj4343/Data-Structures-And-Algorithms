#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

// Brute Force is just using another loop to add.

int BetterApproach(vector<int> &arr, int n)
{
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            maxi = max(sum, maxi);
        }
    }
    return maxi;
}

// TC = O(N2)
// SC = O(1)

int KadaneAlgo(vector<int> &arr, int n)
{
    int maxi = INT_MIN;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum > maxi)
            maxi = sum;
        if (sum < 0)
            sum = 0;
    }
    // if asked for empty subarray ( sum >= 0)
    if (maxi < 0)
        return 0;
    return maxi;
}

/*
 * Kadane's Algorithm (Maximum Subarray Sum)
 * -------------------------------------------
 * Finds the maximum sum of a contiguous subarray in O(n) time
 * by making a single pass and deciding, at each element, whether
 * to extend the previous subarray or start a fresh one from here.
 *
 * currentSum -> best sum of a subarray ending exactly at current index
 * bestSum    -> best sum seen so far across all subarrays
 *
 * Logic:
 * - at each element, currentSum = max(arr[i], currentSum + arr[i])
 *   (if adding arr[i] makes the running sum worse than arr[i] alone,
 *    it's better to start a new subarray from here)
 * - bestSum = max(bestSum, currentSum)  (track the overall best)
 *
 * Why it works:
 * A negative running sum can only drag down future sums, so once
 * currentSum drops below the value of the current element itself,
 * it's discarded and a new subarray starts.
 *
 * Time Complexity: O(n) — single pass
 * Space Complexity: O(1) — no extra array needed
 */

// getting that particular array

vector<int> KadaneAlgoArray(vector<int> &arr, int n)
{
    int maxi = INT_MIN;
    int start = 0;
    int ansStart = -1;
    int ansEnd = -1;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (sum == 0) start = i;
        sum += arr[i];
        if (sum > maxi) {
            maxi = sum;
            ansStart = start;
            ansEnd = i;
        }
        if (sum < 0)
            sum = 0;
    }
    return vector <int> (arr.begin() + ansStart, arr.begin() + ansEnd + 1);
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
    cout << BetterApproach(v, n) << endl;
    cout << KadaneAlgo(v, n) << endl;
    vector <int> ans = KadaneAlgoArray(v,n);
    for (auto it: ans) cout << it << " ";
    return 0;
}