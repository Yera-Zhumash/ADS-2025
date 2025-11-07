#include <bits/stdc++.h>
using namespace std;

struct SuffixAutomaton {
    struct State {
        int len, link;
        map<char, int> next;
        long long occ = 0;
    };

    vector<State> st;
    int last;

    SuffixAutomaton(int n) {
        st.reserve(2 * n);
        st.push_back({0, -1, {}, 0});
        last = 0;
    }

    void extend(char c) {
        int cur = st.size();
        st.push_back({st[last].len + 1, 0, {}, 1}); // occ=1 initially
        int p = last;
        while (p != -1 && !st[p].next.count(c)) {
            st[p].next[c] = cur;
            p = st[p].link;
        }
        if (p == -1)
            st[cur].link = 0;
        else {
            int q = st[p].next[c];
            if (st[p].len + 1 == st[q].len)
                st[cur].link = q;
            else {
                int clone = st.size();
                st.push_back(st[q]);
                st[clone].len = st[p].len + 1;
                st[clone].occ = 0;
                while (p != -1 && st[p].next[c] == q) {
                    st[p].next[c] = clone;
                    p = st[p].link;
                }
                st[q].link = st[cur].link = clone;
            }
        }
        last = cur;
    }

    void computeOccurrences() {
        // Order states by descending length
        vector<int> order(st.size());
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](int a, int b) {
            return st[a].len > st[b].len;
        });

        for (int v : order) {
            if (st[v].link != -1)
                st[st[v].link].occ += st[v].occ;
        }
    }

    long long countSubstringOccurrences(const string &pattern) {
        int v = 0;
        for (char c : pattern) {
            if (!st[v].next.count(c))
                return 0;
            v = st[v].next[c];
        }
        return st[v].occ;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int q;
    cin >> q;

    SuffixAutomaton sa(s.size());
    for (char c : s) sa.extend(c);
    sa.computeOccurrences();

    while (q--) {
        int l, r;
        cin >> l >> r;
        string sub = s.substr(l - 1, r - l + 1);
        cout << sa.countSubstringOccurrences(sub) << "\n";
    }
}
