#include <iostream>
using namespace std;

// Brute force -> convert to binary -> traverse -> if 1 return 0 else modify to 1

// Optimal

int f(int N, int i){
    return (N^(1 << i));
}

int main() {
    int N, i;
    cin >> N >> i;
    cout << f(N,i) << endl;
    return 0;
}   