#include <iostream>
using namespace std;

// Brute force -> convert to binary -> traverse -> if 1 return true else false

// Optimal

bool f1(int N, int i){
    if ((N & (1 << i)) != 0) return true;
    else return false;
}

bool f2(int N, int i){  
    if (((N >> i) & 1) != 0) return true;
    else return false;
}

int main() {
    int N, i;
    cin >> N >> i;
    cout << f1(N,i) << endl << f2(N,i);
    return 0;
}