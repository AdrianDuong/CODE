#include <bits/stdc++.h>
using namespace std;

struct Node 
{
    int left, right;
};

bool isFullBinaryTree(Node tree[], int root, int depth, int& height;) {
    if (root == -1) {
        height = depth;
        return true;
    }
    int leftHeight, rightHeight;
    bool leftIsFull = isFullBinaryTree(tree, tree[root].left, depth + 1, leftHeight);
    bool rightIsFull = isFullBinaryTree(tree, tree[root].right, depth + 1, rightHeight);
    height = max(leftHeight, rightHeight);
    if (leftHeight == rightHeight && leftIsFull && rightIsFull) {
        return true;
    }
    return false;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Node tree[n];
        for (int i = 0; i < n; i++) {
            int u, v;
            char c;
            cin >> u >> v >> c;
            if (c == 'L') {
                tree[u].left = v;
            } else {
                tree[u].right = v;
            }
        }
        int height;
        if (isFullBinaryTree(tree, 0, 0, height)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}
