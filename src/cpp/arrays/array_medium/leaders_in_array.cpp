#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> bruteforce(vector<int> &arr, int n) {
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        bool leader = true;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[i]) {
                leader = false;
                break;
            }
        }
        if (leader)
            ans.emplace_back(arr[i]);
    }
    return ans;
}


vector <int> optimal(vector <int> &arr, int n){
    vector <int> ans;
    int maxi = INT_MIN;
    for (int i = n-1; i >= 0; i--) {
        if (arr[i] > maxi){
            ans.emplace_back(arr[i]);
            maxi = max(maxi,arr[i]);
        }
    }
    sort(ans.begin(),ans.end());
    return ans;
}

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
    vector <int> ans = bruteforce(v,n);
    for (auto it : ans) cout << it << " "; 
    cout << endl;
    vector <int> ans1 = optimal(v,n);
    for (auto it1 : ans1) cout << it1 << " "; 
    return 0;
}