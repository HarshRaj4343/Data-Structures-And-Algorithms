// Type 1 of Pascal's Triangle

// #include <iostream>
// using namespace std;
// int main() {
//     int m,n;
//     cin>>m>>n;
//     int p=1;
//     for (int i=1;i<=m-1;i++){
//         p=p*i;
//     }
//     int q=1;
//     for (int i=1;i<=n-1;i++){
//         q=q*i;
//     }
//     int r=1;
//     for (int i=1;i<=m-n;i++){
//         r=r*i;
//     }
//     cout<<p/(q*r);
//     return 0;
// }

// Slightly Better one

// #include <iostream>
// using namespace std;
// int fxn(int n, int r){
//     int result=1;
//     for (int i=0;i<r;i++){
//         result*=(n-i);
//         result/=i+1;
//     }
//     return result;
// }
// int main() {
//     int m,n;
//     cin>>m>>n;
//     cout<<fxn(m-1,n-1);
// }

// Type -2 Brute Force Solution

// #include <iostream>
// using namespace std;
// int fxn(int n, int r){
//     int result=1;
//     for (int i=0;i<r;i++){
//         result*=(n-i);
//         result/=i+1;
//     }
//     return result;
// }
// int main() {
//     int n;
//     cin>>n;
//     for (int i=1;i<=n;i++){
//         cout<<fxn(n-1,i-1)<<" ";
//     }
//     return 0;
// }

// Type -2 Optimized Solution

// #include <iostream>
// using namespace std;
// int main() {
//     int n;
//     cin>>n;
// int ans = 1;
// cout<<ans<<" ";
// for (int i=1;i<n;i++){
//     ans*=(n-i);
//     ans/=i;
//     cout<<ans<<" ";
// }
//     return 0;
// }

// Type - 3 Brute Force

// #include <iostream>
// #include <list>
// using namespace std;

// int fxn(int n, int r){
//     int result=1;
//     for (int i=0;i<r;i++){
//         result*=(n-i);
//         result/=i+1;
//     }
//     return result;
// }

// int main() {
//     int n;
//     cin >> n;
//     list<int> ans;

//     for (int i = 1; i < n; i++){
//         list<int> temp;
//         for (int j = 1; j < i; j++){
//             temp.push_back(fxn(i-1, j-1));
//         }
//         ans.splice(ans.end(), temp); // append temp to ans
//     }

//     for (auto it : ans){
//         cout << it << " ";
//     }
//     return 0;
// }

// Type - 3 Optimized

// #include <iostream>
// using namespace std;
// int main() {
//     int n;
//     cin >> n;
//     for (int i = 1; i <= n; i++){
//         int ans = 1;
//         cout<<ans<<" ";
//         for (int j=1;j<i;j++){
//             ans*=(i-j);
//             ans/=j;
//             cout<<ans<<" ";
//         }
//     }
//     return 0;
// }

// Majority Element ( > n/3 times)

// Brute Force

// #include <iostream>
// #include <list>
// #include <vector>
// using namespace std;
// int main() {
//     int n;
//     cin >> n;
//     vector<int> arr(n);
//     for (int i = 0; i < n; i++){
//         cin >> arr[i];
//     }
//     list<int> ans;
//     for (int i = 0; i < n; i++){
//         if (ans.size()==0 || ans.front()!=arr[i]){
//             int count = 0;
//             for (int j = 0; j < n; j++){
//                 if (arr[i] == arr[j]){
//                     count++;
//                 }
//             }
//             if (count > n / 3){
//                 ans.push_back(arr[i]);
//             }
//         }
//         if (ans.size() > 2){
//             break;
//         }
//     }
//     for (auto it : ans){
//         cout << it << " ";
//     }
//     return 0;
// }

// Better Approach (Using Hashmap)

// #include <iostream>
// #include <vector>
// #include <unordered_map>
// using namespace std;
// int main() {
//     int n;
//     cin >> n;
//     vector<int> arr(n);
//     for (int i = 0; i < n; i++){
//         cin >> arr[i];
//     }
//     unordered_map<int, int> freq;
//     for (int i = 0; i < n; i++){
//         freq[arr[i]]++;
//     }
//     for (auto it : freq){
//         if (it.second > n / 3){
//             cout << it.first << " ";
//         }
//     }
//     return 0;
// }

// Optimal Approach (Moore's Voting Algorithm)

// #include <iostream>
// using namespace std;
// int main() {
//     int n;
//     cin >> n;
//     int arr[n];
//     for (int i = 0; i < n; i++){
//         cin >> arr[i];
//     }
//     int count1 = 0, count2 = 0;
//     int candidate1 = INT_MIN, candidate2 = INT_MIN;
//     for (int i = 0; i < n; i++){
//         if (count1 == 0 && arr[i] != candidate2){
//             candidate1 = arr[i];
//             count1 = 1;
//         }
//         else if (count2 == 0 && arr[i] != candidate1){
//             candidate2 = arr[i];
//             count2 = 1;
//         }
//         else if (arr[i] == candidate1){
//             count1++;
//         }
//         else if (arr[i] == candidate2){
//             count2++;
//         }
//         else{
//             count1--;
//             count2--;
//         }
//     }
//     count1 = 0;
//     count2 = 0;
//     for (int i = 0; i < n; i++){
//         if (arr[i] == candidate1){
//             count1++;
//         }
//         else if (arr[i] == candidate2){
//             count2++;
//         }
//     }
//     if (count1 > n / 3){
//         cout << candidate1 << " ";
//     }
//     if (count2 > n / 3){
//         cout << candidate2 << " ";
//     }
//     return 0;
// }

// 3-Sum Problem

// Brute Force Approach

// #include <iostream>
// #include <vector>
// #include <set>
// #include <algorithm>
// using namespace std;
// int main() {
// int n;
// cin >> n;
// vector<int> arr(n);
// for (int i = 0; i < n; i++){
//     cin >> arr[i];
// }
// set <vector<int>> st;
//     for (int i=0;i<n;i++){
//         for (int j=i+1;j<n;j++){
//             for (int k=j+1;k<n;k++){
//                 if (arr[i]+arr[j]+arr[k]==0){
//                     vector <int> temp = {arr[i],arr[j],arr[k]};
//                     sort(temp.begin(),temp.end());
//                     st.insert(temp);
//                 }
//             }
//         }
//     }
// vector <vector<int>> ans(st.begin(),st.end());
// for (auto it : ans){
//     for (auto jt : it){
//         cout << jt << " ";
//     }
//     cout << endl;
// }
//     return 0;
// }

// Better Approach (Using Hashing)

// #include <iostream>
// #include <vector>
// #include <set>
// #include <algorithm>
// using namespace std;
// int main() {
//     int n;
//     cin >> n;
//     vector<int> arr(n);
//     for (int i = 0; i < n; i++){
//         cin >> arr[i];
//     }
//     set <vector<int>> st;
//     for (int i=0;i<n;i++){
//         set <int> hashmap;  // initializes itself everytime i changes
//         for (int j=i+1;j<n;j++){
//             int third = - (arr[i]+arr[j]);
//             hashmap.insert(arr[j]);
//             if (hashmap.find(third) != hashmap.end()){
//                 vector <int> temp = {arr[i],arr[j],third};
//                 sort(temp.begin(),temp.end());
//                 st.insert(temp);
//             }
//         }
//     }
//     vector <vector<int>> ans(st.begin(),st.end());
// for (auto it : ans){
//     for (auto jt : it){
//         cout << jt << " ";
//     }
//     cout << endl;
// }
//     return 0;
// }

// Optimal Solution

// #include <iostream>
// #include <vector>
// #include <set>
// #include <algorithm>
// using namespace std;
// int main() {
//     int n;
//     cin >> n;
//     vector<int> arr(n);
//     for (int i = 0; i < n; i++){
//         cin >> arr[i];
//     }
//     sort(arr.begin(),arr.end());
//     vector <vector<int>> ans;
//     for (int i=0;i<n;i++){
//         if (i>0 && arr[i] == arr[i-1]) continue;
//         int j = i+1;
//         int k = n-1;
//         while (j<k) {
//             int sum = arr[i] + arr[j] + arr[k];
//             if (sum < 0) {
//                 j++;
//             }
//             else if (sum > 0){
//                 k--;
//             }
//             else {
//                 vector <int> temp = {arr[i],arr[j],arr[k]};
//                 ans.push_back(temp);
//                 j++; // first move to a new pair and check for duplicates
//                 k--;
//                 while (j<k && arr[j]==arr[j-1]) j++;
//                 while (j<k && arr[k]==arr[k+1]) k--;
//             }
//         }
//     }
// for (auto it : ans){
//     for (auto jt : it){
//         cout << jt << " ";
//     }
//     cout << endl;
// }
//     return 0;
// }

// 4-Sum Problem

// Brute force

// #include <iostream>
// #include <vector>
// #include <set>
// #include <algorithm>
// using namespace std;
// int main() {
//     int n;
//     cin >> n;
//     vector<int> arr(n);
//     for (int i = 0; i < n; i++){
//         cin >> arr[i];
//     }
//     set <vector<int>> st;
//     for (int i=0;i<n;i++){
//         for (int j=i+1;j<n;j++){
//             for (int k=j+1;k<n;k++){
//                 for (int l=k+1;l<n;l++){
//                     if (arr[i]+arr[j]+arr[k]+arr[l]==0){
//            better to write as below to avoid overflow
//     if ( ((long long)arr[i] + (long long)arr[j] + (long long)arr[k] + (long long)arr[l]) == 0 ){} or
//    int sum= arr[i]+arr[j];
//    sum+=arr[k];
//    sum+=arr[l];
//    if (sum==0){}
//                         vector <int> temp = {arr[i],arr[j],arr[k],arr[l]};
//                         sort(temp.begin(),temp.end());
//                         st.insert(temp);
//                     }
//                 }
//             }
//         }
//     }
//     vector <vector<int>> ans(st.begin(),st.end());
//     for (auto it : ans){
//         for (auto jt : it){
//             cout << jt << " ";
//         }
//         cout << endl;
//     }
//     return 0;
// }

// Better Approach (Using Hashing)

// #include <iostream>
// #include <vector>
// #include <set>
// #include <algorithm>
// using namespace std;
// int main() {
//     int n;
//     cin >> n;
//     vector<int> arr(n);
//     for (int i = 0; i < n; i++){
//         cin >> arr[i];
//     }
//     set <vector<int>> st;
//     for (int i=0;i<n;i++){
//         set <int> hashset;
//         for (int j=i+1;j<n;j++){
//             for (int k = j+1;k<n;k++){
//                 int fourth = - (arr[i]+arr[j]+arr[k]);
//                 hashset.insert(arr[k]);
//                 if (hashset.find(fourth) != hashset.end()){
//                     vector <int> temp = {arr[i],arr[j],arr[k],fourth};
//                     sort(temp.begin(),temp.end());
//                     st.insert(temp);
//                 }
//             }
//         }
//     }
//     vector <vector<int>> ans(st.begin(),st.end());
//     for (auto it : ans){
//         for (auto jt : it){
//             cout << jt << " ";
//         }
//         cout << endl;
//     }
//     return 0;
// }

// Optimal Approach

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    for (int i = 0; i < n; i++)
    {
        if (i > 0 && arr[i] == arr[i - 1])
            continue;
        for (int j = i + 1; j < n; j++)
        {
            if (j != i + 1 && arr[j] == arr[j - 1])
                continue;
            int k = j + 1;
            int l = n - 1;
            while (k < l)
            {
                int sum = arr[i] + arr[j] + arr[k] + arr[l];
                if (sum < 0)
                    k++;
                else if (sum > 0)
                    l--;
                else
                {
                    vector<int> temp = {arr[i], arr[j], arr[k], arr[l]};
                    ans.push_back(temp);
                    k++;
                    l--;
                    while (k < l && arr[k] == arr[k - 1])
                        k++;
                    while (k < l && arr[l] == arr[l + 1])
                        l--;
                }
            }
        }
    }
    for (auto it : ans)
    {
        for (auto jt : it)
        {
            cout << jt << " ";
        }
        cout << endl;
    }
    return 0;
}
