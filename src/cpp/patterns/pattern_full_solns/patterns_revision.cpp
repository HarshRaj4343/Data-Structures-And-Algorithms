// 1

// #include <iostream>
// using namespace std;
// int main() {
//     int n;
//     cin>>n;
//     for (int i=1;i<=n;i++){
//         for (int j=1;j<=n;j++){
//             cout<<"* ";
//         }
//         cout<<endl;
//     }
//     return 0;
// }

// 2

// #include <iostream>
// using namespace std;
// int main() {
//     int n;
//     cin>>n;
//     for (int i=1;i<=n;i++){
//         for (int j=1;j<=i;j++){
//             cout<<"* ";
//         }
//         cout<<endl;
//     }
//     return 0;
// }

// 3

// #include <iostream>
// using namespace std;
// int main() {
//     int n;
//     cin>>n;
//     for (int i=1;i<=n;i++){
//         for (int j=1;j<=i;j++){
//             cout<<j<<" ";
//         }
//         cout<<endl;
//     }
//     return 0;
// }


// 4

// #include <iostream>
// using namespace std;
// int main() {
//     int n;
//     cin>>n;
//     for (int i=1; i<=n; i++){
//         for (int j=1; j<=i; j++){
//             cout<<i<<" ";
//         }
//         cout<<endl;
//     }
//     return 0;
// }


// 5

// #include <iostream>
// using namespace std;
// int main() {
//     int n;
//     cin>>n;
//     for (int i=n;i>=1;i--){
//         for (int j=1;j<=i;j++){
//             cout<<"* ";
//         }
//         cout<<endl;
//     }
//     return 0;
// }


// 6

// #include <iostream>
// using namespace std;
// int main() {
//     int n;
//     cin>>n;
//     for (int i=n;i>=1;i--){
//         for (int j=1;j<=i;j++){
//             cout<<j<<" ";
//         }
//         cout<<endl;
//     }
//     return 0;
// }


// 7

// #include <iostream>
// using namespace std;
// int main() {
//     int n;
//     cin>>n;
//     for (int i=1;i<=n;i++){
//         for (int j=1;j<=n-i;j++){
//             cout<<"  ";
//         }
//         for (int j=1;j<=2*i-1;j++){
//             cout<<"* ";
//         }
//         for (int j=1;j<=n-i;j++){
//             cout<<"  ";
//         }
//         cout<<endl;
//     }
//     return 0;
// }

// 8

// #include <iostream>
// using namespace std;
// int main() {
//     int n;
//     cin>>n;
//     for (int i=1;i<=n;i++){
//         for (int j=1;j<=(i-1);j++){
//             cout<<"  ";
//         }
//         for (int j=1;j<=(2*n-(2*i-1));j++){
//             cout<<"* ";
//         }
//         for (int j=1;j<=(i-1);j++){
//             cout<<"  ";
//         }
//     cout<<endl;
//     }
//     return 0;
// }

// 9

// #include <iostream>
// using namespace std;
// int main() {
//     int n;
//     cin>>n;
//     for (int i=1;i<=n;i++){
//         for (int j=1;j<=n-i;j++){
//             cout<<"  ";
//         }
//         for (int j=1;j<=2*i-1;j++){
//             cout<<"* ";
//         }
//         for (int j=1;j<=n-i;j++){
//             cout<<"  ";
//         }
//         cout<<endl;
//     }
//     for (int i=1;i<=n;i++){
//         for (int j=1;j<=(i-1);j++){
//             cout<<"  ";
//         }
//         for (int j=1;j<=(2*n-(2*i-1));j++){
//             cout<<"* ";
//         }
//         for (int j=1;j<=(i-1);j++){
//             cout<<"  ";
//         }
//         cout<<endl;
//     }
//     return 0;
// }


// 10

// #include <iostream>
// using namespace std;
// int main() {
//     int n;
//     cin>>n;
//     for (int i=1;i<=n;i++){
//         for (int j=1;j<=i;j++){
//             cout<<"* ";
//         }
//         for (int j=1;j<=(n-i);j++){
//             cout<<" ";
//         }
//         cout<<endl;
//     }
//     for (int i=1;i<=n-1;i++){
//         for (int j=1;j<=(n-i);j++){
//             cout<<"* ";
//         }
//         for (int j=1;j<=i;j++){
//             cout<<" ";
//         }
//         cout<<endl;
//     }
    
//     return 0;
// }


// 11

// #include <iostream>
// using namespace std;
// int main() {
//     int n;
//     cin>>n;
//     for (int i=1;i<=n;i++){
//         for (int j=1;j<=i;j++){
//             if ((i+j)%2==0){
//                 cout<<" 1 ";
//             }
//             else {
//                 cout<<" 0 ";
//             }
//         }
//         cout<<endl;
//     }
//     return 0;
// }


// 12

// #include <iostream>
// using namespace std;

// int main() {
//     int n;
//     cin >> n;

//     for (int i = 1; i <= n; i++) {
//         for (int j = 1; j <= i; j++) {
//             cout << j << " ";
//         }
//         for (int j = 1; j <= (n - i); j++) {
//             cout << "  "; 
//         }

//         for (int j = 1; j <= (n - i); j++) {
//             cout << "  "; 
//         }

//         // 3. Right side numbers (Mirror)
//         // This loop goes backwards from i down to 1
//         for (int j = i; j >= 1; j--) {
//             cout << j << " ";
//         }
        
//         cout << endl;
//     }
//     return 0;
// }


// 13
// #include <iostream>
// using namespace std;

// int main() {
//     int n;
//     cin >> n;
//     int count=1;

//     for (int i = 1; i <= n; i++) {
//         for (int j = 1; j <= i; j++) {
//             cout<<count<<' ';
//             count++;
//         }
//         cout << endl;
//     }
//     return 0;
// }


// 14

// #include <iostream>
// using namespace std;
// int main() {
//     int n;
//     cin>>n;
    
//     for (int i=1;i<=n;i++){
//         for (int j=65;j<=65+i-1;j++){
//             cout<<(char)j<<" ";
//         }
//         cout<<endl;
//     }
//     return 0;
// }


// 15

// Just change the behaviour of outer loop 

// #include <iostream>
// using namespace std;
// int main() {
//     int n;
//     cin>>n;
//     for (int i=n;i>=1;i--){
//        for (int j=65;j<=65+i-1;j++){
//             cout<<(char)j<<" ";
//        }
//        cout<<endl;
//     }
//     return 0;
// }


// 16


// #include <iostream>
// using namespace std;
// int main() {
//     int n;
//     cin>>n;
//     for (int i=65;i<65+n;i++){
//         for (int j=1;j<=i-65+1;j++){
//             cout<<(char)i<<" ";
//         }
//         cout<<endl;
//     }
//     return 0;
// }


// 17

// #include <iostream>
// using namespace std;
// int main() {
//     int n;
//     cin>>n;
//     for (int i=1;i<=n;i++){
//         for (int j=1;j<=n-i;j++){
//             cout<<"  ";
//         }
//         for (int j=65;j<=65+i-1;j++){
//             cout<<(char)j<<" ";
//         }
//         for (int j=65+i-2;j>=65;j--){
//             cout<<(char)j<<" ";
//         }
//         cout<<endl;
//     }
//     return 0;
// }


// 18

// #include <iostream>
// using namespace std;
// int main() {
//     int n;
//     cin>>n;
//     for (int i=1;i<=n;i++){
//         for (int j=69-i+1;j<=69;j++){
//             cout<<(char)j<<" ";
//         }
//         cout<<endl;
//     }
//     return 0;
// }


// 19
// #include <iostream>
// using namespace std;

// int main() {
//     int n = 5; 

//     // --- Upper Half ---
//     for (int i = 0; i < n; i++) {
//         // Print left stars
//         // Starts with 5 stars, decreases by 1 each row
//         for (int j = 0; j < n - i; j++) {
//             cout << "*";
//         }

//         // Print spaces
//         // Starts with 0 spaces, increases by 2 each row
//         for (int j = 0; j < 2 * i; j++) {
//             cout << " ";
//         }

//         // Print right stars
//         // Mirror of the left stars
//         for (int j = 0; j < n - i; j++) {
//             cout << "*";
//         }
        
//         // Move to the next line
//         cout << endl;
//     }

//     // --- Lower Half ---
//     for (int i = 0; i < n; i++) {
//         // Print left stars
//         // Starts with 1 star, increases by 1 each row
//         for (int j = 0; j <= i; j++) {
//             cout << "*";
//         }

//         // Print spaces
//         // Starts wide, decreases by 2 each row
//         for (int j = 0; j < 2 * (n - 1 - i); j++) {
//             cout << " ";
//         }

//         // Print right stars
//         for (int j = 0; j <= i; j++) {
//             cout << "*";
//         }
        
//         // Move to the next line
//         cout << endl;
//     }

//     return 0;
// }


// REQUIRES MORE RIGOROUS PRACTICE!