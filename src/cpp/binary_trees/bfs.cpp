// DFS (Depth-first Search)
// -> 1. Inorder Traversal - left,root,right
// -> 2. Pre-order Traversal - root,left,right
// -> 3. Post-order Traversal - left,right,root

// BFS (Breadth-first Search) - Level Order Traversal


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