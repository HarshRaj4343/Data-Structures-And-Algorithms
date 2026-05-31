// 2 sum problem - find all pairs of indices such that the sum of elements at those indices equals a given target value

// Brute Force Approach

// #include <iostream>
// using namespace std;
// int main() {
//     int n , target;
//     cin >> n >> target;
//     int arr[n];
//     for(int i = 0; i < n; i++) {
//         cin >> arr[i];
//     }
//     for(int i = 0; i < n; i++) {
//         for (int j = 0; j<n; j++){
//             if (i==j) continue;
//             if (arr[i] + arr[j] == target){
//                 cout << i << " " << j << endl;
//         }
//         }
//     }
//     return 0;
// }

// Little bit optimized Approach of Brute Force

// #include <iostream>
// using namespace std;
// int main() {
//     int n , target;
//     cin >> n >> target;
//     int arr[n];
//     for(int i = 0; i < n; i++) {
//         cin >> arr[i];
//     }
//     for(int i = 0; i < n; i++) {
//         for (int j = i+1; j<n; j++){
//             if (arr[i] + arr[j] == target){
//                 cout << i << " " << j << endl;
//         }
//         }
//     }
//     return 0;
// }

// Better Approach using Hashing

// #include <iostream>
// #include <map>
// using namespace std;
// int main() {
//     int n,target;
//     cin>>n>>target;
//     int arr[n];
//     for (int i=0;i<n;i++){
//         cin>>arr[i];
//     }
//     map <int,int> hash;
//     int flag=0;
//     for (int i=0;i<n;i++){
//         if (hash.find(target-arr[i]) != hash.end()){
//             cout << hash[target - arr[i]] << " " << i << endl;
//             flag=1;
//             break;
//         }
//         else {
//             hash[arr[i]]=i;
//         }
//     }
//     if (flag==0){
//         cout<<"No pair found!!";
//     }
//     return 0;
// }

// This is the most optimized approach for finding a pair with given sum in an array. Although , Not much difference in time complexity but still better than previous approaches.

// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;
// int main() {
//     int n,target;
//     cin>>n>>target;
//     vector <int> arr(n);
//     for (int i=0;i<n;i++){
//         cin>>arr[i];
//     }
//     sort(arr.begin(),arr.end());
//     int left=0;
//     int right=n-1;
//     int flag=0;
//     while (left<right){
//         int sum = arr[left]+arr[right];
//         if (sum==target){
//             cout<<"Yes";
//             flag=1;
//             break;
//         }
//         else if (sum<target){
//             left++;
//         }
//         else {
//             right--;
//         }
//     }
//     if (flag==0) cout<<"No";
//     return 0;
// }

// Sort an array of 0s , 1s and 2s

// Brute Force Approach (use merge sort or quick sort)

// #include <iostream>
// #include <vector>
// using namespace std;

// void merge(vector<int> &arr, int low, int mid, int high) {
//     vector<int> temp;
//     int left = low;
//     int right = mid + 1;
//     // merge two sorted halves
//     while (left <= mid && right <= high) {
//         if (arr[left] <= arr[right]) {
//             temp.push_back(arr[left]);
//             left++;
//         } else {
//             temp.push_back(arr[right]);
//             right++;
//         }
//     }

//     // remaining elements
//     while (left <= mid) {
//         temp.push_back(arr[left]);
//         left++;
//     }

//     while (right <= high) {
//         temp.push_back(arr[right]);
//         right++;
//     }

//     // copy back to original array
//     for (int i = low; i <= high; i++) {
//         arr[i] = temp[i - low];
//     }
// }

// void mergeSort(vector<int> &arr, int low, int high) {
//     if (low >= high) return;

//     int mid = low + (high - low) / 2;

//     mergeSort(arr, low, mid);
//     mergeSort(arr, mid + 1, high);
//     merge(arr, low, mid, high);
// }

// int main() {
//     int n;
//     cin >> n;

//     vector<int> arr(n);
//     for (int i = 0; i < n; i++) {
//         cin >> arr[i];
//     }

//     mergeSort(arr, 0, n - 1);

//     for (int x : arr) {
//         cout << x << " ";
//     }

//     return 0;
// }

// TC: O(nlogn) and SC: O(n)

// Better Approach (Counting Sort)

// #include <iostream>
// using namespace std;
// int main() {
//     int n;
//     cin >> n;
//     int arr[n];
//     for (int i = 0; i < n; i++) {
//         cin >> arr[i];
//     }
//     int count0 = 0, count1 = 0, count2 = 0;
//     for (int i = 0; i < n; i++) {
//         if (arr[i] == 0) count0++;
//         else if (arr[i] == 1) count1++;
//         else count2++;
//     }
//     int index = 0;
//     for (int i = 0; i < count0; i++) {
//         arr[index++] = 0;
//     }
//     for (int i = 0; i < count1; i++) {
//         arr[index++] = 1;
//     }
//     for (int i = 0; i < count2; i++) {
//         arr[index++] = 2;
//     }
//     for (int i = 0; i < n; i++) {
//         cout << arr[i] << " ";
//     }
//     return 0;
// }

// TC: O(n) and SC: O(1)

// Dutch National Flag Algorithm (Optimal Approach)

// #include <iostream>
// using namespace std;
// int main() {
//     int n;
//     cin >> n;
//     int arr[n];
//     for (int i = 0; i < n; i++) {
//         cin >> arr[i];
//     }
//     int low = 0, mid = 0, high = n - 1;
//     while (mid <= high) {
//         if (arr[mid] == 0) {
//             swap(arr[low], arr[mid]);
//             low++;
//             mid++;
//         } else if (arr[mid] == 1) {
//             mid++;
//         } else {
//             swap(arr[mid], arr[high]);
//             high--;
//         }
//     }
//     for (int i = 0; i < n; i++) {
//         cout << arr[i] << " ";
//     }
//     return 0;
// }

// TC: O(n) and SC: O(1)

// Majority Element Problem - Find the element that appears more than n/2 times in an array

// Brute force Approach

// #include <iostream>
// using namespace std;
// int main() {
//     int n;
//     cin >> n;
//     int arr[n];
//     for (int i = 0; i < n; i++) {
//         cin >> arr[i];
//     }
//     int count=0;
//     for (int i=0;i<n;i++){
//         count=0;
//         for (int j=0;j<n;j++){
//             if (arr[i]==arr[j]){
//                 count++;
//             }
//         }
//         if (count > n/2){
//             cout << arr[i];
//             break;
//         }
//     }
//     return 0;
// }

// TC: O(n^2) and SC: O(1)

// Better Approach using Hashing

// #include <iostream>
// #include <map>
// using namespace std;
// int main()
// {
//     int n;
//     cin >> n;
//     int arr[n];
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//     }
//     map<int, int> hashmap;
//     for (int i = 0; i < n; i++)
//     {
//         hashmap[arr[i]]++;
//     }

//     for (auto pair : hashmap)
//     {
//         if (pair.second > n / 2)
//         {
//             cout << pair.first;
//             break;
//         }
//     }

//     return -1;
// }


// Optimal Approach - Moore's Voting Algorithm

// #include <iostream>
// using namespace std;
// int main() {
//     int n;
//     cin >> n;
//     int arr[n];
//     for (int i = 0; i < n; i++) {
//         cin >> arr[i];
//     }
//     int cnt=0;
//     int ele;
//     for (int i=0;i<n;i++){
//         if (cnt==0){
//             cnt=1;
//             ele=arr[i];
//         }
//         else if (arr[i]==ele){
//             cnt++;
//         }
//         else {
//             cnt--;
//         }
//     }
//     int cnt1=0;
//     for (int i=0;i<n;i++){
//         if (arr[i]==ele) {
//             cnt1++;
//         }
//     }
//     if (cnt1>n/2) cout<<ele;
//     return 0;
// }



// Maximum Subarray Sum Problem - Find the contiguous subarray with the largest sum

// Brute Force Approach

// #include <iostream>
// using namespace std;
// int main() {
//     int n;
//     cin >> n;
//     int arr[n];
//     for (int i = 0; i < n; i++) {
//         cin >> arr[i];
//     }
//     int maxi = INT_MIN;
//     for (int i=0;i<n;i++){
//         for (int j=i;j<n;j++){
//             int sum=0;
//             for (int k=i;k<j;k++){
//                 sum+=arr[k];
//             }
//             maxi=max(sum,maxi);
//         }
//     }
//     cout<<maxi;
//     return 0;
// }


// Better Solution

// #include <iostream>
// using namespace std;
// int main() {
//     int n;
//     cin>>n;
//     int maxi=INT_MIN;
//     int arr[n];
//     for (int i=0;i<n;i++){
//         cin>>arr[i];
//     }
//     for (int i=0;i<n;i++){
//         int sum=0;
//         for (int j=i;j<n;j++){
//             sum+=arr[j];
//             maxi=max(sum,maxi);
//         }
//     }
//     cout<<maxi;
//     return 0;
// }


// Optimal Solution - Kadane's Algorithm

// #include <iostream>
// using namespace std;
// int main() {
//     long long sum = 0;
//     long long maxi = LONG_MIN;
//     int ansStart = -1;
//     int ansEnd = -1;
//     int n;
//     cin >> n;
//     int arr[n];
//     for (int i = 0; i < n; i++) {
//         cin >> arr[i];
//     }
//     for (int i = 0; i < n; i++) {
//         if (sum == 0) {
//             ansStart = i;
//         }
//         sum += arr[i];
//         if (sum > maxi) {
//             maxi = sum;
//             ansEnd = i;
//         }
//         if (sum < 0) {
//             sum = 0;
//         }
//     }
//     if (maxi < 0) {
//         cout<<0;
//     }
//     cout << maxi<<endl;
//     cout<<"["<<ansStart<<","<<ansEnd<<"]";
//     return 0;
// }

// Stocks Buy and Sell to Maximize Profit - Find the maximum profit by buying and selling stocks multiple times

// #include <iostream>
// using namespace std;
// int main() {
//     int n;
//     cin >> n;
//     int arr[n];
//     for (int i = 0; i < n; i++) {
//         cin >> arr[i];
//     }
//     int mini = arr[0];
//     int profit = 0;
//     for (int i = 1; i < n; i++) {
//         int cost = arr[i] - mini;
//         profit = max(profit, cost);
//         mini = min(mini, arr[i]);
//     }
//     cout << profit;
//     return 0;
// }


// Rearrange Array in alternate Positive and Negative Items

// Brute Force Approach

// #include <iostream>
// #include <vector>
// using namespace std;
// int main() {
//     int n;
//     cin >> n;
//     vector<int> arr(n);
//     for (int i = 0; i < n; i++) {
//         cin >> arr[i];
//     }
//     vector <int> pos;
//     vector <int> neg;
//     for (int i=0;i<n;i++){
//         if (arr[i]>0) pos.push_back(arr[i]);
//         else neg.push_back(arr[i]);
//     }
//     for (int i=0;i<n/2;i++){
//         arr[2*i]=pos[i];
//         arr[(2*i)+1]=neg[i];
//     }
//     for (int i=0;i<n;i++){
//         cout<<arr[i]<<" ";
//     }
//     return 0;
// }


// Optimal Solution

// #include <iostream>
// #include <vector>
// using namespace std;
// int main() {
//     int n;
//     cin>>n;
//     vector <int> arr(n);
//     for (int i=0;i<n;i++){
//         cin>>arr[i];
//     }
//     vector <int> temp(n);
//     int posIndex=0;
//     int negIndex=1;
//     for (int i=0;i<n;i++){
//         if (arr[i]<0){
//             temp[negIndex]=arr[i];
//             negIndex+=2;
//         }
//         else {
//             temp[posIndex]=arr[i];
//             posIndex+=2;
//         }
//     }
//     for (int i=0;i<n;i++){
//         cout<<temp[i]<<" ";
//     }
//     return 0;
// }


// 2nd variety of Rearranging Array in alternate Positive and Negative Items

// #include <iostream>
// #include <vector>
// using namespace std;
// int main() {
//     int n;
//     cin>>n;
//     vector <int> arr(n);
//     for (int i=0;i<n;i++){
//         cin>>arr[i];
//     }
//     vector <int> pos;
//     vector <int> neg;
//     for (int i=0;i<n;i++){
//         if (arr[i]>=0) pos.push_back(arr[i]);
//         else neg.push_back(arr[i]);
//     }
//     if (pos.size() > neg.size()) {
//         for (int i=0;i<neg.size();i++){
//             arr[2*i]=pos[i];
//             arr[2*i+1]=neg[i];
//         }
//         int index=neg.size()*2;
//         for (int i=neg.size();i<pos.size();i++){
//             arr[index]=pos[i];
//             index++;
//         }
//     }
//     else {
//         for (int i=0;i<pos.size();i++){
//             arr[2*i]=pos[i];
//             arr[2*i+1]=neg[i];
//         }
//         int index=pos.size()*2;
//         for (int i=pos.size();i<neg.size();i++){
//             arr[index]=neg[i];
//             index++;
//         }
//     }
//     for (int i=0;i<n;i++){
//         cout<<arr[i]<<" ";
//     }
//     return 0;
// }


// Leader Element Problem - Find all elements that are greater than all elements to their right

// Brute Force Approach

// #include <iostream>
// #include <vector>
// using namespace std;
// int main() {
//     int n;
//     cin>>n;
//     vector <int> arr(n);
//     for (int i=0;i<n;i++){
//         cin>>arr[i];
//     }
//     for (int i=0;i<n;i++){
//         bool flag=true;
//         for (int j=i+1;j<n;j++){
//             if (arr[j]>arr[i]){
//                 flag=false;
//                 break;;
//             }
//         }
//         if (flag==true){
//             cout<<arr[i]<<" ";
//         }
//     }
//     return 0;
// }


// Optimal Solution

// #include <iostream>
// #include <vector>
// using namespace std;
// int main() {
//     int n;
//     cin>>n;
//     vector <int> arr(n);
//     for (int i=0;i<n;i++){
//         cin>>arr[i];
//     }
//     int maxi=arr[n-1];
//     cout<<maxi<<" ";
//     for (int i=n-2;i>=0;i--){
//         if (arr[i]>maxi){ 
//             maxi=arr[i];
//             cout<<maxi<<" ";
//         }
//     }
//     return 0;
// }


// Longest Consecutive Sequence - Find the length of the longest consecutive elements sequence in an unsorted array

// Brute Force Approach

// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// bool linearsearch(vector<int> arr, int x) {
//     bool attendance = false;
//     for (int i = 0; i < arr.size(); i++) {
//         if (arr[i] == x) attendance = true;
//     }
//     if (attendance == true) return true;
//     else {
//         return false;
//     }
// }

// int main() {
//     int n;
//     cin >> n;
//     int longest = 1;
//     vector<int> arr(n);
//     for (int i = 0; i < n; i++) {
//         cin >> arr[i];
//     }
//     for (int i=0;i<n;i++){
//         int x=arr[i];
//         int count=1;
//         while (linearsearch(arr,x+1)==true){
//             x++;
//             count++;
//             longest=max(longest,count);
//         }
//     }
//     cout<<longest;
//     return 0;
// }


// Better Approach using Sorting

// #include <iostream>
// #include <vector>
// using namespace std;
// int main() {
//     int n;
//     cin>>n;
//     vector <int> arr(n);
//     for (int i=0;i<n;i++){
//         cin>>arr[i];
//     }
//     sort(arr.begin(),arr.end());
//     int longest=1;
//     int last_smallest=INT_MIN;
//     int count_current=0;
//     for (int i=0;i<n;i++){
//         if (arr[i]-1==last_smallest){
//             count_current++;
//             last_smallest=arr[i];
//         }
//         else if (arr[i]!=last_smallest) {
//             count_current=1;
//             last_smallest=arr[i];
//         }
//         longest=max(longest,count_current);
//     }
//     cout<<longest;
//     return 0;
// }

// Optimal Solution

// #include <iostream>
// #include <vector>
// #include <unordered_set>
// using namespace std;
// bool linearsearch(const vector<int>& arr, int x) {
//     for (int i = 0; i < arr.size(); i++) {
//         if (arr[i] == x) return true; // stop immediately
//     }
//     return false; // not found
// }
// int main() {
//     int n;
//     cin >> n;
//     vector <int> arr(n);
//     for (int i = 0; i < n ; i ++){
//         cin>>arr[i];
//     }
//     unordered_set <int> s;
//     for (int i = 0 ; i < n ; i++){
//         s.insert(arr[i]);
//     }
//     int longest=1;
//     for (auto it : s){
//         if (s.find(it-1)==s.end()){
//             int count_current=1;
//             int x=it;
//             while (s.find(x+1)!=s.end()){
//                 count_current++;
//                 x++;
//             }
//             longest=max(longest,count_current);
//         }
//     }
//     cout<<longest;
//     return 0;
// }



// Printing all the permutations of a given array

// #include <iostream>
// #include <vector>
// using namespace std;
// void permut(vector <int> arr,int index=0){
//     if (index==arr.size()){
//         for (int i=0;i<arr.size();i++){
//             cout<<arr[i]<<" ";
//         }
//         cout<<endl;
//         return;
//     }
//     for (int i=index;i<arr.size();i++){
//         swap(arr[index],arr[i]);
//         permut(arr,index+1);
//         swap(arr[index],arr[i]);
//     }
// }
// int main() {
//     int n;
//     cin>>n;
//     vector <int> arr(n);
//     for (int i=0;i<n;i++){
//         cin>>arr[i];
//     }
//     permut(arr);
//     return 0;
// }


// TC: O(n*n!) and SC: O(n)

// Printing next permutation of a given array

// Brute Force Approach

// #include <iostream>
// using namespace std;
// vector <vector<int>> perms;
// void permut(vector <int> arr,int index=0){
//     if (index==arr.size()){
//         perms.push_back(arr);
//         return;
//     }
//     for (int i=index;i<arr.size();i++){
//         swap(arr[index],arr[i]);
//         permut(arr,index+1);
//         swap(arr[index],arr[i]);
//     }
// }

// int main() {
//     vector<int> nums = {1, 2, 3};
//     vector<int> original = nums;
//     permut(nums);
//     sort(perms.begin(), perms.end());
//     for (int i = 0; i < perms.size(); i++) {
//         if (perms[i] == original) {
//             if (i == perms.size() - 1) {
//                 nums = perms[0];
//             } else {
//                 nums = perms[i + 1];
//             }
//             break;
//         }
//     }
//     for (int i = 0; i < nums.size(); i++) {
//         cout << nums[i] << " ";
//     }
//     return 0;
// }

// Better Approach is by directly using STL function next_permutation

// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;
// int main() {
//     int n;
//     cin>>n;
//     vector <int> arr(n);
//     for (int i=0;i<n;i++){
//         cin>>arr[i];
//     }
//     next_permutation(arr.begin(),arr.end());
//     for (int i=0;i<n;i++){
//         cout<<arr[i]<<" ";
//     }
//     return 0;
// }

// Optimal Approach without using STL

// #include <iostream>
// using namespace std;
// int main() {
//     int n;
//     cin>>n;
//     int arr[n];
//     for (int i=0;i<n;i++){
//         cin>>arr[i];
//     }
//     int index= -1;
//     for (int i=n-2;i>=0;i--){
//         if (arr[i]<arr[i+1]){
//             index=i;
//             break;
//         }
//     }
//     if (index==-1){
//         reverse(arr,arr+n);
//     }
//     else {
//         for (int i=n-1;i>index;i--){
//             if (arr[i]>arr[index]){
//                 swap(arr[i],arr[index]);
//                 break;
//             }
//         }
//         reverse(arr+index+1,arr+n);
//     }
//     for (int i=0;i<n;i++){
//         cout<<arr[i]<<" ";
//     }
//     return 0;
// }


// Number of Subarrays with sum K

// Brute Force Approach

// #include <iostream>
// using namespace std;
// int main() {
//     int n,k;
//     cin>>n>>k;
//     int arr[n]; 
//     for (int i=0;i<n;i++){
//         cin>>arr[i];
//     }
//     int count=0;
//     for (int i=0;i<n;i++){
//         for (int j=i;j<n;j++){
//             int sum=0;
//             for (int l=i;l<=j;l++){
//                 sum+=arr[l];
//             }
//             if (sum==k){
//                 count++;
//             }
//         }
//     }
//     cout<<count;
//     return 0;
// }

// Better Approach

// #include <iostream>
// #include <vector>
// using namespace std;
// int main() {
//     int n,k;
//     cin>>n>>k;
//     vector <int> arr(n);
//     for (int i=0;i<n;i++){
//         cin>>arr[i];
//     }
//     int count=0;
//     for (int i=0;i<n;i++){
//         int sum=0;
//         for (int j=i;j<n;j++){
//             sum+=arr[j];
//             if (sum==k){
//                 count++;
//             }
//         }
//     }
//     cout<<count;
//     return 0;
// }




// OPTIMAL APPROACH

