#include <iostream>
#include <numeric>
#include <vector>
#include <algorithm>
using namespace std;
// you can do brute force urself.
int summer(vector<int> &weights, int mid)
{
    int n = weights.size();
    int days = 1;
    int load = 0;
    for (int i = 0; i < n; i++) {
        if (load + weights[i] > mid) {
            days++;
            load = weights[i];
        }
        else load+=weights[i];
    }
    return days;
}

int shipWithinDays(vector<int> &weights, int days)
{
    int n = weights.size();
    int low = *max_element(weights.begin(), weights.end());
    int high = accumulate(weights.begin(), weights.end(), 0);
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int temp = summer(weights, mid);
        if (temp <= days)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return low;
}

int main()
{
    int n,days;
    cin >> n >> days;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.emplace_back(x);
    }
    cout << shipWithinDays(v,days);
    return 0;
}