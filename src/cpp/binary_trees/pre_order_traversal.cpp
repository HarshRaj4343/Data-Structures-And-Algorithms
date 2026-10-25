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

void preOrderTraversal(struct Node *root){
    if(root == nullptr) return;

    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}
// TC = O(N) where N is number of nodes in the tree
// SC = O(H) where H is height of the tree, in worst case SC = O(N) for skewed tree and SC = O(logN) for balanced tree
// the space complexity is due to the recursive stack space used in the function calls
int main() {
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(5);
    preOrderTraversal(root);
    return 0;
}