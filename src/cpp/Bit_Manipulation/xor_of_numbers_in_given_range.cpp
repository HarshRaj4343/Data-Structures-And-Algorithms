#include <iostream>
using namespace std;

int bruteforce(int N){
    int ans = 0;
    for (int i = 1; i < N; i++) {
        ans = ans^i;
    }
    return ans;
}

int optimal(int N){
    if (N%4 == 0) return N;
    else if (N%4 == 1) return 1;
    else if (N%4 == 2) return N+1;
    else return 0;
}
// tc = o(1)
// sc = o(1)

int optimalv2(int start, int end){
    return optimal(start-1)^optimal(end);
}

int main() {
    int n;
    cin >> n;
    cout << bruteforce(n) << endl;
    cout << optimal(n) << endl;
    return 0;
}