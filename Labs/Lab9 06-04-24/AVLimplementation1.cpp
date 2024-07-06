#include <iostream>
using namespace std;

// Definition for a AVL tree node.
struct TreeNode {
    int val;
    int height;
    int balFac;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), height(0), balFac(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), height(0), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), height(0), left(left), right(right) {}
};

class AVLTree {
private:
    TreeNode* root;
    
    // Helper Functions
    int getHeight(TreeNode* node) {
        if (node == nullptr)
            return -1;
        return node->height;
    }
    int getBalanceFactor(TreeNode* node) {
        if (node == nullptr)
            return 0;
        return getHeight(node->right) - getHeight(node->left);
    }

    // Rotation Operations
    TreeNode* rightRotate(TreeNode* y) {
        TreeNode* x = y->left;
        TreeNode* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

        return x;
    }
    TreeNode* leftRotate(TreeNode* x) {
        TreeNode* y = x->right;
        TreeNode* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

        return y;
    }

    // Insertion Operation
    TreeNode* insertNode(TreeNode* node, int value) {
        if (node == nullptr)
            return new TreeNode(value);

        if (value <= node->val)
            node->left = insertNode(node->left, value);
        else
            node->right = insertNode(node->right, value);

        // Update height of current node
        node->height = 1 + max(getHeight(node->left), getHeight(node->right));

        // Update balance factor
        node->balFac = getBalanceFactor(node);

        // Perform rotations if necessary
        // Left Left Case
        if (node->balFac > 1 && value < node->left->val)
            return rightRotate(node);

        // Right Right Case
        if (node->balFac < -1 && value > node->right->val)
            return leftRotate(node);

        // Left Right Case
        if (node->balFac > 1 && value > node->left->val) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // Right Left Case
        if (node->balFac < -1 && value < node->right->val) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    // Deletion Operation
    TreeNode* treeMinimum(TreeNode* root) {
        while (root && root->left) {
            root = root->left;
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

        // Update height of current node
        root->height = 1 + max(getHeight(root->left), getHeight(root->right));

        // Update balance factor
        root->balFac = getBalanceFactor(root);

        // Perform rotations if necessary
        // Left Left Case
        if (root->balFac > 1 && getBalanceFactor(root->left) >= 0)
            return rightRotate(root);

        // Left Right Case
        if (root->balFac > 1 && getBalanceFactor(root->left) < 0) {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }

        // Right Right Case
        if (root->balFac < -1 && getBalanceFactor(root->right) <= 0)
            return leftRotate(root);

        // Right Left Case
        if (root->balFac < -1 && getBalanceFactor(root->right) > 0) {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        return root;
    }

    // Search Operation
    TreeNode* searchNode(TreeNode* node, int key) {
        if (node == nullptr || node->val == key)
            return node;

        if (key < node->val)
            return searchNode(node->left, key);

        return searchNode(node->right, key);
    }

    // Inorder traversal to print the tree
    void inorderTraversal(TreeNode* root) {
        if (root == nullptr)
            return;

        inorderTraversal(root->left);
        cout << root->val << " ";
        inorderTraversal(root->right);
    }

public:
    // Constructor
    AVLTree() : root(nullptr) {}

    // Insertion
    void insert(int value) {
        root = insertNode(root, value);
    }

    // Deletion
    void remove(int key) {
        root = deleteNode(root, key);
    }

    // Search
    TreeNode* search(int key) {
        return searchNode(root, key);
    }

    // Inorder traversal
    void traverseInorder() {
        inorderTraversal(root);
    }
};

int main() {
    AVLTree tree;

    // Insertion
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(40);
    tree.insert(50);
    tree.insert(25);

    // Printing the AVL tree in inorder traversal
    cout << "Inorder traversal of AVL tree: ";
    tree.traverseInorder();
    cout << endl;

    // Searching for a node
    int keyToSearch = 30;
    TreeNode* searchResult = tree.search(keyToSearch);
    if (searchResult)
        cout << "Node with key " << keyToSearch << " found in the AVL tree." << endl;
    else
        cout << "Node with key " << keyToSearch << " not found in the AVL tree." << endl;

    // Deletion
    int keyToDelete = 20;
    tree.remove(keyToDelete);
    cout << "AVL tree after deleting node with key " << keyToDelete << ":" << endl;
    tree.traverseInorder();

    return 0;
}
