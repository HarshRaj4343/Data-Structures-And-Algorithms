// Brute Force

// #include <iostream>
// #include <vector>
// using namespace std;

// void LeftRotate(vector <int> &arr, int n, int d){
//     d = d%n;
//     vector <int> temp;
//     for (int i = 0; i < d; i++) {
//         temp.emplace_back(arr[i]);
//     }
//     for (int i = d; i < n; i++) {
//         arr[i-d] = arr[i];
//     }
//     int j = 0;
//     for (int i = n-d; i < n; i++) {
//         arr[i] = temp[j];
//         j++;
//     }
// }

// // OR

// void LeftRotate1(vector <int> &arr, int n, int d){
//     d = d%n;
//     vector <int> temp;
//     for (int i = 0; i < d; i++) {
//         temp.emplace_back(arr[i]);
//     }
//     for (int i = d; i < n; i++) {
//         arr[i-d] = arr[i];
//     }
//     for (int i = n-d; i < n; i++) {
//         arr[i] = temp[i-(n-d)];
//     }
// }

// int main()
// {
//     int n,d;
//     cin >> n >> d;
//     vector<int> v;
//     for (int i = 0; i < n; i++)
//     {
//         int x;
//         cin >> x;
//         v.emplace_back(x);
//     }
//     LeftRotate(v,n,d);
//     for (auto it : v ) cout << it << " ";
//     return 0;
// } 

// TC = O(d) + O(n-d) + O(d) = O(n+d)
// SC = O(d)


// Optimal Solution

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void LeftRotate(vector<int> &arr, int n, int d){
    reverse(arr.begin(), arr.begin() + d);
    reverse(arr.begin() + d, arr.begin() + n);
    reverse(arr.begin(), arr.begin() + n);
}

int main()
{
    int n,d;
    cin >> n >> d;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.emplace_back(x);
    }
    LeftRotate(v,n,d);
    for (auto it : v){
        cout << it << " ";
    }
    return 0;
}

// TC = O(2n)
// SC = O(1)

// Homeworks


// Write your own Reverse Function


// Right rotate the array by d places