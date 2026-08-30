#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

public:
    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }

public:
    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};

class Stacks
{
    Node *top = nullptr;
    int size = 0;
public:
    void push(int x)
    {
        Node *temp = new Node(x);
        temp->next = top;
        top = temp;
        size++;
    }

    void pop()
    {
        if (top == nullptr)
        {
            cout << "Stack is Empty" << endl;
            return;
        }
        Node *temp = top;
        top = top->next;
        delete temp;
        size--;
    }

    int peek()
    {
        if (top == nullptr)
        {
            cout << "Stack is Empty" << endl;
            return -1;
        }
        return top->data;
    }

    int getSize()
    {
        return size;
    }
};

Node *convertArrayToLinkedList(vector<int> v)
{
    Node *head = new Node(v[0], nullptr);
    Node *mover = head;

    for (int i = 1; i < v.size(); i++)
    {
        Node *temp = new Node(v[i], nullptr);
        mover->next = temp;
        mover = temp;
    }

    return head;
}
int main()
{
    Stacks s;

    // Push elements
    s.push(10);
    s.push(20);
    s.push(30);

    // Check top element
    cout << "Top: " << s.peek() << endl;

    // Check size
    cout << "Size: " << s.getSize() << endl;

    // Pop
    s.pop();

    cout << "Top after pop: " << s.peek() << endl;
    cout << "Size after pop: " << s.getSize() << endl;

    // Pop again
    s.pop();

    cout << "Top after pop: " << s.peek() << endl;
    cout << "Size: " << s.getSize() << endl;

    // Pop last element
    s.pop();

    // Try popping from empty stack
    s.pop();

    // Try peeking at empty stack
    cout << "Top: " << s.peek() << endl;

    return 0;
}