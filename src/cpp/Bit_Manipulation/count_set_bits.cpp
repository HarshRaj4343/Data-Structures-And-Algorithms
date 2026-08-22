#include <iostream>
using namespace std;

int f1(int N){
    int cnt = 0;
    while (N > 1){
        cnt += N&1;
        N = N >> 1;
    }
    if (N == 1) cnt++;
    return cnt;
}

// this method is very faster -> used in cp

// another builtin fxn -> __builtin_popcount(n)

int f2(int N){
    int cnt = 0;
    while (N!=0){
        N = N & (N-1);
        cnt ++;
    }
    return cnt;
}

// tc = O(no. of set bits) -> worst case (O(31))

// dbt - why 31?

int main() {
    int N;
    cin >> N;
    cout << f1(N) << endl << f2(N);
    return 0;
}   
