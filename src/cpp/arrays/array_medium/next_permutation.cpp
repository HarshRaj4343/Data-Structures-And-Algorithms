#include <iostream>
#include <vector>
using namespace std;

// revisit


vector <int> bruteforce(vector <int> &arr, int n){
    // generate all permutations
    // do a linear search and output the next permutation
}
// tc = o(n!*n) -> extremely high order

vector <int> better(vector <int> &arr, int n){
    next_permutation(arr.begin(),arr.end());
    return arr;
}

vector <int> optimal(vector <int> &arr, int n){
    
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
    
    return 0;
}