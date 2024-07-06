#include<bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// finds the minimum element in subtree rooted at root
TreeNode* minEle(TreeNode* root) {
    if (!root) {return NULL;}
    while (root -> left != NULL) {root = root -> left;}
    return root;
}

// finds the maximum element in subtree rooted at root
TreeNode* maxEle(TreeNode* root) {
    if (!root) {return NULL;}
    while (root -> right != NULL) {root = root -> right;}
    return root;
}

// checks for every node in-order
void inOrderWalk(TreeNode *root, bool &ans) {
    if (root->left) {
        if ((maxEle(root->left))->val < root->val) {
            inOrderWalk(root->left, ans);
        } else {
            ans = false;
        }
    }
    if (root->right) {
        if ((minEle(root->right))->val > root->val) {
            inOrderWalk(root->right, ans);
        } else {
            ans = 0;
        }
    }
}

bool isValidBST(TreeNode* root) {
    bool ans = true;
    inOrderWalk(root, ans);
    if (ans) {cout << "Valid BST rooted at -> " << root -> val << endl;}
    else {cout << "Invalid BST rooted at -> " << root -> val << endl;}
    return ans;
}

int main() {
    TreeNode *a1 = new TreeNode(2);
    TreeNode *a2 = new TreeNode(1, nullptr, a1);
    TreeNode *a3 = new TreeNode(4);
    TreeNode *a4 = new TreeNode(3, a2, a3);
    TreeNode *a6 = new TreeNode(7);
    TreeNode *a5 = new TreeNode(8, a4, a6);

    isValidBST(a4);
    isValidBST(a5);
  return 0;
}