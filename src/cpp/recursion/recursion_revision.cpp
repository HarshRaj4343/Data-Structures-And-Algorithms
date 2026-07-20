// A simple recursion example

// #include <iostream>
// using namespace std;

// void printer(int count)
// {
//     if (count == 5)
//         return;
//     cout << count << " ";
//     count++;
//     printer(count);
// }
// int main()
// {
//     printer(0);
//     return 0;
// }

// Printing a name 'n' times

// #include <iostream>
// using namespace std;

// void nameprinter(int n,int i,string s){
//     if (i>n) return;
//     cout << s << endl;
//     i++;
//     nameprinter(n,i,s);
// }

// int main() {
//     int n;
//     string name;
//     cin >> n >> name;
//     int i = 1;
//     nameprinter(n,i,name);
//     return 0;
// }

// Printing linearly from 1 to n

// #include <iostream>
// using namespace std;

// void printingpress(int a,int i){
//     if (i>a) return;
//     cout << i << endl;
//     i++;
//     printingpress(a,i);
// }

// int main() {
//     int n;
//     cin >> n;
//     int i = 1;
//     printingpress(n,i);
//     return 0;
// }

// Printing linearly from 1 to n

// #include <iostream>
// using namespace std;

// void printpress(int a, int i){
//     if (i<1) return;
//     cout << i << endl;
//     i--;
//     printpress(a,i);
// }

// int main() {
//     int n;
//     cin >> n;
//     int i = n;
//     printpress(n,i);
//     return 0;
// }

// Using backtracking to print 1 to n

// #include <iostream>
// using namespace std;

// void printpress(int a, int i){
//     if (i<1) return;
//     printpress(a,i-1);
//     cout << i << endl;
// }

// int main() {
//     int n;
//     cin >> n;
//     int i = n;
//     printpress(n,i);
//     return 0;
// }

// Using backtracking to print n to 1

// #include <iostream>
// using namespace std;

// void printingpress(int a,int i){
//     if (i>a) return;
//     printingpress(a,i+1);
//     cout << i << endl;
// }

// int main() {
//     int n;
//     cin >> n;
//     int i = 1;
//     printingpress(n,i);
//     return 0;
// }

// sum of first n numbers using my way (avoid)

// #include <iostream>
// using namespace std;

// int sumprint(int n, int i, int count){
//     if (i>n) return count;
//     count += i;
//     return sumprint(n,i+1,count);
// }

// int main() {
//     int n;
//     cin >> n;
//     int i = 1;
//     cout << sumprint(n,i,0);
//     return 0;
// }

// for n = 5
// sumprint(5,0)
// count = 0+1 = count
// sumprint(5,2,1)
// count = 3
// sumprint(5,3,3)
// count = 6
// sumprint(5,4,6)
// count = 10
// sumprint(5,5,10)
// count = 15
// sumprint(5,6,15)
// return count = 15

// Parametrised Way

// #include <iostream>
// using namespace std;
// void sum1(int i, int sum) {
//     if (i < 1) {
//         cout << sum;
//         return;
//     }
//     sum1(i - 1, sum + i);
// }
// int main() {
//     int n;
//     cin >> n;
//     sum1(n,0);
//     return 0;
// }

// Functional way

// #include <iostream>
// using namespace std;

// int sum(int n, int i) {
//     if (i > n)
//         return 0;

//     return i + sum(n, i + 1);
// }
// int main() {
//     int n;
//     cin >> n;
//     int i = 1;
//     cout << sum(n,i);
//     return 0;
// }

// functional way for printing factorial

// #include <iostream>
// using namespace std;

// int fact(int a, int i)
// {
//     if (i > a)
//         return 1;
//     return i * fact(a, i + 1);
// }

// int main()
// {
//     int n;
//     cin >> n;
//     cout << fact(n, 1);
//     return 0;
// }

//////////////////////
// Reversing an array
//////////////////////

// #include <iostream>
// #include <vector>
// using namespace std;

// int main() {
//     int n;
//     cin >> n;
//     vector <int> arr[n];

//     return 0;
// }

////////////////////
// Checking a string for palindrome
///////////////////

// #include <iostream>
// using namespace std;

// bool palindromecheck(string k){
//     if
// }

// int main() {
//     string s;
//     cin >> s;

//     return 0;
// }

////////////////////
// Fibonacci Number Printing
///////////////////

// #include <iostream>
// using namespace std;

// int fib(int a)
// {
//     if (a <= 1)
//         return a;
//     return fib(a - 1) + fib(a - 2);
// }

// int main()
// {
//     int n;
//     cin >> n;
//     cout << fib(n);
//     return 0;
// }
