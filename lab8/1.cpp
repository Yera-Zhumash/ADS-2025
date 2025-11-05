#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007LL;
const long long BASE = 11LL;

long long get_hash(const string &s) {
    long long h = 0;
    long long p = 1;
    for (size_t i = 0; i < s.size(); ++i) {
        h = (h + (long long)(s[i] - 47) * p) % MOD;
        p = (p * BASE) % MOD;
    }
    return h;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<string> v;
    v.reserve(2 * n);
    set<string> st;

    for (int i = 0; i < 2 * n; ++i) {
        string s;
        cin >> s;
        v.push_back(s);
        st.insert(s);
    }

    int cnt = 0;
    for (size_t i = 0; i < v.size() && cnt < n; ++i) {
        string s = v[i];
        long long hs_val = get_hash(s);
        ostringstream oss;
        oss << hs_val;
        string hs = oss.str();

        if (st.count(hs)) {
            cout << "Hash of string \"" << s << "\" is " << hs << "\n";
            cnt++;
        }
    }

    return 0;
}
