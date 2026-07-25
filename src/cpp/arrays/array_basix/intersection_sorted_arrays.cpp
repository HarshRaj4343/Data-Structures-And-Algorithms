// brute Force

#include <iostream>
#include <vector>
using namespace std;

vector <int> findIntersection(vector <int> &a,vector <int> &b, int n, int m){
    vector <int> ans;
    vector<int> vis(m, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i] == b[j] && vis[j] == 0){
                ans.emplace_back(a[i]);
                vis[j] = 1;
                break;
            }
            if (b[j] > a[i]) break;
        }
    }
    return ans;
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
    vector <int> ans = findIntersection(v,b,n,m);
    for (auto it : ans) cout << it << " ";
    return 0;
}

// TC = (n1*n2)
// SC = O(n2)

// Optimal Solution -> 2 pointer obv

#include <iostream>
#include <vector>
using namespace std;

vector<int> findInt(vector<int> &a, vector<int> &b, int n, int m)
{
    int i = 0;
    int j = 0;
    vector<int> ans;
    while (i < n && j < m)
    {
        if (a[i] < b[j])
            i++;
        else if (a[i] > b[j])
            j++;
        else
        {
            ans.emplace_back(a[i]);
            i++;
            j++;
        }
    }
    return ans;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> v;
    vector<int> b;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.emplace_back(x);
    }
    for (int i = 0; i < m; i++)
    {
        int y;
        cin >> y;
        b.emplace_back(y);
    }
    vector<int> ans = findInt(v, b, n, m);
    for (auto it : ans)
        cout << it << " ";
    return 0;
}

// tc = O(n1+n2)
// sc = o(1)