// // method 1 to count number of digits in a number


// #include <iostream>
// using namespace std;
// int main() {
//     int a;
//     cin>>a;
//     int count=0;
//     while (a>0){
//         cout<<a%10<<endl;
//         a=a/10;
//         count++;
//     }
//     cout<<"The number of digits is "<<count<<endl;
//     return 0;
// }

// // time complexity: O(log n base 10)


// //method 2 using log10 function

// #include <iostream>
// using namespace std;
// int main() {
//     int a;
//     cin>>a;
//     int count=log10(a)+1;
//     cout<<"The number of digits is "<<count<<endl;
//     return 0;
// }
// //time complexity: O(1)


// method to reverse a number ( ignoring leading zeros )


// #include <iostream>
// using namespace std;
// int main() {
//     int a, reversed=0, lastdigit;
//     cin>>a;
//     while (a>0){
//         lastdigit=a%10;
//         reversed=reversed*10+lastdigit;
//         a=a/10;
//     }
//     cout<<"The reversed number is "<<reversed<<endl;
//     return 0;
// }

// (with leading zeros not ignored)

// #include <iostream>
// using namespace std;
// int main() {
//     int n;
//     cin>>n;
//     while (n>0){
//         cout<<n%10;
//         n/=10;
//     }
// }



//palindrome checker

// #include <iostream>
// using namespace std;
// int main() {
//     int a, reversed=0, lastdigit, original;
//     bool palindrome=false;
//     cin>>a;
//     a=original;
//     while (a>0){
//         lastdigit=a%10;
//         reversed=reversed*10+lastdigit;
//         a=a/10;
//     }
//     if (reversed==original){
//         palindrome=true;
//         cout<<"The number is a palindrome"<<endl;
//     }
//     else{
//         cout<<"The number is not a palindrome"<<endl;
//     }
//     return 0;
// }



// //Armstrong number checker
// //Armstrong number is a number which is equal to the sum of cubes of its digits.

// #include <iostream>
// using namespace std;
// int main() {
//     int a, original;
//     cin >> a;
//     original = a; 
//     int sum = 0;
//     while (a > 0) {
//         int lastdigit = a % 10;
//         int cube = lastdigit * lastdigit * lastdigit;
//         sum += cube; 
//         a = a / 10;
//     }
//     if (sum == original) {
//         cout << "The number is an Armstrong number" << endl;
//     } else {
//         cout << "The number is not an Armstrong number" << endl;
//     }
//     return 0;
// }


// //divisor printer

// #include <iostream> 
// using namespace std;
// int main() {
//     int a;
//     cin >> a;
//     for (int i = 1; i <= a; i++) {
//         if (a % i == 0) {
//             cout << i << endl;
//         }
//     }
//     return 0;
// }
// // O(n) time complexity

// //another faster method to print divisors


// #include <iostream>
// using namespace std;
// int main() {
//     vector<int> divisors;
//     int a;
//     cin >> a;
//     for (int i = 1; i * i <= a; i++) { // i*i<=a is same as i<=sqrt(a) but this is faster
//         //O(sqrt(n))
//         if (a % i == 0) {
//             cout << i << endl;
//             if (i != a / i) {
//                 divisors.push_back(a / i);
//             }
//         }
//     //O(sqrt(n))
//     }
//     for (int j = divisors.size() - 1; j >= 0; j--) {
//         cout << divisors[j] << endl;
//     }
//     return 0;
// }

//total time complexity: O(sqrt(n)) (since adding two O(sqrt(n)) operations doesn't change the overall time complexity)


//prime number checker


// #include <iostream>
// using namespace std;
// int main() {
//     int n,count=0;
//     cin>>n;
//     for (int i=1; i<=n; i++){
//         if (n%i==0){
//             count++;
//         }
//     }
//     if (count==2){
//         cout<<"The number is prime."<<endl;
//     }
//     else{
//         cout<<"The number is not prime."<<endl;
//     }
//     return 0;
// }

// //O(n) time complexity


// //optimized prime number checker

// #include <iostream>
// using namespace std;
// int main() {
//     int n, count = 0;
//     cin >> n;
//     for (int i = 1; i * i <= n; i++) {
//         if (n % i == 0) {
//             count++;
//             if (i != n / i) {
//                 count++;
//             }
//         }
//     }
//     if (count == 2) {
//         cout << "The number is prime." << endl;
//     } else {
//         cout << "The number is not prime." << endl;
//     }

//     return 0;
// }

// //O(sqrt(n)) time complexity



// gcd caculator


// #include <iostream>
// using namespace std;

// int main() {
//     int a, b;
//     cin >> a >> b;

//     int gcd = 1; 

//     for (int i = 1; i <= min(a, b); i++) {
//         if (a % i == 0 && b % i == 0) {
//             gcd = i; 
//         }
//     }
//     cout << "The GCD is " << gcd << endl;
//     return 0;
// }


// //O(min(a,b)) time complexity


// //gcd calculator using Euclidean algorithm


// #include <iostream>
// using namespace std;
// int main() {
//     int a, b;
//     cin >> a >> b; 
//     while (a>0 && b>0){
//         if (a>b){
//             a=a%b;
//         }
//         else{
//             b=b%a;
//         } 
//         if (a==0){
//             cout<<"The GCD is "<<b<<endl;
//         }
//         else if (b==0){
//             cout<<"The GCD is "<<a<<endl;
//         }
//     }
//     return 0;
// }

// //O(log phi {min(a,b)}) time complexity