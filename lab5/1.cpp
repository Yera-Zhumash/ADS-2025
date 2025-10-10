#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return; // на случай некорректного ввода

    // Если 0 или 1 элемент — никакой «стоимости» слияния нет.
    if (n <= 1) {
        // прочитать возможные входные значения, чтобы не нарушать протокол ввода
        ll tmp;
        for (int i = 0; i < n; ++i) cin >> tmp;
        cout << 0 << '\n';
        return;
    }

    // Мини-куча (priority_queue с greater) для суммирования по минимальным парам
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    for (int i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        pq.push(x);
    }

    ll total_cost = 0;
    while (pq.size() > 1) {
        ll a = pq.top(); pq.pop();
        ll b = pq.top(); pq.pop();
        ll merged = a + b;
        total_cost += merged;
        pq.push(merged);
    }

    cout << total_cost << '\n';
}

int main() {
    solve();
    return 0;
}
