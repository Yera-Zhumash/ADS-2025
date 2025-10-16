#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);

    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    map<int, int> freq;
    for (int x : a) freq[x]++;

    vector<int> result;
    for (int x : b) {
        if (freq[x] > 0) {
            result.push_back(x);
            freq[x]--;
        }
    }

    sort(result.begin(), result.end());  // 🔹 Fix: sort intersection

    for (int x : result) cout << x << " ";
    return 0;
}
