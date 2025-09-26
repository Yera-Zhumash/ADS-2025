#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    long long k; cin >> k;

    long long bestDist = LLONG_MAX;
    int bestIdx = 0;

    for (int i = 0; i < n; ++i) {
        long long d = llabs(a[i] - k);
        if (d < bestDist) {        
            bestDist = d;
            bestIdx = i;
        }
        
    }

    cout << bestIdx << "\n";
    return 0;
}
