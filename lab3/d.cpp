#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vector<ll> a(n), vals;
    vals.reserve(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        vals.push_back(a[i]);
    }

 
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());
    int m = vals.size();

    vector<ll> freq(m + 1, 0);
    for (ll x : a) {
        int id = int(lower_bound(vals.begin(), vals.end(), x) - vals.begin()) + 1;
        freq[id]++;
    }
    for (int i = 1; i <= m; i++) freq[i] += freq[i - 1];

    auto countRange = [&](ll L, ll R) -> ll {
        if (R < L) return 0;
        int r = int(upper_bound(vals.begin(), vals.end(), R) - vals.begin());
        int l = int(lower_bound(vals.begin(), vals.end(), L) - vals.begin()) + 1;
        if (r == 0 || l > m) return 0;
        r = min(r, m);
        l = max(l, 1);
        if (l > r) return 0;
        return freq[r] - freq[l - 1];
    };

    while (q--) {
        ll l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        ll c1 = countRange(l1, r1);
        ll c2 = countRange(l2, r2);
        ll inter = countRange(max(l1, l2), min(r1, r2));
        cout << c1 + c2 - inter << "\n";
    }
    return 0;
}
