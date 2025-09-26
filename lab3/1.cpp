#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    vector<long long> query(t);
    for (int i = 0; i < t; i++) cin >> query[i];

    int n, m;
    cin >> n >> m;
    vector<vector<long long>> a(n, vector<long long>(m));
    unordered_map<long long, pair<int,int>> pos;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            pos[a[i][j]] = {i, j};
        }
    }

    for (long long x : query) {
        if (pos.count(x))
            cout << pos[x].first << " " << pos[x].second << "\n";
        else
            cout << -1 << "\n";
    }
    return 0;
}
