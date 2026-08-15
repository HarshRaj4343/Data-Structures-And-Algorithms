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

Node *Add2Numbers(Node *head1, Node *head2)
{
    Node *ty1 = head1;
    Node *ty2 = head2;
    int carry = 0;
    Node *DummyNode = new Node(-1);
    Node *current = DummyNode;
    while (ty1 != nullptr || ty2 != nullptr)
    {
        int sum = carry;
        if (ty1 != nullptr)
            sum += ty1->data;
        if (ty2 != nullptr)
            sum += ty2->data;
        Node *naya = new Node(sum % 10);
        carry = sum / 10;
        current->next = naya;
        current = current->next;

        if (ty1 != nullptr)
            ty1 = ty1->next;
        if (ty2 != nullptr)
            ty2 = ty2->next;
    }
    if (carry != 0)
    {
        Node *naya = new Node(carry);
        current->next = naya;
    }
    return DummyNode->next;
}

void print(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> v1;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v1.emplace_back(x);
    }

    vector<int> v2;
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        v2.emplace_back(x);
    }

    Node *temp1 = convertArrayToLinkedList(v1);
    Node *temp2 = convertArrayToLinkedList(v2);
    Node *result = Add2Numbers(temp1, temp2);
    print(result);
    return 0;
}
