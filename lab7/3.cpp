#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> a(n), b(m);
    for (int &x : a) cin >> x;
    for (int &x : b) cin >> x;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    vector<int> common;
    int i = 0, j = 0;

    while (i < n && j < m) {
        if (a[i] == b[j]) {
            common.push_back(a[i]);
            ++i; ++j;
        } 
        else if (a[i] < b[j]) ++i;
        else ++j;
    }

    for (int x : common) cout << x << ' ';

    return 0;
}