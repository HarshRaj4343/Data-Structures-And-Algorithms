#include <iostream>
using namespace std;

// Brute force -> convert to binary -> traverse -> check -> if 1 return 0 else return 0 only

// Optimal

int f(int N)
{
    return (N & (N - 1));
}   

int main()
{
    int N;
    cin >> N;
    cout << f(N) << endl;
    return 0;
}