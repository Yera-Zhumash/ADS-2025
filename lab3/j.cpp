#include <bits/stdc++.h>
using namespace std;

bool canSteal(const vector<long long>& bags, long long k, long long h) {
    long long hours = 0;
    for (long long bars : bags) {
        // ceil(bars / k) = (bars + k - 1) / k
        hours += (bars + k - 1) / k;
        if (hours > h) return false; // маленькая оптимизация
    }
    return hours <= h;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long h;
    cin >> n >> h;
    vector<long long> bags(n);
    long long mx = 0;
    for (int i = 0; i < n; i++) {
        cin >> bags[i];
        mx = max(mx, bags[i]);
    }

    long long l = 1, r = mx, ans = mx;
    while (l <= r) {
        long long mid = (l + r) / 2;
        if (canSteal(bags, mid, h)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << ans << "\n";
    return 0;
}
