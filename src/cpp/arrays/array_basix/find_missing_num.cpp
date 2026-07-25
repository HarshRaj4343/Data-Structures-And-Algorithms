// Brute Force

#include <iostream>
#include <vector>
using namespace std;

int findMissing(vector<int> &arr, int n)
{
    for (int i = 1; i <= n; i++)
    {
        int flag = 0;
        for (int j = 0; j < n - 1; j++)
        {
            if (arr[j] == i)
                flag = 1;
        }
        if (flag == 0)
            return i;
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
    cout << findMissing(v, n);
    return 0;
}

// TC = O(n**2)
// SC = O(1)

// Better Approach

#include <iostream>
#include <vector>
using namespace std;

int findMissing(vector <int> &arr, int n){
    vector<int> hash(n + 1, 0);
    // push
    for (int i = 0; i < n-1; i++) {
        hash[arr[i]] = hash[arr[i]] + 1;
    }
    // fetch
    for (int i = 1; i < hash.size(); i++) {
        if (hash[i] == 0) return i;
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
    cout << findMissing(v, n);
    return 0;
}

// TC = O(N+N)
// SC = O(N)


// Optimised Soluton with Sum 

#include <iostream>
#include <vector>
using namespace std;

int findMissing(vector<int> &arr, int n)
{
    int expected_sum = (n * (n + 1)) / 2;
    int experimented_sum = 0;
    for (int i = 0; i < n - 1; i++)
    {
        experimented_sum += arr[i];
    }
    return (expected_sum - experimented_sum);
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
    cout << findMissing(v, n);
    return 0;
}

// TC = O(N)
// SC = O(1)



// Optimised Soluton with XOR -> This is slightly better due to data overflow error.

// a XOR a = 0
// a XOR 0 = 0


#include <iostream>
#include <vector>
using namespace std;

int findMissing(vector<int> &arr, int n)
{
    int XOR1 = 0;
    int XOR2 = 0;
    for (int i = 1; i < n; i++) {
        XOR1 = XOR1^i;
    }
    for (int i = 1; i < n-1; i++) {
        XOR2 = XOR2^i;
    }
    int result = XOR1^XOR2;
    return result;
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
    cout << findMissing(v, n);
    return 0;
}

// TC = O(2N)
// SC = O(1)


// Another Version

#include <iostream>
#include <vector>
using namespace std;

int findMissing(vector<int> &arr, int n)
{
    int XOR1 = 0;
    int XOR2 = 0;
    for (int i = 1; i < n-1; i++) {
        XOR2 = XOR2^i;
        XOR1 = XOR1^(i+1);
    }
    XOR1 = XOR1^n;
    int result = XOR1^XOR2;
    return result;
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
    cout << findMissing(v, n);
    return 0;
}

// TC = O(N)
// SC = O(1)