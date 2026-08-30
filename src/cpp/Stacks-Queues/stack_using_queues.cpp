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

class st
{
    queue<int> q;

public:
    void push(int x)
    {
        int len = q.size();
        q.push(x);
        for (int i = 0; i < len; i++)
        {
            q.push(q.front());
            q.pop();
        }
    }
    void pop()
    {
        q.pop();
    }
    int top()
    {
        return q.front();
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
