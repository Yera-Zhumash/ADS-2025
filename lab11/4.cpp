#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<ll>> cost(n, vector<ll>(n));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> cost[i][j];

    const ll INF = (1LL << 60);
    vector<ll> dist(n, INF);
    vector<bool> used(n, false);

    dist[0] = 0;
    ll ans = 0;

    for(int it = 0; it < n; it++) {
        int v = -1;
        for(int i = 0; i < n; i++)
            if(!used[i] && (v == -1 || dist[i] < dist[v]))
                v = i;

        used[v] = true;
        ans += dist[v];

        for(int u = 0; u < n; u++)
            if(!used[u] && cost[v][u] < dist[u])
                dist[u] = cost[v][u];
    }

    cout << ans << "\n";
    return 0;
}
