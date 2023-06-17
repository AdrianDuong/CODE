#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    int height;
};
int max(int a, int b) {
    return (a>b) ? a : b;
}
int height(Node* node) {
    if (node == NULL)
        return 0;
    return node->height;
}
Node* newNode(int data) {
    Node* node = new Node();
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return(node);
}
Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return x;
}
Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    return y;
}
int getBalance(Node* node) {
    if (node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}
Node* insert(Node* node, int data) {
    if (node == NULL)
        return(newNode(data));
    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);
    else
        return node;
    node->height = 1 + max(height(node->left), height(node->right));
    int balance = getBalance(node);
    if (balance > 1 && data < node->left->data)
        return rightRotate(node);
    if (balance < -1 && data > node->right->data)
        return leftRotate(node);
    if (balance > 1 && data > node->left->data) {
        node->left=leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && data < node->right->data) {
        node->right=rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}
void inOrder(Node* root, int x, int& count) {
    if (root != NULL) {
        inOrder(root->left, x, count);
        if (root->data == x)
        count++;
        inOrder(root->right, x, count);
    }
}

int countOccurences(Node* root, int x) {
    int count = 0;
    inOrder(root, x, count);
    return count;
}

int main() {
    Node* root = NULL;
    int n;
    cin >> n;
    int* a = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
    root = insert(root, a[i]);
}
cout << root->data << " ";
cout << endl;
int x;
cin >> x;
int count = countOccurences(root, x);
cout <<count << endl;
return 0;
}