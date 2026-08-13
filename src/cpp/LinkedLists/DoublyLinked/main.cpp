#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

public:
    Node(int data1, Node *next1, Node *prev1)
    {
        data = data1;
        next = next1;
        prev = prev1;
    }

public:
    Node(int data1)
    {
        data = data1;
        next = nullptr;
        prev = nullptr;
    }
};

Node *convertArrayToLinkedList(vector<int> v)
{
    Node *head = new Node(v[0]);
    Node *prev = head;

    for (int i = 1; i < v.size(); i++)
    {
        Node *temp = new Node(v[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
    }

    return head;
}

void print(Node *head)
{
    while (head != nullptr)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

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

Node *deletehead(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return nullptr;

    Node *temp = head;
    head = head->next;
    head->prev = nullptr;
    temp->next = nullptr;
    free(temp);
    return head;
}

Node *deletetail(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return nullptr;
    Node *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }

    temp->prev->next = nullptr;
    temp->prev = nullptr;
    free(temp);
    return head;
}

// k is between 1 to n

Node *deletek(Node *head, int k)
{
    if (head == nullptr)
        return nullptr;
    Node *temp = head;
    int cnt = 0;
    while (temp != nullptr)
    {
        cnt++;
        if (cnt == k)
            break;
        temp = temp->next;
    }
    Node *prevNode = temp->prev;
    Node *nextNode = temp->next;
    if (prevNode == nullptr && nextNode == nullptr)
    {
        free(temp);
        return nullptr;
    }
    else if (prevNode == nullptr && nextNode != nullptr)
    {
        head = deletehead(head);
        return head;
    }
    else if (prevNode != nullptr && nextNode == nullptr)
    {
        head = deletetail(head);
        return head;
    }
    prevNode->next = nextNode;
    nextNode->prev = prevNode;

    temp->next = nullptr;
    temp->prev = nullptr;
    free(temp);
    return head;
}

// given node is never the head of the dll

void deleteNode(Node *temp)
{
    Node *prev = temp->prev;
    Node *front = temp->next;
    if (front == nullptr)
    {
        prev->next = nullptr;
        free(temp);
        return;
    }
    prev->next = front;
    front->prev = prev;
    temp->next = temp->prev = nullptr;
    free(temp);
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

    Node *temp = convertArrayToLinkedList(v);
    // temp = deletehead(temp);
    // temp = deletetail(temp);
    // temp = deletek(temp, 3);
    deleteNode(temp); // if i say head, then this head will move and will have to make the next element as the node.
    print(temp);
    return 0;
}
