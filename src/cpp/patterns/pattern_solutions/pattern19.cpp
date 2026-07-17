#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= 2 * n; i++)
    {
        int count = (i <= n) ? (n - i + 1) : (i - n);

        for (int j = 1; j <= count; j++)
        {
            cout << "* ";
        }
        for (int j = 1; j <= 2 * (n - count); j++)
        {
            cout << " ";
        }
        for (int j = 1; j <= count; j++)
        {
            cout << "* ";
        }

        cout << endl;
    }
    return 0;
}