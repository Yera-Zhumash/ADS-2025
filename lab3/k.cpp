#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long K;
    cin >> n >> K;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    long long sum = 0;
    int left = 0, ans = n + 1;

    for (int right = 0; right < n; right++) {
        sum += a[right];
        while (sum >= K) {
            ans = min(ans, right - left + 1);
            sum -= a[left++];
        }
    }

    cout << ans << "\n";
    return 0;
}
