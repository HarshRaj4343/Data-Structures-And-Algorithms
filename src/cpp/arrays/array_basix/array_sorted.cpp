#include <iostream>
#include <vector>
using namespace std;
bool sorted_checker(vector <int> &arr, int n){
    for (int i = 0; i < n-1; i++) {
        if (arr[i+1] < arr[i]){
            return false;
        }
    }
    return true;
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
    cout << sorted_checker(v, n);
    return 0;
}