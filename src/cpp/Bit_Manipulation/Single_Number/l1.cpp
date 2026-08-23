#include <iostream>
#include <vector>
using namespace std;

// brute - solve via hashing using a hashmap

int f(vector <int> &v, int n){
    int XOR = 0;
    for (auto it : v){
        XOR = XOR^it;
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
    cout << f(v,n) ;
    return 0;
}