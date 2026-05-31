//  Left rotate the array by 1 place

// #include <iostream>
// using namespace std;
// int main() {
//     int n;
//     cin>>n;
//     int arr[n];
//     for (int i=0;i<n;i++){
//         cin>>arr[i];
//     }
//     int temp=arr[0];
//     for (int i=1;i<n-1;i++){
//         arr[i-1]=arr[i];
//     }
//     arr[n-1]=temp;
//     for (int i=0;i<n;i++){
//         cout<<arr[i]<<" ";
//     }
//     return 0;
// }

// TC=O(n) and SC=O(1+N) since N is either given to you or you need it . Most preferred is O(N).

//  Left rotate the array by D place

// Brute Force 1.1

// #include <iostream>
// #include <vector>
// using namespace std;
// int main() {
//     int n;
//     cin>>n;
//     int arr[n];
//     for (int i=0;i<n;i++){
//         cin>>arr[i];
//     }
//     int d;
//     cin>>d;
//     d=d%n;
//     vector <int> temp;
//     for (int i=0;i<d;i++){
//         temp.emplace_back(arr[i]);
//     }
//     for (int i=temp.size();i<n;i++){
//         arr[i-temp.size()]=arr[i];
//     }

//     // focus on this part - 1st method

//     int j=0;
//     for (int i=n-d;i<n;i++){
//         arr[i]=temp[j];
//         j++;
//     }

//     for(int i=0;i<n;i++){
//         cout<<arr[i]<<" ";
//     }
// }

// Brute Force 1.2

// #include <iostream>
// #include <vector>
// using namespace std;
// int main() {
//     int n;
//     cin>>n;
//     int arr[n];
//     for (int i=0;i<n;i++){
//         cin>>arr[i];
//     }
//     int d;
//     cin>>d;
//     d=d%n;
//     vector <int> temp;
//     for (int i=0;i<d;i++){
//         temp.emplace_back(arr[i]);
//     }
//     for (int i=temp.size();i<n;i++){
//         arr[i-temp.size()]=arr[i];
//     }

//     // focus on this part - 2nd method

//     for (int i = n - d; i < n; i++) {
//     arr[i] = temp[i - (n - d)];
//     }

//     for(int i=0;i<n;i++){
//         cout<<arr[i]<<" ";
//     }
// }

// TC=O(n-d)+O(d)+O(d)=O(n-d) and SC=O(d) since N is either given to you or you need it . Most preferred is O(N).

// Reverse function

// void reverse(int arr[], int start, int end){
//     while(start<end){
//         swap(arr[start], arr[end]);
//         start++;
//         end--;
//     }
// }

// Optimal Approach - Reversal Algorithm

// #include <iostream>
// #include <algorithm>
// using namespace std;
// int main() {
//     int n;
//     cin>>n;
//     int arr[n];
//     for (int i=0;i<n;i++){
//         cin>>arr[i];
//     }
//     int d;
//     cin>>d;
//     d=d%n;
//     // Reverse first d elements
//     reverse(arr, arr + d);
//     // Reverse remaining n-d elements
//     reverse(arr + d, arr + n);
//     // Reverse the whole array
//     reverse(arr, arr + n);
//     for(int i=0;i<n;i++){
//         cout<<arr[i]<<" ";
//     }
//     return 0;
// }

// TC=O(n) and SC=O(1) since N is either given to you or you need it . Most preferred is O(N).

// Think about doing right rotation using reversal algorithm or any other optimal approach.

// Move all the null elements to right side of the array

// Brute force Approach

// #include <iostream>
// using namespace std;
// int main() {
//     int n;
//     cin>>n;
//     int arr[n];
//     for (int i=0;i<n;i++){
//         cin>>arr[i];
//     }
//     vector <int> temp;
//     for (int i=0;i<n;i++){
//         if (arr[i]!=0) temp.emplace_back(arr[i]);
//     }
//     int j=0;
//     for (int i=0;i<temp.size();i++){
//         arr[i]=temp[j];
//         j++;
//     }
//     for (int i=temp.size();i<n;i++){
//         arr[i]=0;
//     }
//     for (int i=0;i<n;i++){
//         cout<<arr[i]<<" ";
//     }
//     return 0;
// }

// TC=O(n) and SC=O(n) since N is either given to you or you need it . Most preferred is O(N).

// Optimal Approach - Two Pointer Approach

// #include <iostream>
// using namespace std;
// int main() {
//     int n;
//     cin>>n;
//     int arr[n];
//     for (int i=0;i<n;i++){
//         cin>>arr[i];
//     }
//     int j=-1;
//     for (int i=0;i<n;i++){
//         if (arr[i]==0){
//             j=i;
//             break;
//         }
//     }
//     for (int i=j+1;i<n;i++){
//         if (arr[i]!=0){
//             swap(arr[i],arr[j]);
//             j++;
//         }
//     }
//     for (int i=0;i<n;i++){
//         cout<<arr[i]<<" ";
//     }
//     return 0;
// }

// // Linear Search
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

//     int key;
//     cin >> key;

//     for (int i = 0; i < n; i++) {
//         if (arr[i] == key) {
//             cout << i;
//             return 0;
//         }
//     }

//     cout << -1;
//     return 0;
// }
// TC=O(n) and SC=O(1) since N is either given to you or you need it . Most preferred is O(N).


// Union of two sorted arrays

// Brute Force

// #include <iostream>
// #include <set>
// #include <vector>
// using namespace std;
// int main() {
//     int n,m;
//     cin>>n>>m;
//     int arr1[n];
//     for (int i=0;i<n;i++){
//         cin>>arr1[i];
//     }
//     int arr2[m];
//     for (int i=0;i<m;i++){
//         cin>>arr2[i];
//     }
//     set <int> s;
//     for (int i=0;i<n;i++){
//         s.insert(arr1[i]);
//     }
//     for (int i=0;i<m;i++){
//         s.insert(arr2[i]);
//     }
//     vector <int> unionArr;
//     for (auto it : s){
//         unionArr.emplace_back(it);
//     }
//     for (int i=0;i<unionArr.size();i++){
//         cout<<unionArr[i]<<" ";
//     }
//     return 0;
// }

// TC=O(NlogN+MlogM)+O(N+M) and SC=O(n+m)+O(n+m)(for returning the answer) since N is either given to you or you need it . Most preferred is O(N).


// Optimal Approach - Two Pointer Approach

// #include <iostream>
// #include <vector>
// using namespace std;
// int main() {
//     int n,m;
//     cin>>n>>m;
//     int arr1[n];
//     for (int i=0;i<n;i++){
//         cin>>arr1[i];
//     }
//     int arr2[m];
//     for (int i=0;i<m;i++){
//         cin>>arr2[i];
//     }
//     vector <int> unionArr;
//     int i=0,j=0;
//     while(i<n && j<m){
//         if (arr1[i]<=arr2[j]){
//             if (unionArr.size()==0 || unionArr.back()!=arr1[i]){
//                 unionArr.emplace_back(arr1[i]);
//             }
//             i++;
//         }
//         else if (arr2[j]<arr1[i]){
//             if (unionArr.size()==0 || unionArr.back()!=arr2[j]){
//                 unionArr.emplace_back(arr2[j]);
//             }
//             j++;
//         }
    
//     }
//     while (i<n){
//         if (unionArr.size()==0 || unionArr.back()!=arr1[i]){
//             unionArr.emplace_back(arr1[i]);
//         }
//         i++;
//     }
//     while (j<m){
//         if (unionArr.size()==0 || unionArr.back()!=arr2[j]){
//             unionArr.emplace_back(arr2[j]);
//         }
//         j++;
//     }
//     for (int i=0;i<unionArr.size();i++){
//         cout<<unionArr[i]<<" ";
//     }
//     return 0;
// }

// TC=O(n+m) and SC=O(n+m)(for returning the answer) since N is either given to you or you need it 


// Intersection of two sorted arrays

// #include <iostream>
// using namespace std;

// int main() {
//     int n, m;
//     cin >> n >> m;

//     int arr1[n], arr2[m];

//     for (int i = 0; i < n; i++) cin >> arr1[i];
//     for (int i = 0; i < m; i++) cin >> arr2[i];

//     int vis[m] = {0};

//     for (int i = 0; i < n; i++) {
//         if (i > 0 && arr1[i] == arr1[i - 1]) continue;  

//         for (int j = 0; j < m; j++) {
//             if (arr1[i] == arr2[j] && vis[j] == 0) {
//                 cout << arr1[i] << " ";
//                 vis[j] = 1;
//                 break;
//             }
//             if (arr2[j] > arr1[i]) break;
//         }
//     }
//     return 0;
// }


// TC=O(n*m) and SC=O(m) 


// Optimal Approach - Two Pointer Approach

// #include <iostream>
// using namespace std;
// int main() {
//     int n,m;
//     cin>>n>>m;
//     int arr1[n];
//     for (int i=0;i<n;i++){
//         cin>>arr1[i];
//     }
//     int arr2[m];
//     for (int i=0;i<m;i++){
//         cin>>arr2[i];
//     }
//     int i=0,j=0;
//     while (i<n && j<m){
//         if (arr1[i]<arr2[j]){
//             i++;
//         }
//         else if (arr2[j]<arr1[i]){
//             j++;
//         }
//         else{
//             cout<<arr1[i]<<" ";
//             i++;
//             j++;
//         }
//     }
    
//     return 0;
// }

// TC=O(n+m) and SC=O(1)