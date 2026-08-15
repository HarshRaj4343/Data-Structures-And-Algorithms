#include <iostream>
#include <vector>
#include <stack>
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

Node *ReversalBruteForce(Node *head)
{
    stack<int> st;
    Node *temp = head;
    while (temp != nullptr)
    {
        st.push(temp->data);
        temp = temp->next;
    }
    Node *temp2 = head;
    while (temp2 != nullptr)
    {
        temp2->data = st.top();
        st.pop();
        temp2 = temp2->next;
    }
    return head;
}

// O(2n) time and O(n) space

Node *ReversalOptimal(Node *head){
    if (head == nullptr || head->next == nullptr) return head;
    Node *last = nullptr;
    Node *current = head;
    while (current != nullptr){
        last = current->prev;
        current->prev = current->next;
        current->next = last;
        current = current->prev;
    }
    Node *newHead = last->prev;
    return newHead;
}
// O(2n) time and O(1) space


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
    temp = ReversalOptimal(temp);
    print(temp);
    return 0;
}
