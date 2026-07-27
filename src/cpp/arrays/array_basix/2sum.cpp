// brute force

#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
bool twosumvariant1(vector<int> &arr, int n, int target)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                continue;
            else if (arr[i] + arr[j] == target)
            {
                return true;
            }
        }
    }
    return false;
}

vector<int> twosumvariant2(vector<int> &arr, int n, int target)
{
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                continue;
            else if (arr[i] + arr[j] == target)
            {
                ans.emplace_back(i);
                ans.emplace_back(j);
            }
        }
    }
    return ans;
}

vector<int> twosumvari2optimised(vector<int> &arr, int n, int target)
{
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] + arr[j] == target)
            {
                ans.emplace_back(i);
                ans.emplace_back(j);
            }
        }
    }
    return ans;
}

// using hashing

bool twosumbetter(vector<int> &arr, int n, int target)
{
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        int a = arr[i];
        int residual = target - a;
        if (mp.find(residual) != mp.end())
        {
            return true;
        }
        mp[a] = i;
    }
    return false;
}

// TC = O(nlogn)
// SC = O(n)
// similarly, u can also print the indices also

// A slightly better solution using 2 pointer greedy approach

bool twosumoptimal(vector<int> &arr, int n, int target)
{
    sort(arr.begin(), arr.end());
    int left = 0;
    int right = n - 1;
    while (left < right)
    {
        int sum = arr[left] + arr[right];
        if (sum == target)
            return true;
        else if (sum < target)
            left++;
        else
            right--;
    }
    return false;
}

// TC = O(n) + O(nlogn)
// SC = O(1) without distorting the array

// Optimal Version 2 - not preferred for variant 2

// vector <int> twosumopt(vector <int> &arr, int n, int target){
//     vector <int> ans;
//     map <int,int> mpp;
//     int left = 0;
//     int right = n-1;
//     while (left<right){
//         int sum = arr[left] + arr[right];
//         if (sum == target){
//             ans.emplace_back(mpp[a]);
//             ans.emplace_back(mpp[b]);
//         }
//         else if (sum < target)
//             left++;
//         else
//             right--;
//     }
//     return ans;
// }

// retry this method while revision


int main()
{
    int n, target;
    cin >> n >> target;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.emplace_back(x);
    }
    cout << twosumvariant1(v, n, target) << "\n";
    vector<int> ans = twosumvariant2(v, n, target);
    for (auto it : ans)
        cout << it << " ";
    vector<int> ans1 = twosumvari2optimised(v, n, target);
    cout << "\n";
    for (auto it2 : ans1)
        cout << it2 << " ";
    cout << "\n";
    cout << twosumbetter(v, n, target) << "\n";
    cout << twosumoptimal(v, n, target) << "\n";
    return 0;
}