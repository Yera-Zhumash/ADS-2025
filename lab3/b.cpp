#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool canDivide(const vector<ll>& a, ll limit, int k) {
    int blocks = 1;
    ll sum = 0;
    for (ll x : a) {
        if (sum + x > limit) {
            blocks++;
            sum = x;
            if (blocks > k) return false;
        } else {
            sum += x;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    ll L = 0, R = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        L = max(L, a[i]);   
        R += a[i];          
    }

    while (L < R) {
        ll mid = (L + R) / 2;
        if (canDivide(a, mid, k)) R = mid;
        else L = mid + 1;
    }

    cout << L << "\n";
    return 0;
}
