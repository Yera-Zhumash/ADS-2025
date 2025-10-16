#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a.begin(), a.end());

    int minDiff = INT_MAX;
    for (int i = 1; i < n; i++)
        minDiff = min(minDiff, abs(a[i] - a[i - 1]));

    for (int i = 1; i < n; i++)
        if (abs(a[i] - a[i - 1]) == minDiff)
            cout << a[i - 1] << " " << a[i] << " ";

    return 0;
}
