#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct DSU {
    int n;
    vector<int> p, r;
    DSU(int n=0): n(n), p(n+1), r(n+1,0) {
        iota(p.begin(), p.end(), 0);
    }
    int find(int x){ return p[x]==x? x : p[x]=find(p[x]); }
    bool unite(int a,int b){
        a = find(a); b = find(b);
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
    if(!(cin >> n >> m)) return 0;
    ll costBig, costSmall;
    cin >> costBig >> costSmall;
    
    struct Edge { int u,v; ll w; };
    vector<Edge> edges;
    edges.reserve(m);
    
    for(int i=0;i<m;i++){
        string t;
        int u,v;
        ll len;
        cin >> t >> u >> v >> len;
        ll w;
        if(t == "big") w = costBig * len;
        else if(t == "small") w = costSmall * len;
        else /* "both" */ w = min(costBig, costSmall) * len;
        edges.push_back({u,v,w});
    }
    
    sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b){
        return a.w < b.w;
    });
    
    DSU dsu(n);
    ll ans = 0;
    int taken = 0;
    for(auto &e : edges){
        if(dsu.unite(e.u, e.v)){
            ans += e.w;
            if(++taken == n-1) break;
        }
    }
    
    cout << ans << "\n";
    return 0;
}
