#include <bits/stdc++.h>
using namespace std;

vector<int> prefix_function(const string &s) {
    int n = s.size();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];
        if (s[i] == s[j]) j++;
        pi[i] = j;
    }
    return pi;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        string s;
        long long k;
        cin >> s >> k;

        int n = s.size();
        auto pi = prefix_function(s);

        int overlap = pi.back(); 
        int add = n - overlap;

        long long ans = n + (k - 1) * 1LL * add;
        cout << ans << "\n";
    }
    return 0;
}
