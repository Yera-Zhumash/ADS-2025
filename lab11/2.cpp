#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<long long> a(n);
    long long sum = 0;
    long long mn = LLONG_MAX;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
        mn = min(mn, a[i]);
    }

 
    long long ans = mn * (n - 1) + (sum - mn);

    cout << ans << "\n";
    return 0;
}
