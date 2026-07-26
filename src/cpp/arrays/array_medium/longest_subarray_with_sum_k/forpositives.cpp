// Brute force

#include <iostream>
#include <vector>
using namespace std;

int longsubarray(vector <int> &arr, int n, int target){
    int len = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int total = 0;
            for (int k = i; k <= j; k++) {
                total += arr[k];
            }
            if (total == target) len = max(len, j-i+1);
        }
    }
    return len;
}

int main()
{
    int n,k;
    cin >> n >> k;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.emplace_back(x);
    }
    cout << longsubarray(v,n,k);
    return 0;
}

// TC = O(n3)

// Slightly better


#include <iostream>
#include <vector>
using namespace std;

int longsubarray(vector <int> &arr, int n, int target){
    int len = 0;
    for (int i = 0; i < n; i++) {
        int total = 0;
        for (int j = i; j < n; j++) {
            total+=arr[j];
            if (total == target) len = max(len, j-i+1);
        }
    }
    return len;
}

int main()
{
    int n,k;
    cin >> n >> k;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.emplace_back(x);
    }
    cout << longsubarray(v,n,k);
    return 0;
}

// TC = O(n2)

// Better Solution using Hashing


#include <iostream>
#include <vector>
using namespace std;

int longsubarray(vector <int> &arr, int n, int target){
    
}

int main()
{
    int n,k;
    cin >> n >> k;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.emplace_back(x);
    }
    cout << longsubarray(v,n,k);
    return 0;
}


// left for now -> do it when you reach mandi