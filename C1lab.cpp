#include <bits/stdc++.h>
using namespace std;


string s(const string &s) {
    string res;
    for (char c : s) {
        if (c == '#') {
            if (!res.empty()) res.pop_back();
        } else {
            res.push_back(c);
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s1, s2;
    cin >> s1 >> s2;

    if (s(s1) == s(s2))
        cout << "Yes\n";
    else
        cout << "No\n";

    return 0;
}