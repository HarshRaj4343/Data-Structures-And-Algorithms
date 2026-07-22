// Finding the largest element in an array

// Brute Force (first sort)

#include <vector>
#include <iostream>
using namespace std;

void Merge(vector <int> &arr, int low,int mid, int high){
    vector <int> temp;
    int left = low;
    int right = mid+1;
    while (left<=mid && right<=high){
        if (arr[left] <= arr[right]){
            temp.emplace_back(arr[left]);
            left++;
        }
        else {
            temp.emplace_back(arr[right]);
            right++;
        }
    }
    while (left<=mid){
        temp.emplace_back(arr[left]);
        left++;
    }
    while (right<=high){
        temp.emplace_back(arr[right]);
        right++;
    }
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i-low];
    }
}

void MergeSort(vector <int> &arr, int low, int high){
    if (low>=high) return;
    int mid = (low+high)/2;
    MergeSort(arr, low, mid);
    MergeSort(arr, mid+1, high);
    Merge(arr, low, mid, high);
}

int main() {
    int n;
    cin >> n;
    vector <int> v;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.emplace_back(x);
    }
    MergeSort(v,0,n-1);
    cout << v[n-1];
    return 0;
}

// O(NlogN)

// Optimised version -> O(N)

#include <iostream>
#include <vector>
using namespace std;

int findlargest(vector<int> &arr, int n)
{
    int largest = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > largest)
            largest = arr[i];
    }
    return largest;
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
    cout << findlargest(v, n);
    return 0;
}