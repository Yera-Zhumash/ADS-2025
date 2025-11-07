#include <bits/stdc++.h>
using namespace std;

struct SuffixAutomaton {
    struct State {
        int len, link;
        map<char, int> next;
    };

    vector<State> st;
    int last;

    SuffixAutomaton(int n) {
        st.resize(2 * n);
        st[0].len = 0;
        st[0].link = -1;
        last = 0;
    }

    void extend(char c) {
        int cur = st.size();
        st.push_back({});
        st[cur].len = st[last].len + 1;

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

                while (p != -1 && st[p].next[c] == q) {
                    st[p].next[c] = clone;
                    p = st[p].link;
                }
                st[q].link = st[cur].link = clone;
            }
        }
        last = cur;
    }

    long long countDistinct() {
        long long ans = 0;
        for (int i = 1; i < (int)st.size(); i++)
            ans += st[i].len - st[st[i].link].len;
        return ans;
    }
};

int main() {
    string s;
    cin >> s;

    SuffixAutomaton sa(s.size());
    for (char c : s) sa.extend(c);

    cout << sa.countDistinct() << "\n";
}
