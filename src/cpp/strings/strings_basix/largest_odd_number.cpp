#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;


int oddnum(string s){
    int n = s.length();
    int maxodd = 1;
    for (int i = 0; i < n; i++) {
        char c = s[i];
        int digit = c - '0';
        int odd = 1;
        if (digit % 2 != 0) {
            odd = digit;
            maxodd = max(odd,maxodd);
        }
    }
    return maxodd;
}


int main()
{
    string s;
    cin >> s;
    int n = s.length();
    cout << oddnum(s) << " ";
    return 0;
}
// to convert a string to an integer, we can use the following functions:
// stoi (returns int)
// stol (returns long)
// stoll (returns long long)
// stoull (returns unsigned long long)