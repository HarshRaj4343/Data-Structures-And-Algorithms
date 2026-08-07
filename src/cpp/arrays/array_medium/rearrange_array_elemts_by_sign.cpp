#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector <int> bruteforcev1(vector <int> &arr, int n){
    vector <int> pos;
    vector <int> neg;
    for (int i = 0; i < n; i++) {
        if (arr[i] >= 0) pos.emplace_back(arr[i]);
        else neg.emplace_back(arr[i]);
    }
    // pos elements at even indices
    // neg elements at odd indices
    for (int i = 0; i < n/2; i++) {
        arr[2*i] = pos[i];
        arr[2*i+1] = neg[i];
    }
    return arr;
}
// Tc = O(3n/2)
// sc = O(n)
vector <int> optimalv1(vector <int> &arr, int n){
    vector <int> ans(n,0);
    int posindex = 0;
    int negindex = 1;
    for (int i = 0; i < n; i++) {
        if (arr[i] < 0){
            ans[negindex] = arr[i];
            negindex += 2;
        }
        else {
            ans[posindex] = arr[i];
            posindex += 2;
        }
    }
    return ans;
}
// tc = o(n)
// sc = o(n)

vector <int> bruteforcev2optimal(vector <int> &arr, int n){
    vector <int> pos;
    vector <int> neg;
    for (int i = 0; i < n; i++) {
        if (arr[i] >= 0) pos.emplace_back(arr[i]);
        else neg.emplace_back(arr[i]);
    }
    int p = pos.size();
    int m = neg.size();
    int mini = min(p,m);
    // pos elements at even indices
    // neg elements at odd indices
    for (int i = 0; i < mini; i++) {
        arr[2*i] = pos[i];
        arr[2*i+1] = neg[i];
    }
    int idx = 2 * mini;
    if (p > m) {
        for (int i = mini; i < p; i++) {
            arr[idx] = pos[i];
            idx++;
        }
    }
    else {
        for (int i = mini; i < m; i++) {
            arr[idx] = neg[i];
            idx++;
        }
    }

    return arr;
}

// tc = o(n) + o(min(pos,neg)) + o(abs(pos-neg)) = o(n) -> classify into best case, average case, worst case
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
    vector <int> ans = bruteforcev1(v,n);
    for (auto it : ans) cout << it << " ";
    cout << endl;
    vector <int> ans1 = optimalv1(v,n);
    for (auto it2 : ans1) cout << it2 << " ";
    cout << endl;
    vector <int> ans3 = bruteforcev2optimal(v,n);
    for (auto it3 : ans3) cout << it3 << " ";
    cout << endl;
    return 0;
}