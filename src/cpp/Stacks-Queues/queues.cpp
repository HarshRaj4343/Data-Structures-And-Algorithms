#include <iostream>
#include <vector>
using namespace std;

class Q {
    int q[4];
    int start = -1;
    int end = -1;
    int currSize = 0;
public:
    void push(int x){
        if (currSize == 4) {
            cout << "Queue Overflow";
            return;
        }
        if (currSize == 0) {
            start++;
            end++;
        }
        else {
            end = (end+1)%4;
        }
        q[end] = x;
        currSize += 1;
    }
    void pop(){
        if (currSize == 0) {
            cout << "Nothing to remove!";
            return;
        }
        if (currSize == 1) {
            start = -1;
            end = -1;
        }
        else {
            start = (start+1)%4;        
        }
        currSize -= 1;
    }
    int front(){
        if (currSize == 0) {
            cout << "Nothing to show";
            return -1;
        }
        return q[start];
    }
    int size(){
        return currSize;
    }
};

int main()
{
    Q q;

    // Push elements
    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Front: " << q.front() << endl;
    cout << "Size: " << q.size() << endl;

    // Pop one element
    q.pop();

    cout << "Front after pop: " << q.front() << endl;
    cout << "Size after pop: " << q.size() << endl;

    // Push more elements
    q.push(40);
    q.push(50);

    cout << "Front: " << q.front() << endl;
    cout << "Size: " << q.size() << endl;

    // Queue is full, this should show Overflow
    q.push(60);

    // Remove everything
    q.pop();
    q.pop();
    q.pop();
    q.pop();

    cout << "Size after removing everything: " << q.size() << endl;

    // Try popping from empty queue
    q.pop();

    // Try viewing empty queue
    cout << "Front: " << q.front() << endl;

    return 0;
}