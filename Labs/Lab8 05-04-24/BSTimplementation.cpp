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

// 2. Insertion Operation
void insert(TreeNode *&root, int value) {
    if (root == NULL) {root = new TreeNode(value);}
    else if (root -> val <= value) {
        insert(root->right, value);
    } else {
        insert(root->left, value);
    }
}

// 3. Deletion Operation
TreeNode* treeMinimum(TreeNode* root) {
    while (root -> left) {
        root = root -> left;
    }
    return root;
}
TreeNode* deleteNode(TreeNode* root, int key) {
    if (!root)
        return root;

    if (key < root->val)
        root->left = deleteNode(root->left, key);
    else if (key > root->val)
        root->right = deleteNode(root->right, key);
    else {
        if (!root->left) {
            TreeNode* temp = root->right;
            delete root;
            return temp;
        } else if (!root->right) {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }

        TreeNode* successor = treeMinimum(root->right);
        root->val = successor->val;
        root->right = deleteNode(root->right, successor->val);
    }
    return root;
}

// 4. Traversal Operaation
void inOrderWalk(TreeNode *root) {
    // cout << "[ ";
    if (root -> left) {
        inOrderWalk(root -> left);
    }
    cout << root -> val << " ";
    if (root -> right) {
        inOrderWalk(root -> right);
    }
    // cout << "]";
}
void preOrderWalk(TreeNode *root) {
    // cout << "[ ";
    cout << root -> val << " ";
    if (root -> left) {
        preOrderWalk(root -> left);
    }
    if (root -> right) {
        preOrderWalk(root -> right);
    }
    // cout << "]";
}
void postOrderWalk(TreeNode *root) {
    // cout << "[ ";
    if (root -> left) {
        postOrderWalk(root -> left);
    }
    if (root -> right) {
        postOrderWalk(root -> right);
    }
    cout << root -> val << " ";
    // cout << "]";
}

// 5. Height Calculation
int heightBST(TreeNode *root) {
    int h = -1; 
    if (!root) {return h;}
    return (max(heightBST(root -> left) + 1, heightBST(root -> right) + 1));
}

// 6. Number of Nodes Calculation
int countNodes(TreeNode *root) {
    int count = 0;
    if (root -> left) {count += countNodes(root->left);}
    if (root) {count++;}
    if (root -> right) {count += countNodes(root->right);}
    return count;
}


// helper function to generate BST
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

    cout << endl;
    inOrderWalk(root);
    cout << endl;
    insert(root, 5);
    deleteNode(root, 4);
    inOrderWalk(root); cout << endl;
    preOrderWalk(root); cout << endl;
    postOrderWalk(root);cout << endl;
    cout << heightBST(root); cout << endl;
    cout << countNodes(root); cout << endl;
    
    return 0;
}