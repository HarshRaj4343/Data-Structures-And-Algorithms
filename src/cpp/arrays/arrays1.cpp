// //declare array globally such that it cannot store garbage values like if declared locally in int main
// // maximum size of array is 10^7 globally and 10^6 locally (i.e in int main)

// // One thing to note is that even if we know the most optimised solution, we should always try to think of a brute force solution first and then try to optimise it step by step in front of interviewer.
// // Q1

// // Brute Force Method (First using Merge Sort)

// #include <iostream>
// #include <vector>
// using namespace std;
// void milao(int arr[],int mid,int high,int low=0){
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
//     while (right<=high){
//         temp.emplace_back(arr[right]);
//         right++;
//     }
//     for (int i=low;i<=high;i++){
//         arr[i]=temp[i-low];
//     }
// }
// void mergesort(int arr[],int high,int low=0){
//     int mid=(low+high)/2;
//     if (low>=high) return;
//     mergesort(arr,mid,low);
//     mergesort(arr,high,mid+1);
//     milao(arr,mid,high,low);
// }
// int main() {
//     int n;
//     cin>>n;
//     int arr[n];
//     for (int i=0;i<n;i++){
//         cin>>arr[i];
//     }
//     mergesort(arr,n-1,0);
//     // Finally, printing the largest element 
//     cout<<arr[n-1];
//     return 0;
// }

// // Brute Force Method (Now using Quick Sort)

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
//     cout<<arr[n-1];
//     return 0;
// }


// // Optimised One

// #include <iostream>
// using namespace std;
// int main() {
//     int n;
//     cin>>n;
//     int arr[n];
//     for (int i = 0; i < n; i++)
//     {
//         cin>>arr[i];
//     }
//     int largest=arr[0];
//     for (int i=0;i<n;i++){
//         if (arr[i]>largest) largest=arr[i];
//     }
//     cout<<largest;
    
//     return 0;
// }


// // Q2
// //One thing to note is that if we have to find second largest element, we cannot sort the array and pick the second last element as it may lead to wrong answer in case of duplicate largest elements.Hence, we have to traverse the array only once to find both largest and second largest elements.
// // Find second largest element in an array

// // with sorting 

// #include <iostream>
// #include <vector>
// using namespace std;
// void milao(int arr[],int mid,int high,int low=0){
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
//     while (right<=high){
//         temp.emplace_back(arr[right]);
//         right++;
//     }
//     for (int i=low;i<=high;i++){
//         arr[i]=temp[i-low];
//     }
// }
// void mergesort(int arr[],int high,int low=0){
//     int mid=(low+high)/2;
//     if (low>=high) return;
//     mergesort(arr,mid,low);
//     mergesort(arr,high,mid+1);
//     milao(arr,mid,high,low);
// }
// int main() {
//     int n;
//     cin>>n;
//     int arr[n];
//     for (int i=0;i<n;i++){
//         cin>>arr[i];
//     }
//     mergesort(arr,n-1,0);
//     int largest = arr[n - 1];
//     for (int i = n - 2; i >= 0; i--) {
//         if (arr[i] != largest) {
//             cout << arr[i];
//             return 0;
//         }
//     }
//     return 0;
// }
// // This will take O(N log N+N) time complexity due to sorting

// // Without sorting (optimised approach)


// #include <iostream>
// using namespace std;
// int main() {
//     int n;
//     cin>>n;
//     int arr[n];
//     for (int i = 0; i < n; i++){
//         cin>>arr[i];            
//     }  
//     int largest=arr[0];
//     int largest2=-1;
//     for (int i=0;i<n;i++){
//         if (arr[i]>largest) largest=arr[i];
//     }
//     cout<<largest<<endl;
//     for (int i=0;i<n;i++){
//         if (arr[i]>largest2 && arr[i]!=largest){
//             largest2=arr[i];
//         }
//     }
//     cout<<largest2;
//     return 0;
// }




// //O(2N) ~ O(N) time complexity and O(1) space complexity

// //In case the array contains negative numbers also, we can initialise second_largest with INT_MIN from <climits> header file.


// // // Optimised approach 2 (Best approach)
// #include <iostream>
// #include <climits>
// using namespace std;

// int main() {
//     int n;
//     cin >> n;

//     if (n < 2) {
//         cout << "No second largest";
//         return 0;
//     }

//     int arr[n];
//     for (int i = 0; i < n; i++) {
//         cin >> arr[i];
//     }

//     int largest = arr[0];
//     int second_largest = INT_MIN;

//     for (int i = 1; i < n; i++) {
//         if (arr[i] > largest) {
//             second_largest = largest;
//             largest = arr[i];
//         }
//         // “If this number is not the biggest,but is bigger than everything else except the biggest,then it deserves to be second biggest.”
//         else if (arr[i] < largest && arr[i] > second_largest) {
//             second_largest = arr[i];
//         }
//     }

//     if (second_largest == INT_MIN) {
//         cout << "No second largest";
//     }
//     else {
//         cout << second_largest;
//     }

//     return 0;
// }
// // This approach only requires a single traversal of the array, making it more efficient.
// // O(N) time complexity and O(1) space complexity


// // Q3
// // //Check if array is sorted or not
// #include <iostream>
// using namespace std;
// int main() {
//     int n;
//     cin>>n;
//     int arr[n];
//     for (int i = 0; i < n; i++){
//         cin>>arr[i];            
//     }  
//     for (int i=1;i<n;i++){
//         if (arr[i]>=arr[i-1]){
            
//         }
//         else {
//             return false;
//         }
//     }
//     return true;
// }

// //  Here the error is coming since int main does not return a bool Value!
// #include <iostream>
// using namespace std;
// int main() {
//     int n = 6;
//     int arr[6] = {1, 1, 2, 2, 3, 10};
//     bool sorted=true;
//     for (int i=0;i<n-1;i++){
//         if (arr[i]>arr[i+1]){
//             sorted=false;
//             break;
//         }
//     }
//     if (sorted){
//         cout<<"Array is sorted";
//     }
//     else{
//         cout<<"Array is not sorted";
//     }
//     return 0;
// }

// // Time Complexity: O(N), where N = size of the array.

// Q4
// Removing duplicates from a sorted array

// Brute force approach : Set data structure can be used to store only unique elements from the array and then we can print the set elements.

// #include <iostream>
// #include <set>
// using namespace std;
// int main() {
//     set<int> s;
//     int n = 8;
//     for (int i = 0; i < n; i++) {
//         int x;
//         cin >> x;
//         s.insert(x); // insert elements into set takes O(log N) time
//     }
//     for (auto it : s) {
//         cout << it << " ";
//     }
//     cout << endl;
//     return 0;
// }

// // TC=O(NlogN+N) SC=O(N)


// // // 2 pointer approach (optimised approach)
// #include <iostream>
// using namespace std;
// int main() {
//     int n = 8;
//     int arr[8] = {1, 1, 2, 2, 3, 4, 5, 5};
//     int i=0; 
//     for (int j=1;j<n;j++){
//         if (arr[j]!=arr[i]){
//             arr[i+1]=arr[j];
//             i++;
//         }
//     }
//     for (int k=0;k<=i;k++){
//         cout<<arr[k]<<" ";
//     }
//     return 0;
// }

// // O(N) time complexity and O(1) space complexity
