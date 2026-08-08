// floor - largest number in array <=x
// ceil - smallest number in array >=x

#include <iostream>
#include <vector>
using namespace std;


int ceil(vector<int> &arr, int n, int x)
{
    int low = 0;
    int high = n - 1;
    int ans = n;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] >= x)
        {
            ans = arr[mid];
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return ans;
}

int floor(vector <int> &arr, int n, int x){
    int low = 0;
    int high = n-1;
    int ans = -1;
    while (low<=high){
        int mid = (low+high)/2;
        if (arr[mid] <= x){
            ans = arr[mid];
            low = mid+1;
        }
        else high = mid-1;
    }
    return ans;
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
    cout << ceil(v,n,x) << endl;
    cout << floor(v,n,x) << endl;
    return 0;
}