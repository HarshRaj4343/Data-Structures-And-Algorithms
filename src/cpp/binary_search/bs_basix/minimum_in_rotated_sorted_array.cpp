#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

// for unique sorted arrays

int bruteforce(vector<int> &arr, int n)
{
    int mini = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < mini)
            mini = arr[i];
    }
    return mini;
}

int binarysearch(vector<int> &arr, int n)
{
    int low = 0;
    int high = n - 1;
    int mini = INT_MAX;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] <= mini)
            mini = arr[mid];
        // left sorted
        if (arr[low] <= arr[mid])
        {
            if ((arr[low] <= mini) && (mini <= arr[high]))
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        // right sorted
        else
        {
            if ((arr[low] <= mini) && (mini <= arr[high]))
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }
    return mini;
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
    cout << bruteforce(v, n);
    cout << endl << binarysearch(v, n);
    return 0;
}