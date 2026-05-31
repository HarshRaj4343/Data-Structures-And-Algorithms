// Selection Sort

// #include <iostream>
// using namespace std;
// int main() {
//     cout<<"Selection Sort Pseudo Code"<<endl;
//     int n;
//     cin>>n;
//     int arr[n];
//     for (int i=1;i<=n;i++){
//         cin>>arr[i];
//     }
//     for (int i=0;i<=n-2;i++){
//         int minidx=i;
//         for (int j=0;j<i;j++){
//             if (arr[j]<arr[minidx]) {
//                 minidx=j;
//         }
//         swap(arr[j],arr[minidx]);
//     }
//     for (int i=0;i<n;i++){
//         cout<<arr[i]<<" ";
//     }
//     return 0;
// }


// Bubble Sort

// #include <iostream>
// using namespace std;
// int main() {
//     cout<<"Bubble Sort Pseudo Code"<<endl;
//     int n;
//     cin>>n;
//     int arr[n];
//     for (int i=0;i<n;i++){
//         cin>>arr[i];
//     }
//     for (int i=0;i<n;i++){
//         int didSwap=0;
//         for (int j=0;j<n-i-1;j++){
//             if (arr[j]>arr[j+1]){
//                 swap(arr[j], arr[j+1]);
//             }
//             didSwap=1;
//         }
//         if (didSwap==0){
//             break;
//         }
//     }
//     for (int i=0;i<n;i++){
//         cout<<arr[i]<<" ";
//     }
//     return 0;
// }


// Insertion Sort

// #include <iostream>
// using namespace std;
// int main() {
//     cout << "Insertion Sort Pseudo Code" << endl;
//     int n;
//     cin >> n;
//     int arr[n];
//     for (int i = 0; i < n; i++) {
//         cin >> arr[i];
//     }
//     for (int i=1;i<n;i++){
//         int curr=arr[i];
//         int prev=i-1;
//         while (prev>=0 && arr[prev]>curr){
//             arr[prev+1]=arr[prev];
//             prev--;
//         }
//         arr[prev+1]=curr;
//     }
//     for (int i=0;i<n;i++){
//         cout<<arr[i]<<" ";
//     }
//     return 0;
// }



// Merge Sort

// #include <iostream>
// #include <vector>
// using namespace std;
// void milao(int arr[],int low,int mid,int high){
//     vector <int> temp;
//     int left=low;
//     int right=mid+1;
//     while (left<=mid && right<=high){
//         if (arr[left]<=arr[right]){
//             temp.emplace_back(arr[left]);
//             left++;
//         }
//         else {
//             temp.emplace_back(arr[right]);
//             right++;
//         }
//     }
//     while (left<=mid){
//         temp.emplace_back(arr[left]);
//         left++;
//     }
//     while (right<=high) {
//         temp.emplace_back(arr[right]);
//         right++;
//     }
//     for (int i=low;i<=high;i++){
//         arr[i]=temp[i-low];
//     }
// }
// // positional arguments with default values must be at the end
// void mergesort(int arr[], int high, int low = 0){
//     if (low >= high) return;

//     int mid = (low + high) / 2;

//     mergesort(arr, mid, low);
//     mergesort(arr, high, mid + 1);
//     milao(arr, low, mid, high);
// }

// int main() {
//     int n;
//     cin>>n;
//     int arr[n];
//     for (int i=0;i<n;i++){
//         cin>>arr[i];
//     }
//     mergesort(arr,n-1);
//      for (int i = 0; i < n; i++) {
//         cout << arr[i] << " ";
//     }

//     return 0;
// }


// // Quick Sort

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
//     int arr[n];
//     for (int i=0;i<n;i++){
//         cin>>arr[i];
//     }
//     quicksort(arr, n - 1);

//     for (int i=0;i<n;i++){
//         cout<<arr[i]<<" ";
//     }
//     return 0;
// }


// Recursive Bubble AND Insertion Sort Is Left for now.