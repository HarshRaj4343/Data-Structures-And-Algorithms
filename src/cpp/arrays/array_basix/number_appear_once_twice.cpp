// Brute Force

#include <iostream>
#include <vector>
using namespace std;

int findimposter(vector <int> &arr, int n){
    for (int i = 0; i < n; i++) {
        int num = arr[i];
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if (arr[j] == num) cnt++;
        }
        if (cnt == 1) return num;
    }
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
    cout << findimposter(v,n);
    return 0;
}

// TC = O(n2)
// SC = O(1)

// Better Solution Using Hashing


#include <iostream>
#include <vector>
using namespace std;

int findlargest(vector<int> &arr, int n)
{
    int largest = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > largest)
            largest = arr[i];
    }
    return largest;
}

int findimposter(vector <int> &arr, int n){
    int lar = findlargest(arr,n);
    vector<int> hash(lar+1, 0);
    // push
    for (int i = 0; i < n; i++) {
        hash[arr[i]] = hash[arr[i]] + 1;
    }
    // fetch
    for (int i = 0; i < hash.size(); i++) {
        if (hash[i] == 1) return arr[i];
    }
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
    cout << findimposter(v,n);
    return 0;
}

// TC = O(3n)
// Downside : We need to use map data structure if the numbers were greater than 1e7




// Optimal Solution

#include <iostream>
#include <vector>
using namespace std;

int findimposter(vector <int> &arr, int n){
    int XOR = 0;
    for (int i = 0; i < n; i++) {
        XOR = XOR^arr[i];
    }
    return XOR;
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
    cout << findimposter(v,n);
    return 0;
}

// tc = O(n)