// #include <iostream>
// using namespace std;
// int main() {
//     int N;
//     cin>>N;
//     for (int i=1; i<=N; i++){
//         for (int j=1; j<=N; j++){
//             cout<<"* ";
//         }
//         cout<<endl;
//     }
//     return 0;
// }



// #include <iostream>
// using namespace std;
// int main() {
//     int N;
//     cin>>N;
//     for (int i=1; i<=N; i++){
//         for (int j=1; j<=i; j++){
//             cout<<"* ";
//         }
//         cout<<endl;
//     }
//     return 0;
// }



// #include <iostream>
// using namespace std;
// int main() {
//     int N;
//     cin>>N;
//     for (int i=1; i<=N; i++){
//         for (int j=1; j<=i; j++){
//             cout<<j<<" ";
//         }
//         cout<<endl;
//     }
//     return 0;
// }



// #include <iostream>
// using namespace std;
// int main() {
//     int N;
//     cin>>N;
//     for (int i=1; i<=N; i++){
//         for (int j=1; j<=i; j++){
//             cout<<i<<" ";
//         }
//         cout<<endl;
//     }
//     return 0;
// }



// #include <iostream>
// using namespace std;
// int main() {
//     int N;
//     cin>>N;
//     for (int i=N; i>=1; i--){
//         for (int j=1; j<=i; j++){
//             cout<<"* ";
//         }
//         cout<<endl;
//     }
//     return 0;
// }



// #include <iostream>
// using namespace std;
// int main() {
//     int N;
//     cin>>N;
//     for (int i=N; i>=1; i--){
//         for (int j=1; j<=i; j++){
//             cout<<j<<" ";
//         }
//         cout<<endl;
//     }
//     return 0;
// }



// #include <iostream>
// using namespace std;
// int main() {
//     int N;
//     cin>>N;
//     for (int i=1; i<=N; i++){
//         //space1
//         for (int j=1; j<=N-i; j++){
//             cout<<" ";
//         }
//         //star
//         for (int j=1; j<=2*i-1; j++){
//             cout<<"*";
//         }
//         //space2
//         for (int j=1; j<=N-i; j++){
//             cout<<" ";
//         }
//         cout<<endl;
//     }
//     return 0;
// }



// #include <iostream>
// using namespace std;
// int main() {
//     int N;
//     cin>>N;
//     for (int i=N; i>=1; i--){
//         //space1
//         for (int j=1; j<=N-i; j++){
//             cout<<" ";
//         }
//         //star
//         for (int j=1; j<=2*i-1; j++){
//             cout<<"*";
//         }
//         //space2
//         for (int j=1; j<=N-i; j++){
//             cout<<" ";
//         }
//         cout<<endl;
//     }
//     return 0;
// }



// #include <iostream>
// using namespace std;
// int main() {
//     int N;
//     cin>>N;
//     for (int i=1; i<=N/2; i++){
//         //space1
//         for (int j=1; j<=(N/2)-i; j++){
//             cout<<" ";
//         }
//         //star
//         for (int j=1; j<=2*i-1; j++){
//             cout<<"*";
//         }
//         //space2
//         for (int j=1; j<=(N/2)-i; j++){
//             cout<<" ";
//         }
//         cout<<endl;
//     }
//     for (int i=N/2; i>=1; i--){
//         //space1
//         for (int j=1; j<=(N/2)-i; j++){
//             cout<<" ";
//         }
//         //star
//         for (int j=1; j<=2*i-1; j++){
//             cout<<"*";
//         }
//         //space2
//         for (int j=1; j<=(N/2)-i; j++){
//             cout<<" ";
//         }
//         cout<<endl;
//     }
//     return 0;
// }



// #include <iostream>
// using namespace std;
// int main() {
//     int N;
//     cin>>N;
//     if (N%2!=0){
//         for (int i=1; i<=(N/2+1); i++){
//             for (int j=1; j<=i; j++){
//                 cout<<"* ";
//             }
//             cout<<endl;
//         }
//         for (int i=N/2; i>=1; i--){
//             for (int j=1; j<=i; j++){
//                 cout<<"* ";
//             }
//             cout<<endl;
//         }



//     }
//     else;
//     return 0;
// }



// #include <iostream>
// using namespace std;
// int main() {
//     int N;
//     cin>>N;
//     for (int i=1; i<=N; i++){
//         for (int j=1; j<=i; j++){
//             if ((i+j)%2==0){
//                 cout<<"1 ";
//             }
//             else {
//                 cout<<"0 ";
//             }
//         }
//         cout<<endl;
//     }
//     return 0;
// }




// #include <iostream>
// using namespace std;
// int main() {
//     int N;
//     cin>>N;
//     for (int i=1; i<=N; i++){
//         //numbers
//         for (int j=1; j<=i; j++){
//             cout<<j;
//         }
//         //space
//         for (int j=1; j<=2*(N-i); j++){
//             cout<<" ";
//         }
//         //numbers in mirrored format
//         // a good technique
//         for (int j=i; j>=1; j--) {
//             cout<<j;
//         }
//         cout<<endl;
//     }
//     return 0;
// }



// a new approach
// #include <iostream>
// using namespace std;
// int main() {
//     int N;
//     cin>>N;
//     int num=1; 
//     for (int i=1; i<=N; i++){
//         for (int j=1; j<=i; j++){
//             cout<<num<<" ";
//             num++;
//         }
//         cout<<endl;
//     }
//     return 0;
// }



// #include <iostream>
// using namespace std;
// int main() {
//     char ch='A';
//     cout<<(int)ch;  // this is how typecasting is done in cpp
//     return 0;
// }




// #include <iostream>
// using namespace std;
// int main() {
//     int N;
//     cin>>N;
//     char ch = 'A';
//     for (int i=1; i<=N; i++){
//         for (int j=1; j<=i; j++){
//             cout<<ch<<" ";
//             ch++;
//         }
//         cout<<endl;
//     }
//     return 0;
// }




// #include <iostream>
// using namespace std;
// int main() {
//     int N;
//     cin>>N;
//     char ch = 'A';
//     for (int i=1; i<=N; i++){
//         for (int j=1; j<=i; j++){
//             cout<<ch<<" ";
//         }
//         ch++;
//         cout<<endl;
//     }
//     return 0;
// }




// #include <iostream>
// using namespace std;
// int main() {
//     int N;
//     cin>>N;
//     char ch = '@';
//     for (int i=1; i<=N; i++){
//         for (int j=1; j<=i; j++){
//             cout<<static_cast<char>(ch+j)<<" "; // to convert from ascii numbers to chars
//         }
//         cout<<endl;
//     }
//     return 0;
// }



// #include <iostream>
// using namespace std;
// int main() {
//     int N;
//     cin>>N;
//     char ch = '@';
//     for (int i=N; i>=1; i--){
//         for (int j=1; j<=i; j++){
//             cout<<static_cast<char>(ch+j)<<" "; // to convert from ascii numbers to chars
//         }
//         cout<<endl;
//     }
//     return 0;
// }



// #include <iostream>
// using namespace std;
// int main() {
//     int N;
//     cin>>N;
//     for (int i=1; i<=N; i++){
//         for (int j=1; j<=N-i; j++){
//             cout<<" ";
//         }
//         char ch='A';
//         for (int j=1; j<=i; j++){
//             cout<<ch;
//             ch++;
//         }
//         ch-=2; // remember to do this step....one of the most crucial step it is.
//         for (int j=1; j<i; j++){
//             cout<<ch;
//             ch--;
//         }
//         cout<<endl;
//     }
//     return 0;
// }



// a good problem
// #include <iostream>
// using namespace std;
// int main() {
//     int N;
//     cin>>N;
//     for (int i=1; i<=N; i++){
//         for (char ch =('A')+N-i ; ch<='A'+(N-1); ch++){
//             cout<<ch<<" ";
//         }
//         cout<<endl;
//     }
//     return 0;
// }



// //  A VERY IMPORTANT ONE
// #include <iostream>
// using namespace std;
// int main() {
//     int N;
//     cin >> N;

//     for (int i = N / 2; i >= 1; i--) {
//         // Left stars
//         for (int j = 1; j <= i; j++) {
//             cout << "*";
//         }

//         // Middle spaces (this part mirrors horizontally).  MOST IMPORTANT PART
//         for (int j = 1; j <= 2 * ((N / 2) - i); j++) {
//             cout << " ";
//         }

//         // Right stars
//         for (int j = 1; j <= i; j++) {
//             cout << "*";
//         }

//         cout << endl;
//     }
//     for (int i=1; i<=N/2; i++){
//         //left stars
//         for (int j=1; j<=i; j++){
//             cout<<"*";
//         }
//         //spaces
//         for (int j = 1; j <= 2 * ((N / 2) - i); j++) {
//             cout << " ";
//         }

//         // Right stars
//         for (int j = 1; j <= i; j++) {
//             cout << "*";
//         }
//         cout<<endl;
//     }

//     return 0;
// }



// #include <iostream>
// using namespace std;
// int main() {
//     int N;
//     cin>>N;
//     for (int i=1; i<=N/2; i++){
//         //stars
//         for (int j=1; j<=i; j++){
//             cout<<"*";
//         }
//         //spaces1
//         for (int j=1; j<=(N/2)-i; j++){
//             cout<<" ";
//         }
//         //spaces2
//         for (int j=1; j<=(N/2)-i; j++){
//             cout<<" ";
//         }
//         //stars
//         for (int j=1; j<=i; j++){
//             cout<<"*";
//         }
//         cout<<endl;
//     }
//     for (int i=N/2-1; i>=1; i--){
//         //stars
//         for (int j=1; j<=i; j++){
//             cout<<"*";
//         }
//         //spaces1
//         for (int j=1; j<=(N/2)-i; j++){
//             cout<<" ";
//         }
//         //spaces2
//         for (int j=1; j<=(N/2)-i; j++){
//             cout<<" ";
//         }
//         //stars
//         for (int j=1; j<=i; j++){
//             cout<<"*";
//         }
//         cout<<endl;
//     }
//     return 0;
// }




// #include <iostream>
// using namespace std;
// int main() {
//     int N;
//     cin>>N;
//     for (int i=1; i<=N; i++){
//         for (int j=1; j<=N; j++){
//             if (i==1 || j==1 || i==N || j==N) cout<<"*";  // || represents OR.
//             else cout<<" ";
//         }
//         cout<<endl;
//     }
//     return 0;
// }



// #include <iostream>
// using namespace std;

// int main() {
//     int N;
//     cin >> N;
//     int size = 2 * N - 1; 
//     for (int i = 1; i <= size; i++) {
//         for (int j = 1; j <= size; j++) {
//             int top = i - 1;
//             int left = j - 1;
//             int right = size - j;
//             int bottom = size - i;

//             // find minimum distance from any border
//             int minDist = min(min(top, bottom), min(left, right));
//             cout << N - minDist << " ";
//         }
//         cout << endl;
//     }
//     return 0;
// }
