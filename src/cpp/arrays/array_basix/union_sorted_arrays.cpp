// Brute Force

#include <iostream>
#include <vector>
#include <set>
using namespace std;

set <int> UnionFind(vector <int> &arr1, vector <int> &arr2, int n, int m){
    set <int> s;
    for (int i = 0; i < n; i++) {
        s.insert(arr1[i]);
    }
    for (int i = 0; i < m; i++) {
        s.insert(arr2[i]);
    }
    return s;
}

int main()
{
    int n,m;
    cin >> n >> m;
    vector<int> v;
    vector<int> b;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.emplace_back(x);
    }
    for (int i = 0; i < m; i++) {
        int y;
        cin >> y;
        b.emplace_back(y);
    }
    set <int> sr = UnionFind(v,b,n,m);
    for (auto it: sr) cout << it << " ";
    return 0;
} // do not use unordered set

// O(nlogn) + O(mlogm) + O(n+m) -> TC
// O(n+m) + O(n+m) -> last one for returning -> SC

// Optimal Method - REVISE

#include <iostream>
#include <vector>
using namespace std;

vector <int> Unifind(vector <int> &arr1, vector <int> &arr2, int n, int m){
    vector <int> uniarr;
    int i = 0;
    int j = 0;
    while (i < n && j < m){
        if (arr1[i] <= arr2[j]) {
            if (uniarr.size() == 0 || uniarr.back() != arr1[i]){
                uniarr.emplace_back(arr1[i]);
            }
            i++;
        }
        else{
            if (uniarr.size() == 0 || uniarr.back() != arr2[j]){
                uniarr.emplace_back(arr2[j]);
            }
            j++;
        }
    }
    while (i<n){
        if (uniarr.size() == 0 || uniarr.back() != arr1[i]){
                uniarr.emplace_back(arr1[i]);
            }
        i++;
    }
    while (j<m){
        if (uniarr.size() == 0 || uniarr.back() != arr2[j]){
                uniarr.emplace_back(arr2[j]);
            }
        j++;
    }
    return uniarr;
}

int main()
{
    int n,m;
    cin >> n >> m;
    vector<int> v;
    vector<int> b;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.emplace_back(x);
    }
    for (int i = 0; i < m; i++) {
        int y;
        cin >> y;
        b.emplace_back(y);
    }
    vector <int> ans  = Unifind(v,b,n,m);
    for (auto it : ans) cout << it << " ";
    return 0;
}

// TC = O(n+m)
// SC = O(n+m) - Just for returning the answer