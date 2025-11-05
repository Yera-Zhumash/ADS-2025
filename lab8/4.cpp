#include <bits/stdc++.h>
using namespace std;

struct AhoCorasick {
    struct Node {
        int next[26], link = -1;
        vector<int> out;
        Node() { memset(next, -1, sizeof(next)); }
    };

    vector<Node> t;
    AhoCorasick() { t.emplace_back(); }

    void add_string(const string &s, int id) {
        int v = 0;
        for (char c : s) {
            int ch = c - 'a';
            if (t[v].next[ch] == -1) {
                t[v].next[ch] = t.size();
                t.emplace_back();
            }
            v = t[v].next[ch];
        }
        t[v].out.push_back(id);
    }

    void build() {
        queue<int> q;
        for (int ch = 0; ch < 26; ch++) {
            if (t[0].next[ch] != -1) {
                t[t[0].next[ch]].link = 0;
                q.push(t[0].next[ch]);
            } else {
                t[0].next[ch] = 0;
            }
        }

        while (!q.empty()) {
            int v = q.front(); q.pop();
            for (int ch = 0; ch < 26; ch++) {
                int u = t[v].next[ch];
                if (u != -1) {
                    t[u].link = t[t[v].link].next[ch];
                    for (int x : t[t[u].link].out)
                        t[u].out.push_back(x);
                    q.push(u);
                } else {
                    t[v].next[ch] = t[t[v].link].next[ch];
                }
            }
        }
    }

    vector<int> search(const string &s, int m) {
        vector<int> freq(m);
        int v = 0;
        for (char c : s) {
            v = t[v].next[c - 'a'];
            for (int id : t[v].out)
                freq[id]++;
        }
        return freq;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true) {
        int n;
        if (!(cin >> n)) break;
        if (n == 0) break;

        vector<string> patterns(n);
        for (int i = 0; i < n; i++) cin >> patterns[i];

        string text;
        cin >> text;

        AhoCorasick aho;
        for (int i = 0; i < n; i++) aho.add_string(patterns[i], i);
        aho.build();

        vector<int> freq = aho.search(text, n);
        int mx = *max_element(freq.begin(), freq.end());

        cout << mx << "\n";
        for (int i = 0; i < n; i++)
            if (freq[i] == mx)
                cout << patterns[i] << "\n";
    }
}
