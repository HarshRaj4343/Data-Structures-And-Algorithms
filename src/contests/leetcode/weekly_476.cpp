// #include <iostream>
// #include <algorithm>
// using namespace std;
// int fxn(int arr[],int high, int low){
//     int pivot=arr[low];
//     int i = low;
//     int j = high;
//     while (i<j){
//         while (arr[i]<=pivot && i<high){
//             i++;
//         }
//         while (arr[j]>pivot && j>=low+1){
//             j--;
//         }
//         if (i<j) swap(arr[i],arr[j]);
//     }
//     swap(arr[low],arr[j]);
//     return j;

// }
// void quicksort(int arr[],int high,int low=0){
//     if (low<high){ 
//         int partitionidx=fxn(arr,high,low);
//         quicksort(arr,partitionidx-1,low);
//         quicksort(arr,high,partitionidx+1);
//     }
// }
// int main() {
//     int n;
//     cin>>n;
//     int nums[n];
//     for (int i=0;i<n;i++){
//         cin>>nums[i];
//     }
//     quicksort(nums, n - 1);
//     int expression = nums[n-1]+nums[n-2]-nums[0];
//     cout<<expression;
//     return 0;
// }



// #include <iostream>
// using namespace std;
// int main() {
//     string s;
//     cin>>s;
//     int counta = 0 ;
//     int countb = 0 ;
//     for (int i = 0 ; i < s.length() ; i++ ){
//         if (s[i]=='a') counta++;
//         else  countb++;
//     }
//     if (counta==countb) cout<<0;
//     else {
//         cout<<abs(counta-countb);
//     }
//     return 0;
// }


#include <iostream>
using namespace std;
bool hasZero(int n) {
    n = abs(n);
    if(n == 0) return true;  // special case for single digit 0

    while(n) {
        if(n % 10 == 0) return true;  // found zero → return immediately
        n /= 10;
    }
    return false;
}
int main() {
    int n;
    cin>>n; 
    int count = 0;
    for(int i = 1; i <= n; i++) {
        if(!hasZero(i)) count++;
    }
    cout << count;
    return 0;
}