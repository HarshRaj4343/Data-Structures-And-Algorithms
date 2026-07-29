#include <iostream>
#include <vector>
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

vector <int> binarysearch(vector <int> &arr, int n, int x){
    vector <int> ans;
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
    return 0;
}