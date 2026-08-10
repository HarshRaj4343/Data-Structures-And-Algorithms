#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int bruteforce(vector<int> &arr, int n, int threshold)
{
    int maxi = *max_element(arr.begin(), arr.end());

    for (int i = 1; i <= maxi; i++)
    {
        int sum = 0;

        for (int d = 0; d < n; d++)
        {
            sum += (arr[d] + i - 1) / i;
        }

        if (sum <= threshold)
            return i;
    }

    return -1;
}

// TC: O(maxi * n)

int compute(vector <int> &arr, int n, int div){
    int total = 0;
    for (int i = 0; i < n; i++) {
        total += (arr[i] + div - 1) / div;
    }
    return total;
}

int binarysearch(vector<int> &arr, int n, int threshold){
    int low = 1;
    int high = *max_element(arr.begin(),arr.end());
    while (low <= high){
        int mid = low + (high-low)/2;
        int temp = compute(arr,n,mid);
        if (temp <= threshold) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return low;
}
// O(log(max)*N)

int main()
{
    int n, th;
    cin >> n >> th;

    vector<int> v;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.emplace_back(x);
    }

    cout << bruteforce(v, n, th) << endl;
    cout << binarysearch(v, n, th);

    return 0;
}