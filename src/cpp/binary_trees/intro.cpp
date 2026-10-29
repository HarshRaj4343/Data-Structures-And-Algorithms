// Full BT -> either has 0 or 2 children for every node
// Complete BT -> all levels should be completely filled except the last level, and the last level has all the nodes on left as possible
// Perfect BT -> all levels are completely filled
// Balanced BT -> height of tree at max log(N) where N is number of nodes in the tree -> height of left and right subtree of every node differs by at most 1
// Degenerate BT -> all nodes have only one child


// Representation of BT in cpp

struct Node{
    int data;
    struct Node *left;
    struct Node *right;

    Node (int val){
        data = val;
        left = right = nullptr;
    }
};

#include <iostream>
using namespace std;

int main() {
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(5);
    return 0;
}