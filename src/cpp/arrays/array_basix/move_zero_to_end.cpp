// Brute Force

#include <iostream>
#include <vector>
using namespace std;

void ZeroMover(vector <int> &arr, int n){
    vector <int> temp;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i]!=0) temp.push_back(arr[i]);
        else cnt++;
    }
    for (int i = 0; i < n-cnt; i++) {
        arr[i] = temp[i];
    }
    for (int i = n-cnt; i < n; i++) {
        arr[i] = 0;
    }
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
    ZeroMover(v,n);
    for (auto it : v) cout << it << " ";
    return 0;
}

// TC = O(n) + O(n-cnt) + O(cnt) = O(2n)
// SC = O(n-cnt)


// Optimal Version - Using 2 pointer

#include <iostream>
#include <vector>
using namespace std;

void MoveZeroAtEnd(vector <int> &arr, int n){
    int j = -1;
    for (int k = 0; k < n; k++) {
        if (arr[k] == 0) {
            j = k;
            break;
        }
    }
    for (int k = j+1; k < n; k++) {
        if (arr[k] != 0){
            swap(arr[k],arr[j]);
            j++;
        }
    }
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
    MoveZeroAtEnd(v,n);
    for (auto it : v) cout << it << " ";
    return 0;
}

// tc - O(n)

