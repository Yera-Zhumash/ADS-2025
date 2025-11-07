#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

const ull P = 1315423911ULL; 

ull computeHash(const string &s, int start, int len, vector<ull> &pref, vector<ull> &power) {
    return pref[start + len] - pref[start] * power[len];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k;
    cin >> k;
    vector<string> s(k);
    for (int i = 0; i < k; i++) cin >> s[i];

    
    int idx = min_element(s.begin(), s.end(),
                          [](auto &a, auto &b) { return a.size() < b.size(); }) - s.begin();
    string base = s[idx];
    swap(s[idx], s[0]);
    int n = base.size();

    
    vector<ull> power(n + 1, 1);
    for (int i = 1; i <= n; i++) power[i] = power[i - 1] * P;

    
    vector<vector<ull>> pref(k);
    for (int i = 0; i < k; i++) {
        int len = s[i].size();
        pref[i].resize(len + 1, 0);
        for (int j = 0; j < len; j++)
            pref[i][j + 1] = pref[i][j] * P + s[i][j];
    }

   
    int low = 1, high = n, bestLen = 0;
    string answer;

    while (low <= high) {
        int mid = (low + high) / 2;
        unordered_set<ull> common;

       
        for (int i = 0; i + mid <= n; i++)
            common.insert(computeHash(base, i, mid, pref[0], power));

        bool ok = true;
        for (int t = 1; t < k && ok; t++) {
            unordered_set<ull> cur;
            for (int i = 0; i + mid <= (int)s[t].size(); i++) {
                ull h = computeHash(s[t], i, mid, pref[t], power);
                if (common.count(h)) cur.insert(h);
            }
            if (cur.empty()) ok = false;
            else common = move(cur);
        }

        if (ok) {
            bestLen = mid;
            ull target = *common.begin();
            for (int i = 0; i + mid <= n; i++) {
                if (computeHash(base, i, mid, pref[0], power) == target) {
                    answer = base.substr(i, mid);
                    break;
                }
            }
            low = mid + 1;
        } else
            high = mid - 1;
    }

    cout << answer << "\n";
}
