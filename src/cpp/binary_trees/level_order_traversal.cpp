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

vector <vector<int>> levelorderTraversal(struct Node *root){
    vector <vector<int>> ans;
    if (root == nullptr) return ans;
    queue <Node*> q;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        vector<int> level;
        for(int i=0;i<size;i++){
            Node *node = q.front();
            q.pop();
            level.push_back(node->data);
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);    
        }
        ans.push_back(level);
    }
    return ans;
}

// TC = O(N) where N is number of nodes in the tree
// SC = O(N) where N is number of nodes in the tree, in worst case

int main() {
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(5);
    vector <vector<int>> result = levelorderTraversal(root);
    for (const auto& level : result) {
        for (int val : level) {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}