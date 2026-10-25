struct Node{
    int data;
    struct Node *left;
    struct Node *right;

    Node (int val){
        data = val;
        left = right = nullptr;
    }
};
// left,root,right

#include <iostream>
using namespace std;

void inorderTraversal(struct Node *root){
    if(root == nullptr) return;

    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

int main() {
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(5);
    inorderTraversal(root);
    return 0;
}