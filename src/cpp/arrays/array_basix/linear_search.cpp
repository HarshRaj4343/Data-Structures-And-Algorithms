#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n,target;
    cin >> n >> target;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.emplace_back(x);
    }
    int idx = -1;
    for (int i = 0; i < n; i++) {
        if (v[i] == target){
            idx = i;
            break;
        }
    }
    cout << idx;
    return 0;
}

// main() always returns -1 no matter what happens,