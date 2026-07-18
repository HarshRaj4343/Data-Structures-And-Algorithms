// Can you explain how to determine whether a given integer is a power of 2?
// Your solution should include:
// An O(log n) approach with an explanation.
// An O(1) approach using bit manipulation, along with the intuition behind why it works.

// O(log n) method

// #include <iostream>
// #include <bitset>
// using namespace std;

// int main()
// {
//     int n;
//     cin >> n;
//     int count = 0;
//     string gut = bitset<32>(n).to_string();
//     for (int i = 0; i < gut.size(); i++)
//     {
//         if (gut[i] == '1')
//             count++;
//     }
//     if (count == 1 && n > 0)
//     {
//         cout << "The given number is in the power of 2 only!";
//     }
//     else
//     {
//         cout << "Bad Luck!";
//     }
//     return 0;
// }

// In C++, a single & is a bitwise operator. For checking two independent conditions in an if statement, you should use the logical AND operator: &&.

// O(1) -> Bit Manipulation Method

#include <iostream>
#include <bitset>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int pred = n - 1;
    bitset<32> mo = bitset<32>(n);
    bitset<32> pi = bitset<32>(pred);
    
    if ((mo & pi) == 0)
    {
        cout << "The given number is in the power of 2 only!";
    }
    else
    {
        cout << "Bad Luck!";
    }

    return 0;
}