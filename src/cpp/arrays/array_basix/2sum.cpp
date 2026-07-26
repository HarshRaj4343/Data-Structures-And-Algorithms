// brute force

#include <iostream>
#include <vector>
using namespace std;
bool twosumvariant1(vector<int> &arr, int n, int target)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                continue;
            else if (arr[i] + arr[j] == target)
            {
                return true;
            }
        }
    }
}

vector<int> twosumvariant2(vector<int> &arr, int n, int target)
{
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                continue;
            else if (arr[i] + arr[j] == target)
            {
                ans.emplace_back(i);
                ans.emplace_back(j);
            }
        }
    }
    return ans;
}

vector<int> twosumvari2optimised(vector<int> &arr, int n, int target)
{
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] + arr[j] == target)
            {
                ans.emplace_back(i);
                ans.emplace_back(j);
            }
        }
    }
    return ans;
}

int main()
{
    int n, target;
    cin >> n >> target;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.emplace_back(x);
    }
    cout << twosumvariant1(v, n, target) << "\n";
    vector<int> ans = twosumvariant2(v, n, target);
    for (auto it : ans)
        cout << it << " ";
    vector<int> ans1 = twosumvari2optimised(v, n, target);
    cout << "\n";
    for (auto it2 : ans)
        cout << it2 << " ";
    return 0;
}