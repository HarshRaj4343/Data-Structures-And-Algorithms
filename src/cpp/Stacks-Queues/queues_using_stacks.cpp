#include <iostream>
#include <vector>
#include <stack>
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
class Q
{
    stack<int> st1;
    stack<int> st2;

public:
    void push(int x)
    {
        // Move everything from st1 to st2
        while (!st1.empty())
        {
            st2.push(st1.top());
            st1.pop();
        }

        // Insert new element
        st1.push(x);

        // Move everything back
        while (!st2.empty())
        {
            st1.push(st2.top());
            st2.pop();
        }
    }

    void pop()
    {
        if (st1.empty())
        {
            cout << "Queue is empty\n";
            return;
        }

        st1.pop();
    }

    int front()
    {
        if (st1.empty())
        {
            cout << "Queue is empty\n";
            return -1;
        }

        return st1.top();
    }

    bool empty()
    {
        return st1.empty();
    }
};

// Approach 2

class Queue
{
    stack<int> st1;
    stack<int> st2;
public:
    void push(int x)
    {
        st1.push(x);
    }

    void pop()
    {
        if (st2.empty())
        {
            while (!st1.empty())
            {
                st2.push(st1.top());
                st1.pop();
            }
        }

        if (!st2.empty())
        {
            st2.pop();
        }
        else
        {
            cout << "Queue is empty\n";
        }
    }

    int front()
    {
        if (st2.empty())
        {
            while (!st1.empty())
            {
                st2.push(st1.top());
                st1.pop();
            }
        }

        if (!st2.empty())
        {
            return st2.top();
        }
        else
        {
            cout << "Queue is empty\n";
            return -1;
        }
    }

    bool empty()
    {
        return st1.empty() && st2.empty();
    }
};





int main()
{
    int n;
    cin >> n;

    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.emplace_back(x);
    }

    Node *head = convertArrayToLinkedList(v);

    return 0;
}
