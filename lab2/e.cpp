#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<string> names(n);
    for (int i = 0; i < n; ++i) cin >> names[i];

    vector<string> uniqueNames;
    for (int i = 0; i < n; ++i) {
        if (i == 0 || names[i] != names[i-1])
            uniqueNames.push_back(names[i]);
    }

    reverse(uniqueNames.begin(), uniqueNames.end());

    cout << "All in all: " << uniqueNames.size() << "\n";
    cout << "Students:\n";
    for (auto &name : uniqueNames)
        cout << name << "\n";
    return 0;
}
