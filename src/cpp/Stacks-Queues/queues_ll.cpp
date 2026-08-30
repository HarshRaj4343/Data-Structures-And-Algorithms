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

class Q
{
    Node *start = nullptr;
    Node *end = nullptr;
    int currSize = 0;

public:
    void push(int x)
    {
        Node *temp = new Node(x);
        if (start == nullptr)
        {
            start = temp;
            end = temp;
        }
        else
        {
            end->next = temp;
            end = temp;
        }

        currSize++;
    }

    void pop()
    {
        if (start == nullptr)
        {
            cout << "Nothing to pop out!";
            return;
        }

        Node *temp = start;
        start = start->next;

        delete temp;

        currSize--;

        if (start == nullptr)
        {
            end = nullptr;
        }
    }

    int front()
    {
        if (start == nullptr)
        {
            cout << "Nothing to show!";
            return -1;
        }

        return start->data;
    }

    int getSize()
    {
        return currSize;
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
    Q q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);

    cout << "Front: " << q.front() << endl;
    cout << "Size: " << q.getSize() << endl;

    q.pop();
    cout << "After one pop:" << endl;
    cout << "Front: " << q.front() << endl;
    cout << "Size: " << q.getSize() << endl;

    q.pop();
    q.pop();
    q.pop();

    cout << "After popping everything:" << endl;
    cout << "Size: " << q.getSize() << endl;

    q.pop();
    cout << endl;

    cout << "Front: " << q.front() << endl;

    return 0;
}