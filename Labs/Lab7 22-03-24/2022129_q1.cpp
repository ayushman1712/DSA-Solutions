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
    // cout << root->val << " ";
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

void BSTGenerator(TreeNode *&root, int k) {
    if (!root) {
        TreeNode *temp = new TreeNode(k);
        root = temp;
    }
    else if (root -> val > k) {
        TreeNode *temp = new TreeNode(k);
        BSTGenerator(root -> left, k);
    } else {
        TreeNode *temp = new TreeNode(k);
        BSTGenerator(root -> right, k);
    }

}

int main() {
    int size = 0; cout << "Enter number of Nodes including NULL values in between :\n";
    cin >> size;
    int huh = size;
    TreeNode *root = NULL;
    while (size > 0) {
        size--;
        cout << "Enter element (use -1 for NULL) : \n";
        int temp = 0; cin >> temp;
        if (temp != -1)  {
            BSTGenerator(root,temp);
        }
    }

    cout << endl << kthSmallest(root, 4);
    return 0;
}