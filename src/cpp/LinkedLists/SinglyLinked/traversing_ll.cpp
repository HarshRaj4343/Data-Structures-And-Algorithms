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
        mover = temp; // or mover = mover->next;
    }
    return head;
}

// finding length of a ll

int findLength(Node *head)
{
    int length = 0;
    Node *temp = head;
    while (temp != nullptr)
    {
        length++;
        temp = temp->next;
    }
    return length;
}

// search an element in a ll

bool searchElement(Node *head, int val)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        if (temp->data == val)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}
// tc = o(n) worst case, for avg -> o(n/2) = o(n)

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
    // Never ever, tamper the head.
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    cout << findLength(head) << endl;
    int val;
    cin >> val;
    cout << searchElement(head, val) << endl;
    return 0;
}