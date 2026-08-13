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

Node *Inserthead(Node *head, int val){
    Node *temp = new Node(val,head);
    return temp;
    // or return new Node(val,head);
}

Node *InsertLast(Node *head, int val)
{
    if (head == nullptr)
        return new Node(val,head);

    Node *temp = head;

    while (temp->next != nullptr)
    {
        temp = temp->next;
    }

    Node *add = new Node(val, nullptr);
    temp->next = add;

    return head;
}

Node *InsertatK(Node *head,int el, int k){
    if (head == nullptr){
        if (k==1) return new Node(el,head);
        else return nullptr;
    }
    if (k==1) {
        Node *temp = new Node(el, head);
        return temp;
    }
    int cnt = 0;
    Node *temp = head;
    while (temp != nullptr){
        cnt++;
        if (cnt == k-1) {
            Node *add = new Node(el,temp);
            add->next = temp->next;
            temp->next = add;
            break;
        }
        temp = temp->next;
    }
    return head;
}

Node *InsertatKelement(Node *head,int el, int val){
    if (head == nullptr){
        return nullptr;
    }
    if (head->data==val) {
        Node *temp = new Node(el, head);
        return temp;
    }
    int cnt = 0;
    Node *temp = head;
    while (temp->next != nullptr){
        cnt++;
        if (temp->next->data == val) {
            Node *add = new Node(el,temp);
            add->next = temp->next;
            temp->next = add;
            break;
        }
        temp = temp->next;
    }
    return head;
}
int main()
{
    int n ,el, val;
    cin >> n >> el >> val;

    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.emplace_back(x);
    }

    Node *head = convertArrayToLinkedList(v);
    head = InsertatK(head,el, val);

    while (head != nullptr)
    {
        cout << head->data << endl;
        head = head->next;
    }

    return 0;
}
