// Most Optimal Version -> Just for 1 place

#include <iostream>
#include <vector>
using namespace std;

void LeftRotate(vector <int> &arr, int n){
    int temp = arr[0];
    for (int i = 1; i < n; i++) {
        arr[i-1] = arr[i];
    }
    arr[n-1] = temp;
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
    LeftRotate(v,n);
    for (auto it : v ) cout << it << " ";
    return 0;
}

// O(N) tc