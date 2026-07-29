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

vector <int> binarysearchplain(vect)

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
    vector <int> ans2 = binarysearch(v,n,x);
    for (auto it2: ans2) cout << it2 << " ";
    return 0;
}