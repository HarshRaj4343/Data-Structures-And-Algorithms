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

Node *deleteNode(Node *head)
{
    if (head == nullptr)
        return head;
    Node *temp = head;
    head = head->next;
    free(temp);  // or delete(temp) -> alternative, java has garbage collector so there is no issue there.
    return head; // writing only this would also suffice but we are not deleting the initial head for now here.
}

Node *deletetail(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return nullptr;
    Node *temp = head;
    while (temp->next->next != nullptr)
    {
        temp = temp->next;
    }
    free(temp);
    temp->next = nullptr;
    return head;
}

Node *deletekelement(Node *head, int k)
{
    if (head == nullptr)
        return nullptr;

    if (k == 0)
    {
        Node *head = deleteNode(head);
        return head;
    }

    Node *temp = head;
    int cnt = 0;

    // Stop at node BEFORE the one we want to delete
    while (temp != nullptr && cnt < k - 1)
    {
        temp = temp->next;
        cnt++;
    }

    // when k is out of range
    if (temp == nullptr || temp->next == nullptr)
        return head;

    Node *toDelete = temp->next;

    temp->next = temp->next->next;

    delete toDelete;

    return head;
}

bool searchElement(Node *head, int val)
{
    Node *temp = head;
    int cnt = 0;
    while (temp != nullptr)
    {
        if (temp->data == val)
        {
            return cnt;
        }
        temp = temp->next;
        cnt++;
    }
    return false;
}

Node *deleteElementValue(Node *head, int k)
{
    if (head == nullptr)
        return nullptr;
    
    if (head->data == k)
    {
        Node *toDelete = head;
        head = head->next;
        delete toDelete;
        return head;
    }

    if (searchElement(head, k) == false)
        return head;

    Node *temp = head;

    while (temp != nullptr && temp->next->data != k)
    {
        temp = temp->next;
    }

    Node *toDelete = temp->next;

    temp->next = temp->next->next;

    delete toDelete;

    return head;
}

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
    head = deleteElementValue(head, 9);
    while (head != nullptr)
    {
        cout << head->data << endl;
        head = head->next;
    }
    return 0;
}
