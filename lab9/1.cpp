#include <bits/stdc++.h>
using namespace std;


vector<int> buildLPS(const string &p) {
    int m = p.size();
    vector<int> lps(m);
    for (int i = 1, len = 0; i < m; ) {
        if (p[i] == p[len]) {
            lps[i++] = ++len;
        } else if (len > 0) {
            len = lps[len - 1];
        } else {
            lps[i++] = 0;
        }
    }
    return lps;
}


bool kmp(const string &t, const string &p) {
    int n = t.size(), m = p.size();
    if (m == 0) return true;
    vector<int> lps = buildLPS(p);

    for (int i = 0, j = 0; i < n; ) {
        if (t[i] == p[j]) {
            i++; j++;
            if (j == m) return true;
        } else if (j > 0) {
            j = lps[j - 1];
        } else {
            i++;
        }
    }
    return false;
}

int minRepetitions(const string &a, const string &b) {
    string s = a;
    int cnt = 1;

    
    while (s.size() < b.size()) {
        s += a;
        cnt++;
    }

    
    if (kmp(s, b)) return cnt;

    
    if (kmp(s + a, b)) return cnt + 1;

    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string A, B;
    getline(cin, A);
    getline(cin, B);

    cout << minRepetitions(A, B) << "\n";
    return 0;
}
