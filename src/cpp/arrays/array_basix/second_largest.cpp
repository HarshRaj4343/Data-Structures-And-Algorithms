// Finding the 2nd largest element in a given array

// Brute Force

// //One thing to note is that if we have to find second largest element, we cannot sort the array and pick the second last element as it may lead to wrong answer in case of duplicate largest elements.Hence, we have to traverse the array only once to find both largest and second largest elements.

#include <iostream>
#include <vector>
using namespace std;
void milao(int arr[],int mid,int high,int low=0){
    vector <int> temp;
    int left=low;
    int right=mid+1;
    while (left<=mid && right<=high){
        if (arr[left]<=arr[right]){
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
    for (int i=low;i<=high;i++){
        arr[i]=temp[i-low];
    }
}
void mergesort(int arr[],int high,int low=0){
    int mid=(low+high)/2;
    if (low>=high) return;
    mergesort(arr,mid,low);
    mergesort(arr,high,mid+1);
    milao(arr,mid,high,low);
}
int main() {
    int n;
    cin>>n;
    int arr[n];
    for (int i=0;i<n;i++){
        cin>>arr[i];
    }
    mergesort(arr,n-1,0);
    int largest = arr[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] != largest) {
            cout << arr[i];
            return 0;
        }
    }
    return 0;
}
// This will take O(N log N+N) time complexity due to sorting


// Better Approach

// #include <iostream>
// #include <vector>
// using namespace std;

// int second_largest(vector<int> &arr, int n)
// {
//     int largest = arr[0];
//     for (int i = 1; i < n; i++)
//     {
//         if (arr[i] > largest)
//             largest = arr[i];
//     }
//     int second_lar = -1;
//     for (int i = 0; i < n; i++)
//     {
//         if (arr[i] > second_lar && arr[i] != largest)
//         {
//             second_lar = arr[i];
//         }
//     }
//     return second_lar;
// }

// int main()
// {
//     int n;
//     cin >> n;
    // vector<int> v;
    // for (int i = 0; i < n; i++)
    // {
    //     int x;
    //     cin >> x;
    //     v.emplace_back(x);
    // }
    // cout << second_largest(v, n);
//     return 0;
// }




// Best Approach

// #include <iostream>
// #include <vector>
// using namespace std;

// int second_largest(vector <int> &arr, int n){
//     int largest = arr[0];
//     int slargest = -1;
//     for (int i = 0; i < n; i++) {
//         if (largest > )
//     }
// }


// int main() {
//     int n;
//     cin >> n;
//     vector<int> v;
//     for (int i = 0; i < n; i++)
//     {
//         int x;
//         cin >> x;
//         v.emplace_back(x);
//     }
//     cout << second_largest(v, n);
//     return 0;
// }