#include <iostream>
#include <vector>
using namespace std;

// just need to tell if it exists or not, not the index

bool bruteforce(vector<int> &arr, int n, int target)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == target)
            return true;
    }
    return false;
}
// edge case where previous method doesn't work :- [3,1,2,3,3,3] -> target = 3 -> mid = 2 -> arr[mid] = 2 -> arr[low] = 3 -> arr[high] = 3 -> both halves are sorted using just this given comparison
bool binarysearchmethod(vector<int> &arr, int n, int target)
{
    int low = 0;
    int high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == target)
            return mid;
        // additional checks
        if (arr[low] == arr[mid] && arr[mid] == arr[high]){
            low++;
            high--;
            continue; // for again case
        }
        // left sorted
        if (arr[low] <= arr[mid])
        {
            if ((arr[low] <= target) && (target <= arr[mid]))
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
            if ((arr[mid] <= target) && (target <= arr[high]))
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }
    return -1;
}

// tc = O(log2 N) (worst case = ~(o(n/2)))


int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.emplace_back(x);
    }
    cout << bruteforce(v, n, k) << endl;
    cout << binarysearchmethod(v,n,k) << endl;
    
    return 0;
}