#include <iostream>
using namespace std;

// Stacks are LIFO
// Queues are FIFO

class Stack {
    int st[10];
    int top = -1;

public:
    void push(int x) {
        if (top >= 9) {
            cout << "Stack Overflow" << endl;
            return;
        }
        top++;
        st[top] = x;
    }

    void peek() {
        if (top == -1) {
            cout << "Stack is Empty" << endl;
            return;
        }
        cout << st[top] << endl;
    }

    void pop() {
        if (top == -1) {
            cout << "Stack is Empty" << endl;
            return;
        }
        top--;
    }

    void size() {
        cout << top + 1 << endl;
    }
};



int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);

    s.peek(); 
    s.pop();
    s.peek();  

    s.size();  

    return 0;
}


