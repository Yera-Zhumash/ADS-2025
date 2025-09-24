#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    unordered_map<int,int> freq;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
        freq[nums[i]]++;
    }

    int mx = 0;
    for (auto &p : freq) mx = max(mx, p.second);

  
    vector<int> modes;
    for (auto &p : freq)
        if (p.second == mx) modes.push_back(p.first);

    sort(modes.rbegin(), modes.rend()); 

    for (int x : modes) cout << x << ' ';
    cout << '\n';
    return 0;
}
