#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> p, r;
    DSU(int n) : p(n+1), r(n+1, 0) {
        iota(p.begin(), p.end(), 0);
    }
    int find(int x) {
        return p[x] == x ? x : p[x] = find(p[x]);
    }
    bool unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return false;
        if (r[a] < r[b]) swap(a,b);
        p[b] = a;
        if (r[a] == r[b]) r[a]++;
        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<array<long long,3>> seg(m);
    for (int i = 0; i < m; i++) {
        cin >> seg[i][0] >> seg[i][1] >> seg[i][2];
    }

    sort(seg.begin(), seg.end(), [&](auto &a, auto &b){
        return a[2] < b[2];
    });

    DSU dsu(n);

   
    vector<int> nxt(n+2);
    iota(nxt.begin(), nxt.end(), 0);

    function<int(int)> getNext = [&](int x) {
        if (x > n) return x;
        return nxt[x] == x ? x : nxt[x] = getNext(nxt[x]);
    };

    long long ans = 0;

    for (auto &s : seg) {
        long long l = s[0], r = s[1], c = s[2];
        int i = getNext(l);

        while (i < r) {
            if (dsu.unite(i, i+1))
                ans += c;

            nxt[i] = i+1;      
            i = getNext(i);    
        }
    }

    cout << ans << "\n";
    return 0;
}
