#include <iostream>
using namespace std;

int f2(int N){
    int cnt = 0;
    while (N!=0){
        N = N & (N-1);
        cnt ++;
    }
    return cnt;
}

int f1(int start, int goal)
{
    int x = start^goal;
    return f2(x);
}
// tc = o(31) worst case

int main()
{
    int start, goal;
    cin >> start >> goal;
    cout << f1(start,goal) << endl;
    return 0;
}