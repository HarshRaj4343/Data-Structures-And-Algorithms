#include <iostream>
using namespace std;

// Brute force -> convert to binary -> traverse -> if 1 return 1 else modify to 1

// Optimal

int f1(int N, int i){
    return (((1<<i) | N));
}

int main() {
    int N, i;
    cin >> N >> i;
    cout << f1(N,i) << endl;
    return 0;
}   