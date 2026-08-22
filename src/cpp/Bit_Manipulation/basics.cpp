#include <iostream>
#include <algorithm>
using namespace std;

string convert2Binary(int n)
{
    string s = "";
    while (n != 1)
    {
        if (n % 2 == 1)
            s += '1';
        else
            s += '0';
        n /= 2;
    }
    s += '1';
    reverse(s.begin(), s.end());
    return s;
}

int convert2Decimal(string s)
{
    int ans = 0;
    int powerof2 = 1;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        if (s[i] == '1')
            ans += powerof2;
        powerof2 *= 2;
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    cout << convert2Binary(n);
    cout << endl;
    cout << convert2Decimal(s);
    return 0;
}