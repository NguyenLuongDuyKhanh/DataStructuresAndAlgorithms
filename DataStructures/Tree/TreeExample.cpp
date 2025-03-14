#include <iostream>
using namespace std;

// Define the structure for a tree node
struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

// Function to insert a node in the binary tree
TreeNode* insert(TreeNode* root, int value) {
    if (root == nullptr) {
        return new TreeNode(value);
    }

    if (value < root->value) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }

    return root;
}

// Function to print the tree in-order
void inOrderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    inOrderTraversal(root->left);
    cout << root->value << " ";
    inOrderTraversal(root->right);
}

int main() {
    TreeNode* root = nullptr;
    root = insert(root, 10);
    insert(root, 5);
    insert(root, 15);
    insert(root, 3);
    insert(root, 7);
    insert(root, 12);
    insert(root, 18);

    cout << "In-order traversal of the binary tree: ";
    inOrderTraversal(root);
    cout << endl;

    return 0;
}

/*
In this example:

We define a TreeNode structure to represent each node in the tree.
The insert function adds a new node to the tree.
The inOrderTraversal function prints the values of the nodes in in-order sequence.

Feel free to adapt and expand this code to suit your specific needs! If you have any questions or need further assistance, I'm here to help.
*/