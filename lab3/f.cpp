#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a.begin(), a.end());

   
    vector<ll> pref(n + 1, 0);
    for (int i = 0; i < n; i++) pref[i + 1] = pref[i] + a[i];

    int q;
    cin >> q;
    while (q--) {
        ll power;
        cin >> power;
        int cnt = upper_bound(a.begin(), a.end(), power) - a.begin();
        ll sum = pref[cnt];
        cout << cnt << " " << sum << "\n";
    }
    return 0;
}
