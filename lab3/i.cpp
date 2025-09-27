#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    long long x;
    cin >> x;

    if (binary_search(a.begin(), a.end(), x))
        cout << "Yes\n";
    else
        cout << "No\n";

    return 0;
}
