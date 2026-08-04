// Maximising the profit is the main agenda. (Buying & Selling can only be done once.)

// if you are selling on ith day, you buy on the minimum price from 1st to i-1 th day

#include <iostream>
#include <vector>
using namespace std;

int Solution(vector<int> &arr, int n)
{
    int mini = arr[0];
    int profit = 0;
    for (int i = 1; i < n; i++)
    {
        int cost = arr[i] - mini;
        profit = max(cost, profit);
        mini = min(mini, arr[i]);
    }
    return profit;
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
    cout << Solution(v, n);
    return 0;
}