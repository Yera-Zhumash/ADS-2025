#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, k;
    if (!(cin >> n >> k)) return 0;
    struct Rect { ll x1,y1,x2,y2; };
    vector<Rect> a(n);
    ll maxCoord = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].x1 >> a[i].y1 >> a[i].x2 >> a[i].y2;
        maxCoord = max(maxCoord, max(a[i].x2, a[i].y2));
        
    }

    auto can = [&](ll L)->bool{
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i].x1 >= 0 && a[i].y1 >= 0 && a[i].x2 <= L && a[i].y2 <= L) {
                ++cnt;
                if (cnt >= k) return true;
            }
        }
        return false;
    };

    ll lo = 0, hi = maxCoord;
    ll ans = -1;
    while (lo <= hi) {
        ll mid = lo + (hi - lo) / 2;
        if (can(mid)) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

   
    if (ans == -1) {
        cout << -1 << "\n";
    } else {
        cout << ans << "\n";
    }

    return 0;
}
