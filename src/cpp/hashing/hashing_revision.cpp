// Brute force computation of "How many times does a given number appear in the array?"


// #include <iostream>
// using namespace std;

// int f(int arr[],int n, int target){
//     int cnt = 0;
//     for (int i = 0; i < n; i++) {
//         if (arr[i] == target) cnt++;
//     }
//     return cnt;
// }

// int main() {
//     int n, target;
//     cin >> n >> target;
//     int arr[n];
//     for (int i = 0; i < n; i++) {
//         cin >> arr[i];
//     }
//     cout << f(arr,n,target);
//     return 0;
// }


// Using Hashing 

// #include <iostream>
// using namespace std;

// int main() {
//     int n;
//     cin >> n;

//     int arr[n];

//     for (int i = 0; i < n; i++) {
//         cin >> arr[i];
//     }

//     int hash[n + 1] = {0};

//     for (int i = 0; i < n; i++) {
//         hash[arr[i]]++;
//     }

//     for (int i = 0; i <= n; i++) {
//         cout << hash[i] << " ";
//     }

//     return 0;
// }


// Character hashing

// #include <iostream>
// using namespace std;

// int main() {
//     string s;
//     char target;
//     cin >> s >> target;
//     int hash[256] = {0};
//     for (int i = 0; i < s.size(); i++) {
//         hash[s[i]]++;
//     }
//     cout << hash[target];
//     return 0;
// }

// another version

// #include <iostream>
// using namespace std;
// int main() {
//     string s;
//     cin >> s;
//     //precompute
//     int hash[26] = {0};
//     for (int i=0; i<s.size(); i++){
//         hash[s[i]-'a']++;
//     } // assuming only lowercase letters
//     int q;
//     cin >> q;
//     while (q--) {
//         char x;
//         cin >> x;
//         //fetching
//         cout << hash[x - 'a'] << endl;
//     }
//     return 0;
// }




#include <iostream>
#include <map>
using namespace std;
int main() {
    int n;
    cin>>n;
    int arr[n];
    for (int i=0; i<n; i++){
        cin>>arr[i];
    }

    //precompute
    map<int,int> mpp;
    for (int i=0; i<n;i++){
        mpp[arr[i]]++;
    }

    int q;
    cin>>q;
    while (q--){
        int number;
        cin>>number;
        cout<<mpp[number]<<endl;
    }
    return 0;
}



#include <iostream>
#include <map>
using namespace std;
int main() {
    int n;
    cin>>n;
    int arr[n];
    for (int i=0; i<n; i++){
        cin>>arr[i];
    }

    //precompute
    unordered_map<int,int> mpp;
    for (int i=0; i<n;i++){
        mpp[arr[i]]++;
    }

    int q;
    cin>>q;
    while (q--){
        int number;
        cin>>number;
        cout<<mpp[number]<<endl;
    }
    return 0;
}
