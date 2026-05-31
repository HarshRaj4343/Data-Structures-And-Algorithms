// #include <iostream>
// using namespace std;
// void nameprinter(int n, int count=1){
//     if (count>n) return;
//     cout<<"Harsh"<<endl;
//     nameprinter(n,count+1);
// }
// int main() {
//     int n;
//     cin>>n;
//     nameprinter(n);
//     return 0;
// }



// #include <iostream>
// using namespace std;
// void printer(int n, int count=1){
//     if (count>n) return;
//     cout<<count<<endl;
//     printer(n,count+1); //not count++ as it directly alters the value of count.
// }
// int main() {
//     int n;
//     cin>>n;
//     printer(n);
//     return 0;
// }




// #include <iostream>
// using namespace std;
// void reverseprinter(int n, int count){
//     if (count<1) return;
//     cout<<count<<endl;
//     reverseprinter(n,count-1);
// }
// int main() {
//     int n;
//     cin>>n;
//     reverseprinter(n,n);
//     return 0;
// }



// //printing 1 to n using backtracking

// #include <iostream>
// using namespace std;
// void printer(int n, int count){
//     if (count<1) return;
//     printer(n, count-1);
//     cout<<count<<endl;
// }
// int main(){
//     int n;
//     cin>>n;
//     printer(n,n);
//     return 0;
// }


//printing n to 1 using backtracking

// #include <iostream>
// using namespace std;
// void printer(int n, int count=1){
//     if (count>n) return;
//     printer(n,count+1);
//     cout<<count<<endl;
// }
// int main() {
//     int n;
//     cin>>n;
//     printer(n);
//     return 0;
// }


//parameterised way of summing n natural numbers

// #include <iostream>
// using namespace std;
// void summer(int n, int sum=0){
//     if (n<1){
//         cout<<sum<<endl;
//         return;
//     }
//     sum+=n;
//     summer(n-1, sum);
// }
// int main() {
//     int n;
//     cin>>n;
//     summer(n);
//     return 0;
// }

//functional recursion

// #include <iostream>
// using namespace std;
// int summer(int n){ // int instead of void because we are returning an integer value
//     if (n==0) return 0;
//     return n + summer(n-1);
// }
// int main() {
//     int n;
//     cin>>n;
//     cout<<summer(n)<<endl;
//     return 0;
// }

//factorial of a number using functional recursion


// #include <iostream>
// using namespace std;
// int factorial(int n){
//     if (n==0 || n==1) return 1;
//     return n*factorial(n-1);
// }
// int main() {
//     int n;
//     cin>>n;
//     cout<<factorial(n)<<endl;
//     return 0;
// }

// factorial of a number using parameterised recursion


// #include <iostream>
// using namespace std;
// void factorial(int n, int ans=1){
//     if (n==0){
//         cout<<ans<<endl;
//         return;
//     }
//     ans*=n;
//     factorial(n-1, ans);
// }
// int main() {
//     int n;
//     cin>>n;
//     factorial(n);
//     return 0;
// }


// fibonacci series using parameterised recursion

// #include <iostream>
// using namespace std;
// void fibonacci(int n, int a=0, int b=1){
//     if (n==0) return;
//     cout<<a<<endl;
//     fibonacci(n-1, b, a+b);
// }
// int main() {
//     int n;
//     cin>>n;
//     fibonacci(n);
//     return 0;
// }

//multiple recursion calls for fibonacci series

// #include <iostream>
// using namespace std;
// int fibonacci(int n){
//     if (n==0){
//         return 0;
//     }
//     if (n==1){
//         return 1;
//     }
//     return fibonacci(n-1) + fibonacci(n-2);
// }
// int main() {
//     int n;
//     cin>>n;
//     for (int i=0;i<n;i++){
//         cout<<fibonacci(i)<<endl;
//     }
//     return 0;
// }

// time complexity: O(2^n)

// reverse an array using recursion

// #include <iostream>
// using namespace std;
// void reverseArray(int arr[], int start, int end){
//     if (start >= end) return; // base case
//     swap(arr[start], arr[end]);
//     reverseArray(arr, start + 1, end - 1);
// }

// int main(){
//     int arr[] = {1, 2, 3, 4, 5};
//     int n = 5;
//     reverseArray(arr, 0, n - 1);
//     for (int i = 0; i < n; i++){
//         cout << arr[i] << " ";
//     }
//     return 0;
// }


//using single pointer to reverse an array

// #include <iostream>
// using namespace std;
// void reverseArray(int arr[], int i, int n){
//     if (i>=n/2) return;
//     swap(arr[i], arr[n-i-1]);
//     reverseArray(arr, i + 1, n);
// }
// int main() {
//     int arr[]={1,2,3,4,5};
//     int n=5;
//     reverseArray(arr,0,n);
//     for (int i=0;i<n;i++){
//         cout<<arr[i]<<" ";
//     }
//     cout<<endl;
//     return 0;
// }


//checking a palindrome using recursion

// #include <iostream>
// using namespace std;

// bool isPalindrome(int arr[], int start, int end) {
//     if (start >= end) return true; 
//     if (arr[start] != arr[end]) return false;
//     return isPalindrome(arr, start + 1, end - 1);
// }

// int main() {
//     int arr[] = {1, 2, 3, 2, 1};
//     int n = 5;

//     if (isPalindrome(arr, 0, n - 1))
//         cout << "The array is a palindrome." << endl;
//     else
//         cout << "The array is not a palindrome." << endl;
//     return 0;
// }
