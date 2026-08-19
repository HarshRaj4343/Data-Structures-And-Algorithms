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

void print(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

Node *Brute(Node *head){
    if (head == nullptr || head->next == nullptr) return head;
    int cnt0 = 0;
    int cnt1 = 0;
    int cnt2 = 0;
    Node *temp = head;
    while (temp != nullptr){
        if (temp->data == 0) cnt0++;
        else if (temp->data == 1) cnt1++;
        else cnt2++;
        temp = temp->next;
    }
    temp = head;
    while (temp != nullptr){
        if (cnt0){
            temp->data = 0;
            cnt0 --;
        }
        else if (cnt1){
            temp->data = 1;
            cnt1 --;
        }
        else{
            temp->data = 2;
            cnt2 --;
        }
        temp = temp->next;
    }
    return head;
}

Node *Optimal(Node *head){
    if (head == nullptr || head->next == nullptr) return head;
    Node *ZeroHead = new Node(-1);
    Node *OneHead = new Node(-1);
    Node *TwoHead = new Node(-1);
    Node *temp0 = ZeroHead;
    Node *temp1 = OneHead;
    Node *temp2 = TwoHead;
    
    Node *temp = head;
    while (temp != nullptr){
        if (temp->data == 0){
            temp0->next = temp;
            temp0 = temp0->next;
        }
        else if (temp->data == 1){
            temp1->next = temp;
            temp1 = temp1->next;
        }
        else {
            temp2->next = temp;
            temp2 = temp2->next;
        }
        temp = temp->next;
    }

    ZeroHead->next = OneHead->next ? (OneHead->next) : (TwoHead->next);
    OneHead->next = TwoHead->next;
    TwoHead->next = nullptr;

    Node *NewHead = ZeroHead->next;
    delete ZeroHead;
    delete OneHead;
    delete TwoHead;
    return NewHead;
}

int main()
{
    int n;
    cin >> n;

    vector<int> v1;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v1.emplace_back(x);
    }

    Node *temp1 = convertArrayToLinkedList(v1);
    Node *result = Optimal(temp1);
    print(result);
    return 0;
}
