#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long k;
    cin >> n >> k;
    vector<long long> a(n);
    long long mx = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mx = max(mx, a[i]);
    }

    long long low = 1, high = mx;
    while (low < high) {
        long long mid = (low + high) / 2;
        long long flights = 0;
        for (long long x : a) {
            flights += (x + mid - 1) / mid;   // ceil(x / mid)
            if (flights > k) break;          // ранний выход
        }
        if (flights <= k) high = mid;
        else low = mid + 1;
    }
    cout << low << "\n";
    return 0;
}
