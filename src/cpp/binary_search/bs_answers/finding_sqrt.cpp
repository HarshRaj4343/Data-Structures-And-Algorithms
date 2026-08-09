#include <iostream>
using namespace std;

int brute(int n)
{
    int ans = 1;
    for (int i = 1; i <= n; i++)
    {
        if (i * i <= n)
            ans = i;
        else
            break;
    }
    return ans;
}
int bs(int n)
{
    int low = 1;
    int high = n;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (mid * mid <= n)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return high;
}
// if we are sure about about the range of the ans, and we are asked to compute either the min or max, then go with binary search.
int main()
{
    int n;
    cin >> n;
    cout << bs(n);
    return 0;
}