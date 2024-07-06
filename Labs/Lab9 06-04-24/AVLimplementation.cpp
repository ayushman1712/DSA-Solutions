#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    int height;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), height(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), height(0), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), height(0), left(left), right(right) {}
};

int getHeight(TreeNode *node)
{
    if (node == nullptr)
        return -1;
    return node->height;
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

TreeNode *rightRotate(TreeNode *y)
{
    TreeNode *x = y->left;
    TreeNode *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

TreeNode *leftRotate(TreeNode *x)
{
    TreeNode *y = x->right;
    TreeNode *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

TreeNode *insertNode(TreeNode *node, int value)
{
    if (node == nullptr)
        return new TreeNode(value);

    if (value < node->val)
        node->left = insertNode(node->left, value);
    else if (value > node->val)
        node->right = insertNode(node->right, value);
    else
        return node;

    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    int balance = getHeight(node->left) - getHeight(node->right);

    if (balance > 1 && value < node->left->val)
        return rightRotate(node);

    if (balance < -1 && value > node->right->val)
        return leftRotate(node);

    if (balance > 1 && value > node->left->val)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && value < node->right->val)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

TreeNode *treeMinimum(TreeNode *root)
{
    while (root && root->left)
    {
        root = root->left;
    }
    return root;
}

TreeNode *deleteNode(TreeNode *root, int key)
{
    if (!root)
        return root;

    if (key < root->val)
        root->left = deleteNode(root->left, key);
    else if (key > root->val)
        root->right = deleteNode(root->right, key);
    else
    {
        if (!root->left)
        {
            TreeNode *temp = root->right;
            delete root;
            return temp;
        }
        else if (!root->right)
        {
            TreeNode *temp = root->left;
            delete root;
            return temp;
        }

        TreeNode *successor = treeMinimum(root->right);
        root->val = successor->val;
        root->right = deleteNode(root->right, successor->val);
    }

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    int balance = getHeight(root->left) - getHeight(root->right);

    if (balance > 1 && getHeight(root->left->left) >= getHeight(root->left->right))
        return rightRotate(root);

    if (balance > 1 && getHeight(root->left->left) < getHeight(root->left->right))
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && getHeight(root->right->right) >= getHeight(root->right->left))
        return leftRotate(root);

    if (balance < -1 && getHeight(root->right->right) < getHeight(root->right->left))
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

TreeNode *searchNode(TreeNode *node, int key)
{
    if (node == nullptr || node->val == key)
        return node;

    if (key < node->val)
        return searchNode(node->left, key);

    return searchNode(node->right, key);
}

void inorderTraversal(TreeNode *root)
{
    if (root == nullptr)
        return;

    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}

int main()
{
    TreeNode *root = nullptr;

    root = insertNode(root, 10);
    root = insertNode(root, 20);
    root = insertNode(root, 30);
    root = insertNode(root, 40);
    root = insertNode(root, 50);
    root = insertNode(root, 25);

    cout << "Inorder traversal of AVL tree: ";
    inorderTraversal(root);
    cout << endl;

    int keyToSearch = 30;
    TreeNode *searchResult = searchNode(root, keyToSearch);
    if (searchResult)
        cout << "Node with key " << keyToSearch << " found in the AVL tree." << endl;
    else
        cout << "Node with key " << keyToSearch << " not found in the AVL tree." << endl;

    int keyToDelete = 20;
    root = deleteNode(root, keyToDelete);
    cout << "AVL tree after deleting node with key " << keyToDelete << ":" << endl;
    cout << "Inorder traversal: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}
