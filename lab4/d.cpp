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

    
    vector<long long> levelSum;
    queue<pair<Node*, int>> q;
    q.push({root, 0});

    while (!q.empty()) {
        auto [node, lvl] = q.front();
        q.pop();

        if (lvl >= (int)levelSum.size())
            levelSum.resize(lvl + 1, 0);

        levelSum[lvl] += node->val;

        if (node->left) q.push({node->left, lvl + 1});
        if (node->right) q.push({node->right, lvl + 1});
    }

    cout << levelSum.size() << "\n";
    for (long long x : levelSum) cout << x << " ";
    cout << "\n";

    return 0;
}
