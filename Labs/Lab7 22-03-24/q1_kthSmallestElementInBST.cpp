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

void inOrderWalk(TreeNode *root, int &count, int k, int &a) {
    if (root -> left) {
        inOrderWalk(root -> left, count, k, a);
    }
    count++;
    if (count == k) {a = root -> val;}
    if (root -> right) {
        inOrderWalk(root -> right, count, k, a);
    }
}

int kthSmallest(TreeNode* root, int k) {
    int count = 0; int ans;
    inOrderWalk(root, count, k, ans);
    return ans;
}

int main() {
    TreeNode *a1 = new TreeNode(2);
    TreeNode *a2 = new TreeNode(1, nullptr, a1);
    TreeNode *a3 = new TreeNode(4);
    TreeNode *root = new TreeNode(3, a2, a3);

    // k = 1
    cout << kthSmallest(root, 1);
  return 0;
}