#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <climits>
using namespace std;

// can be done using linear search also

int bruteforce(vector<int> &arr, int n)
{
    int longest = 1;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++)
    {
        int cnt = 1;
        int x = arr[i];
        while (binary_search(arr.begin(), arr.end(), x + 1) == true)
        {
            x++;
            cnt++;
        }
        longest = max(longest, cnt);
    }
    return longest;
}

int better(vector<int> &arr, int n)
{
    sort(arr.begin(), arr.end());
    int longest = 1;
    int last_smallest = INT_MIN;
    int cntcurrent = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == last_smallest + 1)
        {
            cntcurrent++;
            last_smallest = arr[i];
        }
        else if (arr[i] == last_smallest)
        {
            continue; // no need to check also
        }
        else
        {
            cntcurrent = 1;
            last_smallest = arr[i];
        }
        longest = max(longest, cntcurrent);
    }
    return longest;
}

// since we are distorting the array, it is not the optimal approach

int optimal(vector<int> &arr, int n)
{
    int longest = 1;
    unordered_set<int> s(arr.begin(), arr.end());
    for (auto it : s)
    {
        if (s.find(it - 1) == s.end())
        {
            int cnt = 1;
            int x = it;
            while (s.find(x + 1) != s.end())
            {
                x++;
                cnt++;
            }
            longest = max(longest, cnt);
        }
    }
    return longest;
}
// o(1)- avg + best case
// o(3n) - worst case due to collision
// sc = o(n)

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
    cout << bruteforce(v, n);
    cout << endl;
    cout << better(v, n);
    cout << endl;
    cout << optimal(v, n);

    return 0;
}