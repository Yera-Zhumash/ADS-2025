#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    
    vector<long long> end(n);
    end[0] = a[0];
    for (int i = 1; i < n; i++) end[i] = end[i - 1] + a[i];

    while (m--) {
        long long line;
        cin >> line;
        
        int block = lower_bound(end.begin(), end.end(), line) - end.begin() + 1;
        cout << block << "\n";
    }
    return 0;
}
