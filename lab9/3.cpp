#include <bits/stdc++.h>
using namespace std;

vector<int> computeLPS(const string &p) {
    int n = p.size();
    vector<int> lps(n, 0);
    int len = 0;
    for (int i = 1; i < n; ) {
        if (p[i] == p[len]) {
            lps[i++] = ++len;
        } else if (len > 0) {
            len = lps[len-1];
        } else {
            lps[i++] = 0;
        }
    }
    return lps;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string a, b;
    cin >> a >> b;

    int n = a.size();

    string t = a + a; 
    string p = b;

    vector<int> lps = computeLPS(p);

    int i = 0, j = 0;
    while (i < (int)t.size()) {
        if (t[i] == p[j]) {
            i++; j++;
            if (j == n) {
                int pos = i - n;
                
                if (pos < n) { 
                    int shift = (n - pos) % n;
                    cout << shift;
                    return 0;
                }
                j = lps[j-1];
            }
        } else if (j > 0) {
            j = lps[j-1];
        } else {
            i++;
        }
    }

    cout << -1;
    return 0;
}
