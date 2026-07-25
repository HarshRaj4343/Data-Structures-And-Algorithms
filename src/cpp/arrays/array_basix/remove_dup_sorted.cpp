// Brute Force

// #include <iostream>
// #include <vector>
// #include <set>
// using namespace std;

// set<int> RemoveDuplicatesfromSorted(vector<int> &arr, int n)
// {
//     set<int> s;
//     for (int i = 0; i < n; i++)
//     {
//         s.insert(arr[i]);
//     }
//     return s;
// }

// int main()
// {
//     int n;
//     cin >> n;
//     vector<int> v;
//     for (int i = 0; i < n; i++)
//     {
//         int x;
//         cin >> x;
//         v.emplace_back(x);
//     }
//     set<int> sv = RemoveDuplicatesfromSorted(v, n);
//     int index = 0;
//     vector<int> ans;
//     for (auto it : sv)
//     {
//         ans.emplace_back(it);
//         index++;
//     }
//     for (auto it1 : ans)
//         cout << it1 << " ";
//     return 0;
// }

// TC = O(NlogN + N)
// SC = O(N)


// Optimal -> 2 Pointer Approach

#include <iostream>
#include <vector>
using namespace std;

int optimal(vector <int> &arr, int n){
    if (n == 0) return 0;   // handle empty input
    int i = 0;
    for (int j = 1; j < n; j++) {
        if (arr[j] != arr[i]){
            arr[i+1] = arr[j];
            i++;
        }
    }
    return i+1;
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
    int x = optimal(v,n);
    cout << "Size of the array with unique elements: " << x;
    return 0;
}