#include <bits/stdc++.h>
using namespace std;


struct Node {
    int val;
    Node *left, *right;
    Node(int v) : val(v), left(NULL), right(NULL) {}
};


Node* insert(Node* root, int x) {
    if (!root) return new Node(x);
    if (x < root->val) root->left = insert(root->left, x);
    else root->right = insert(root->right, x);
    return root;
}


bool checkPath(Node* root, const string &path) {
    Node* cur = root;
    for (char c : path) {
        if (!cur) return false; 
        if (c == 'L') cur = cur->left;
        else if (c == 'R') cur = cur->right;
    }
    return cur != NULL; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; 
    cin >> n >> m;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

   
    Node* root = NULL;
    for (int x : arr) root = insert(root, x);

    
    while (m--) {
        string path;
        cin >> path;
        if (checkPath(root, path)) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
