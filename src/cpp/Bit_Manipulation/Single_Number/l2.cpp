#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//  brute force - use the map data structure and find the odd one out

int f(vector<int> &v, int n)
{
    int ans = 0;
    for (int BitIndex = 0; BitIndex < 32; BitIndex++)
    {
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if ((v[i] & (1 << BitIndex)) != 0)
                cnt++;
        }
        if (cnt % 3 != 0)
            ans = ans | (1 << BitIndex);
    }
    return ans;
}

// O(32N) -> always be this
// Sc = O(1) -> no extra space used

// Optimised

int better(vector<int> &v, int n)
{
    sort(v.begin(), v.end());
    for (int i = 1; i < n; i += 3)
    {
        if (v[i] != v[i - 1])
            return v[i - 1];
    }
    return v[n-1];
}

// but here, we are distorting the given input

int optimalNewMethod(vector<int> &v, int n){
    // understand it more deeply
    int ones = 0;
    int twos = 0;
    for (int i = 0; i < n; i++) {
        ones = (ones^v[i]) & ~twos;
        twos = (twos^v[i]) & ~ones;
    }
    return ones;
} 
// tc = o(n)
// sc = o(1)

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
    cout << f(v, n) << " " << better(v, n) << " " << optimalNewMethod(v,n);
    return 0;
}