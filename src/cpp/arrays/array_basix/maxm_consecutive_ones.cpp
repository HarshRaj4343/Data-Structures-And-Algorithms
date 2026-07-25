// Optimal Solution

#include <iostream>
#include <vector>
using namespace std;

int findmaxones(vector<int> &arr, int n)
{
    int maxi = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 1)
        {
            cnt++;
            maxi = max(maxi, cnt);
        }
        else
            cnt = 0;
    }
    return maxi;
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
    cout << findmaxones(v, n);
    return 0;
}