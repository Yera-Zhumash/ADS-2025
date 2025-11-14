#include <bits/stdc++.h>
using namespace std;

vector<int> prefix_function(const string &s) {
    int n = s.size();
    vector<int> pi(n, 0);
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

    string text, pattern;
    cin >> text >> pattern;

    string combined = pattern + "#" + text;
    vector<int> pi = prefix_function(combined);

    vector<int> occ;
    int m = pattern.size();

    for (int i = m + 1; i < combined.size(); i++) {
        if (pi[i] == m) {
         
            int pos = i - 2*m;
            occ.push_back(pos + 1); 
        }
    }

    cout << occ.size() << "\n";
    for (int x : occ) cout << x << " ";
    cout << "\n";

    return 0;
}
