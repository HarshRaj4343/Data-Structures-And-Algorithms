#include <iostream>
#include <vector>
using namespace std;
// input is already given (sorted)

int binarysearchiterative(vector <int> &arr, int n, int target){
    int low = 0;
    int high = n-1;
    while (low <= high){
        int mid = (low+high)/2;
        if (arr[mid] == target) return 1;
        else if (arr[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int binarysearchrecursive(vector <int> &arr, int low, int high, int target){
    if (low > high) return -1;
    int mid = (low+high)/2;
    if (arr[mid] == target) return 1;
    else if (arr[mid] < target) return binarysearchrecursive(arr, mid+1,high,target);
    else return binarysearchrecursive(arr,low, mid-1, target);
}

int main()
{
    int n,target;
    cin >> n >> target;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.emplace_back(x);
    }
    cout << binarysearchiterative(v , n , target) << endl;
    cout << binarysearchrecursive(v , 0, n-1, target) << endl;
    return 0;
}

// Time Complexity Analysis:-
// 32 - 16 - 8 - 4 - 2 - 1 :- log N base 2

// Another analyis for overflow:-

// if high == INT_MAX, then computing mid by the formula above causes overflow, hence, use this particular formula instead:-
// mid = low + (high - low)/2