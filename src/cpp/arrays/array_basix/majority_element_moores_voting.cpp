#include <iostream>
#include <map>
#include <vector>
using namespace std;

int BruteForce(vector <int> &arr, int n){
    int target = n/2;
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (arr[i] == arr[j]) count++;
        }
        if (count > n/2) return arr[i];
    }
}

int BetterApproach(vector <int> &arr, int n){
    int target = n/2;
    map <int,int> mpp;
    for (int i = 0; i < n; i++) {
        mpp[arr[i]]++;
    }
    for (auto it: mpp) {
        if (it.second > target) return it.first;
    }
    return -1;
}
// TC = O(nlogn + n)
// SC = O(n)

int Optimal(vector <int> &arr, int n){
    int el = arr[0];
    int cnt = 0;
    int target = n/2;
    for (int i = 1; i < n; i++) {
        if (cnt == 0){
            cnt = 1;
            el = arr[i+1];
        }
        else if (arr[i] == el) cnt++;
        else cnt--;
    }
    // the next loop is only implemented if it is not given that the array must contain the majority element
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == el) count++;
    }
    if (count > target) return el;
    return -1;
}

// TC = O(n + (n))
// SC = O(1)

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
    cout << BruteForce(v,n) << endl;
    cout << BetterApproach(v,n) << endl;
    cout << Optimal(v,n) << endl;
    return 0;
}