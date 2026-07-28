// upper bound :- smallest index such that arr[idx] > x given a sorted array

#include <iostream>
#include <vector>
using namespace std;

int bruteforce(vector<int> &arr, int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > x)
            return i;
    }
    return n;
}

int betterbs(vector<int> &arr, int n, int x)
{
    int low = 0;
    int high = n - 1;
    int ans = n;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] > x)
        {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return ans;
}
// tc = O(log n base 2)

int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.emplace_back(x);
    }
    cout << bruteforce(v, n, x) << endl;
    cout << betterbs(v, n, x) << endl;
    return 0;
}


// in cpp, there is a dedicated fxn written inside it also by the name 'upper_bound' -> lb = upper_bound(arr.begin(),arr.end(),x) -> returns an iterator -> subtract with arr.begin() to get the final index