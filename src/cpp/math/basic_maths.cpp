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

// #include <iostream>
// using namespace std;

// int main()
// {
//     int n, reversed = 0;
//     cin >> n;
//     int duplicate = n;
//     while (n > 0)
//     {
//         int last = n % 10;
//         n /= 10;
//         reversed = reversed * 10 + last;
//     }
//     if (reversed == duplicate)
//     {
//         cout << "The given number is a palindrome!";
//     }
//     else
//     {
//         cout << "Unfortunately, this is not a palindrome!";
//     }
//     return 0;
// }

// ARMSTRONG NUMBER CHECK

// (A number whose digits, each raised to the power, sums back to the number itself.)

// #include <iostream>
// #include <cmath>
// using namespace std;
// int noofdigit(int a){
//     int count = 0;
//     while (a>0){
//         a/=10;
//         count++;
//     }
//     return count;
// }
// int main() {
//     int n;
//     cin >> n;
//     int duplicate = n;
//     // finding the number of digits of that particular number
//     int power = noofdigit(n);
//     // sequentially sum all the digits raised to the power
//     int total = 0;
//     while(n>0){
//         int lastdigit = n%10;
//         n/=10;
//         total = total + pow(lastdigit,power);
//     }
//     if (total == duplicate){
//         cout << "It is undoubtedly an Armstrong number.";
//     }
//     else{
//         cout << "It is not an Armstrong number.";
//     }
//     return 0;
// }

// Printing all divisors of a particular number (printing every number that evenly divides N, in sorted order)

// Brute Force Method (O(n))

// #include <iostream>
// using namespace std;

// int main() {
//     int n;
//     cin >> n;
//     for (int i = 1; i <= n; i++) {
//         if (n%i == 0){
//             cout << i << " ";
//         }
//     }
//     return 0;
// }

// Optimised version

// #include <iostream>
// using namespace std;

// int main() {
//     int n;
//     cin >> n;
//     for (int i = 1; i * i <= n; i++) {
//         if (n % i == 0) {
//             cout << i << " ";
//             if (n/i != i) {
//                 cout << n / i << " ";
//             }
//         }
//     }
//     return 0;
// }

// PRIME NUMBER CHECKER -> Using Optimised version

// #include <iostream>
// using namespace std;

// int main()
// {
//     int n;
//     cin >> n;
//     int cnt = 0;
//     for (int i = 1; i * i <= n; i++)
//     {
//         if (n % i == 0)
//         {
//             cnt++;
//             if ((n / i) != i)
//             {
//                 cnt++;
//             }
//         }
//     }
//     if (cnt == 2)
//         cout << "Prime";
//     else
//         cout << "Composite";
//     return 0;
// }

// GCD Computation

// Ultra Brute Force

// #include <iostream>
// #include <algorithm>
// #include <vector>
// using namespace std;

// vector<int> rdivisor(int a)
// {
//     vector<int> cont;
//     for (int i = 1; i * i <= a; i++)
//     {
//         if (a % i == 0)
//         {
//             cont.emplace_back(i);
//             if (a / i != i)
//             {
//                 cont.emplace_back(a / i);
//             }
//         }
//     }
//     return cont;
// }

// int main()
// {
//     int n, m;
//     cin >> n >> m;
//     vector <int> arr1 = rdivisor(n);
//     vector <int> arr2 = rdivisor(m);
//     vector <int> con;
//     for (int i = 0; i < arr1.size(); i++) {
//         for (int j = 0; j < arr2.size(); j++) {
//             if (arr1[i]==arr2[j]){
//                 con.emplace_back(arr1[i]);
//             }
//         }
//     }
//     auto it = max_element(con.begin(), con.end());
//     int ans = *it;
//     cout << ans;
//     return 0;
// }

// Brute Force

// #include <iostream>
// #include <algorithm>
// using namespace std;

// int computegcd(int n1, int n2)
// {
//     int result = 1;
//     for (int i = 1; i <= min(n1, n2); i++)
//     {
//         if (n1 % i == 0 && n2 % i == 0)
//         {
//             result = i;
//         }
//     }
//     return result;
// }
// int main()
// {
//     int n, m;
//     cin >> n >> m;
//     cout << computegcd(n, m);
//     return 0;
// }

// the most optimised version using Euclidean algorithm

// #include <iostream>
// using namespace std;

// int EuclideanAlgo(int n1, int n2)
// {
//     while (n1 > 0 && n2 > 0)
//     {
//         if (n1 > n2)
//             n1 = n1 % n2;
//         else
//             n2 = n2 % n1;
//     }
//     if (n1 == 0)
//         return n2;
//     return n1;
// }

// int main()
// {
//     int n, m;
//     cin >> n >> m;
//     cout << EuclideanAlgo(n, m);
//     return 0;
// }
// gcd(x,0) is always x.