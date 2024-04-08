#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

Node* insert(Node* root, int value) {
    if (root == nullptr) {
        return createNode(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    return root;
}

bool search(Node* root, int value) {
    if (root == nullptr) {
        return false;
    }
    if (root->data == value) {
        return true;
    } else if (value < root->data) {
        return search(root->left, value);
    } else {
        return search(root->right, value);
    }
}

void inorderTraversal(Node* root) {
    if (root != nullptr) {
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }
}

int main() {
    Node* root = nullptr;
    root = insert(root, 20);
    insert(root, 30);
    insert(root, 10);
    insert(root, 40);
    insert(root, 5);
    insert(root, 60);
    insert(root, 70);
    insert(root, 80);
    insert(root, 78);
    insert(root, 82);

    cout << "Inorder traversal of BST: ";
    inorderTraversal(root);
    cout << endl;

    int searchValue = 4;
    if (search(root, searchValue)) {
        cout << searchValue << " found in the BST." << endl;
    } else {
        cout << searchValue << " not found in the BST." << endl;
    }

    return 0;
}
