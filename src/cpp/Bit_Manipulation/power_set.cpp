#include <iostream>
#include <vector>
using namespace std;

// this question also has a recursive solution

// 2**n = 1<<n;

vector <vector<int>> powerset(vector <int> &v, int n){
    int totalsubsets = 1<<n;
    vector <vector<int>> ans;
    for (int i = 0; i < totalsubsets; i++) {
        vector <int> list;
        for (int j = 0; j < n; j++) {
            if (i & (1<<j)) list.emplace_back(v[j]);
        }
        ans.emplace_back(list);
    }
    return ans;
}

// O((2**n)*n)
// sc = O((2**n)*n)

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
    vector <vector<int>> ans = powerset(v,n);
    for (auto it : ans){
        for (auto it2 : it){
            cout << it2 << " "; 
        }
        cout << endl;
    }
    return 0;
}