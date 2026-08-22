#include <iostream>
using namespace std;

// Brute force -> convert to binary -> traverse -> if 0 return 0 else modify to 0

// Optimal

int f(int N, int i){
    return (~(1<<2) & N);
}

int main() {
    int N, i;
    cin >> N >> i;
    cout << f(N,i) << endl;
    return 0;
}   