#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        queue<char> q;
        vector<int> freq(26, 0);

        for (int i = 0; i < N; i++) {
            char c;
            cin >> c;
            freq[c - 'a']++;
            q.push(c);

            while (!q.empty() && freq[q.front() - 'a'] > 1)
                q.pop();

            if (q.empty()) cout << "-1 ";
            else cout << q.front() << " ";
        }
        cout << "\n";
    }
    return 0;
}
