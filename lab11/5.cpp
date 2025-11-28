#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> p, r;
    DSU(int n): p(n+1), r(n+1,0) {
        iota(p.begin(), p.end(), 0);
    }
    int find(int x){ return p[x]==x ? x : p[x]=find(p[x]); }
    bool unite(int a,int b){
        a=find(a); b=find(b);
        if(a==b) return false;
        if(r[a]<r[b]) swap(a,b);
        p[b]=a;
        if(r[a]==r[b]) r[a]++;
        return true;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n+1);
    for(int i=0;i<m;i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    DSU dsu(n);
    vector<bool> alive(n+1, false);
    vector<int> ans(n+1);

    int comps = 0;

   
    for(int v = n; v >= 1; v--){
        alive[v] = true;
        comps++;

        for(int u : adj[v]){
            if(alive[u] && dsu.unite(v, u))
                comps--;
        }
        ans[v] = comps;
    }

    
    for(int i = 1; i < n; i++)
        cout << ans[i+1] << "\n";
    cout << 0 << "\n";

    return 0;
}
