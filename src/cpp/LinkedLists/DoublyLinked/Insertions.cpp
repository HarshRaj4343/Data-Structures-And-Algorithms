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

Node *InsertAtHead(Node *head, int el)
{
    Node *latestNode = new Node(el, head, nullptr);
    head->prev = latestNode;
    return latestNode;
}

Node *InsertAtTail(Node *head, int el)
{
    Node *tail = head;
    while (tail->next != nullptr)
    {
        tail = tail->next;
    }
    Node *pichla = tail->prev;
    Node *naya = new Node(el, tail, pichla);
    tail->prev = naya;
    pichla->next = naya;
    return head;
}

Node *InsertAtK(Node *head, int el, int k)
{
    if (k == 1)
        return InsertAtHead(head, el);
    int cnt = 0;
    Node *temp = head;
    while (temp != nullptr)
    {
        cnt++;
        if (cnt == k)
            break;
        temp = temp->next;
    }
    Node *pichla = temp->prev;
    Node *naya = new Node(el, temp, pichla);
    temp->prev = naya;
    pichla->next = naya;
    return head;
}

// given node is not equal to head.
void InsertNode(Node *nod, int val){
    Node *pichla = nod->prev;
    Node *newNode = new Node(val, nod, pichla);
    pichla->next = newNode;
    nod->prev = newNode;
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
    // temp = InsertAtHead(temp, 5);
    // temp = InsertAtTail(temp, 5);
    // temp = InsertAtK(temp, 5, 4);
    InsertNode(temp->next->next,100);
    print(temp);
    return 0;
}
