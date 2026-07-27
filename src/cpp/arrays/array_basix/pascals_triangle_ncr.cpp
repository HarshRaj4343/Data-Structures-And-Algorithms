#include <iostream>
#include <vector>
using namespace std;

// given row and column, find the element at that place

long long var1optimal(int n, int r){
    long long result = 1;
    for (int i = 0; i < r; i++) {
        result = result * (n-i);
        result = result / (i+1);
    }
    return result;
}

// Printing any nth row of pascal's triangle

vector <int> var2brute(int n){
    vector <int> ans;
    for (int i = 1; i <= n; i++) {
        ans.emplace_back(var1optimal(n-1, i-1));
    }
    return ans;
}

// tc = O(n*r)

vector <int> var2optimal(int n){
    vector <int> ansarr;
    int ans = 1;
    ansarr.emplace_back(ans);
    for (int i = 1; i < n; i++) {
        ans = ans * (n-i);
        ans /= i;
        ansarr.emplace_back(ans);
    }
    return ansarr;
}

// tc = O(n)

// Variant - 3 :  Given n, print the entire pascal triangle

// the brute force approach is to call the function var1optimal for every row from 1 to n

vector <vector <int>> var3optimal(int n){
    vector <vector <int>> ans;
    for (int i = 1; i <= n; i++) {
        ans.push_back(var2optimal(i));
    }
    return ans;
}

int main()
{
    int n,r;
    cin >> n >> r;
    cout << var1optimal(n-1,r-1) << endl;
    vector <int> ans = var2brute(n);
    for (auto it : ans) cout << it << " ";
    cout << "\n";
    vector <int> ans1 = var2optimal(n);
    for (auto it : ans1) cout << it << " ";
    cout << "\n";
    vector <vector <int>> ans2 = var3optimal(n);
    for (auto it : ans2) {
        for (auto it1 : it) {
            cout << it1 << " ";
        }
        cout << "\n";
    }
    return 0;
}