#include <iostream>
using namespace std;

void swapper(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

// Without using the extra variable

// XOR of same numbers = 0

void swapoptimal(int &a, int &b)
{
    a = a ^ b; // a = a^b
    b = a ^ b; // b = a^b^b = a
    a = a ^ b; // a = a^b^a = b
}

int main()
{
    int n, m;
    cin >> n >> m;
    cout << "Initial Values:" << endl
         << n << " " << m << endl;
    swapper(n, m);
    cout << "Final Values (Brute):" << endl
         << n << " " << m << endl;
    swapoptimal(n, m);
    cout << "Final Values (Optimal):" << endl
         << n << " " << m << endl;
    return 0;
}