#include <bits/stdc++.h>
using namespace std;

struct Node {
    int left = -1, right = -1;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<Node> tree(n + 1); 

    for (int i = 0; i < n - 1; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        if (z == 0) tree[x].left = y;
        else tree[x].right = y;
    }

    
    queue<pair<int,int>> q; 
    q.push({1, 1});

    unordered_map<int,int> levelCount;
    int maxWidth = 0;

    while (!q.empty()) {
        auto [v, lvl] = q.front();
        q.pop();

        levelCount[lvl]++;
        maxWidth = max(maxWidth, levelCount[lvl]);

        if (tree[v].left != -1) q.push({tree[v].left, lvl + 1});
        if (tree[v].right != -1) q.push({tree[v].right, lvl + 1});
    }

    cout << maxWidth << "\n";
    return 0;
}
