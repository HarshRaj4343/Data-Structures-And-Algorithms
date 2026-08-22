#include <iostream>
using namespace std;

int f1(int N)
{
    return ((N & N - 1) == 0);
}

int main()
{
    int N;
    cin >> N;
    cout << f1(N) << endl;
    return 0;
}