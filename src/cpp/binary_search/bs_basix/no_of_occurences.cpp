#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// array is given sorted
vector <int> bruteforce(vector <int> &arr, int n, int x){
    vector <int> ans;
    int first = -1;
    int last = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] == x){
            if (first == -1) first = i;
            last = i;
        }
    }
    ans.emplace_back(first);
    ans.emplace_back(last);
    return ans;
}
// TC = O(N)

vector<int> lbub(vector<int> &arr, int n, int x) {
    auto it1 = lower_bound(arr.begin(), arr.end(), x);
    int lb1 = it1 - arr.begin();
    if (lb1 == n || arr[lb1] != x) {
        return {-1, -1};
    }
    auto it2 = upper_bound(arr.begin(), arr.end(), x) - 1;
    int ub1 = it2 - arr.begin();
    return {lb1, ub1};
}
// TC = O(2 * log N base 2)

int binarysearchfirst(vector <int> &arr, int n, int x){
    int first = -1;
    int low = 0;
    int high = n-1;
    while (low <= high){
        int mid = (low+high)/2;
        if (arr[mid] == x) {
            first = mid;
            high = mid-1;
        }
        else if (arr[mid] < x) low = mid + 1;
        else high = mid - 1;
    }
    return first;
}

vector <int> binarysearchlast(vector <int> &arr, int n, int x){
    int first = binarysearchfirst(arr, n, x);
    if (first == -1) return {-1,-1}; // important line
    int last = -1;
    int low = 0;
    int high = n-1;
    while (low<=high){
        int mid = (low + high)/2;
        if (arr[mid] == x) {
            last = mid;
            low = mid + 1;
        }
        else if (arr[mid] < x) low = mid + 1;
        else high = mid - 1;
    }
    return {first,last};
}

int occurences(vector <int> &arr, int n, int x){
    vector <int> ab = binarysearchlast(arr,n,x);
    return ab[1] - ab[0] + 1;
}

int main()
{
    int n,x;
    cin >> n >> x;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.emplace_back(x);
    }
    vector <int> ans1 = bruteforce(v,n,x);
    for (auto it : ans1) cout << it << " ";
    cout << "\n";
    vector <int> ans2 = lbub(v,n,x);
    for (auto it2: ans2) cout << it2 << " ";
    cout << "\n";
    vector <int> ans3 = binarysearchlast(v,n,x);
    for (auto it3: ans3) cout << it3 << " ";
    cout << "\n" << occurences(v,n,x);
    return 0;
}