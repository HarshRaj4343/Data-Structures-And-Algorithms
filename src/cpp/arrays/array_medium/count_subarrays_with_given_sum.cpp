#include <iostream>
#include <vector>
using namespace std;

// extreme brute force is to execute the summation task using another loop

int better(vector<int> &arr, int n, int k)
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            if (sum == k)
                cnt++;
        }
    }
    return cnt;
}

// int optimal(vector <int> &arr, int n, int k){
//     int cnt = 0;
//     map <int,int> hashmap;

// }


int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.emplace_back(x);
    }
    cout << better(v, n, k);
    return 0;
}