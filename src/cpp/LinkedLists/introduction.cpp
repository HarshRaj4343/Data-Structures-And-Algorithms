#include <iostream>
#include <vector>
using namespace std;

// array is stored in the heap memory at contiguous locations.
// linked list is similar but it does not store at contiguous locations and ll's size can be changed at any moment.

// store the element as well as the next element's memory location
// starting pt of ll - head of ll
// for last element (tail of ll) - next memory address will be stored at "null."

// LL being 1D as we are just storing the next memory address and not the previous one.

/*
{Where is it used?}
{Primarily used in Stacks and Queue}
and in Real life -> {Used in Browsers}
{search -> reddit.com -> a2z -> article}
*/

// Pseudo Code

// struct Node{
//     int data;
//     Node* next;
//     Node(data1,next1){
//         data = data1;
//         next = next1;

//     }
// }

// For declaration

/*
Node x = Node(2, nullptr)
Node *y = &x;

{Simpler Method}
Node* y = new Node(2,nullptr)
*/

struct Node // instead u can also use class but then you will have to make the data and next public as they are private by default in class.
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
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};

/*
{Converting an array into a linked list}
{1,2,3,4,5} -> {1->2->3->4->5->null}
*/

Node* convertArrayToLinkedList(vector<int> v)
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

// tc = O(n) 
// sc = O(n) as we are creating a new linked list and storing it in the heap memory.

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
    // cout << head->next << endl;
    // Node y = Node(v[0], nullptr);
    // cout << y.data << endl;
    cout << head->data << endl;
    return 0;
}


/*
Memory Space for 32 bit systems:-
int -> 4 bytes
Pointer -> 4 bytes
total = 8 bytes
Memory Space for 64 bit systems:-
int -> 4 bytes
Pointer -> 8 bytes
total = 12 bytes
*/