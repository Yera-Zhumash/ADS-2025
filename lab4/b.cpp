#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node *left, *right;
    Node(int v) : val(v), left(nullptr), right(nullptr) {}
};


Node* insert(Node* root, int x) {
    if (!root) return new Node(x);
    if (x < root->val) root->left = insert(root->left, x);
    else if (x > root->val) root->right = insert(root->right, x);
    return root;
}


Node* findNode(Node* root, int x) {
    if (!root) return nullptr;
    if (root->val == x) return root;
    if (x < root->val) return findNode(root->left, x);
    else return findNode(root->right, x);
}


int subtreeSize(Node* root) {
    if (!root) return 0;
    return 1 + subtreeSize(root->left) + subtreeSize(root->right);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    Node* root = nullptr;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        root = insert(root, x);
    }

    int target;
    cin >> target;

    Node* node = findNode(root, target);
    cout << subtreeSize(node) << "\n";

    return 0;
}
