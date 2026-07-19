// count number of digits in a number

// THE EASIEST ONE!

// #include <iostream>
// using namespace std;

// int main()
// {
//     int n;
//     cin >> n;
//     string s = to_string(n);
//     cout << s.length();
//     return 0;
// }

// SLIGHTLY IMPROVED VERSION

// #include <iostream>
// using namespace std;

// int main()
// {
//     int n;
//     cin >> n;
//     int count = 0;
//     while (n > 0)
//     {
//         n = n / 10;
//         count++;
//     }
//     cout << count;
//     return 0;
// }

// MATHEMATICAL FORMULA

// #include <iostream>
// #include <cmath>
// using namespace std;

// int main() {
//     int n;
//     cin >> n;
//     cout << floor(log10(n))+1;
//     return 0;
// }

// Reversing a number (trailing zeros being skipped)

// #include <iostream>
// using namespace std;

// int main()
// {
//     int n, reversed = 0;
//     cin >> n;
//     while (n > 0)
//     {
//         int lastdigit = n % 10;
//         n /= 10;
//         reversed = reversed * 10 + lastdigit;
//     }
//     cout << reversed;
//     return 0;
// }

// for 324
// lastdigit = 4
// reversed = 4
// lastdigit = 2
// reversed = 42
// lastdigit = 3
// reversed = 423
// finally -> 423

// What if the trailing zeros are not skipped -> SIMPLE ONE

// #include <iostream>
// using namespace std;

// int main() {
//     int n;
//     cin >> n;
//     while (n>0){
//         cout << n%10;
//         n/=10;
//     }
//     return 0;
// }


// PALINDROME CHECK