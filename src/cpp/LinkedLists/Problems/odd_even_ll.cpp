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

Node *OddEvenLinkedListBrute(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;
    vector<int> dump;
    Node *temp1 = head;
    while (temp1 != nullptr && temp1->next != nullptr)
    {
        dump.emplace_back(temp1->data);
        temp1 = temp1->next->next;
    }
    if (temp1 != nullptr)
        dump.emplace_back(temp1->data);
    Node *temp2 = head->next;
    while (temp2 != nullptr && temp2->next != nullptr)
    {
        dump.emplace_back(temp2->data);
        temp2 = temp2->next->next;
    }
    if (temp2 != nullptr)
        dump.emplace_back(temp2->data);
    Node *temp3 = head;
    int cnt = 0;
    while (temp3 != nullptr)
    {
        temp3->data = dump[cnt];
        cnt++;
        temp3 = temp3->next;
    }
    return head;
}

// TC = O(2N)
// SC = O(N)

Node* OddEvenLinkedListOptimal(Node* head) {
    if (head == nullptr || head->next == nullptr)
        return head;
    Node* OddTemp = head;
    Node* EvenTemp = head->next;
    Node* EvenNode = head->next;

    while (EvenTemp != nullptr && EvenTemp->next != nullptr) {
        OddTemp->next = OddTemp->next->next;
        OddTemp = OddTemp->next;
        EvenTemp->next = EvenTemp->next->next;
        EvenTemp = EvenTemp->next;
    }

    OddTemp->next = EvenNode;

    return head;
}

// TC = O(N/2) * 2 (due to the computations of oddtemp.next and eventemp.next) = O(N)
// SC = O(1)

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
    Node *result = OddEvenLinkedListOptimal(temp1);
    print(result);
    return 0;
}
