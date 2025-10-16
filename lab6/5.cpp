#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];

    // Sort each column in descending order
    for (int j = 0; j < m; j++) {
        vector<int> col;
        for (int i = 0; i < n; i++)
            col.push_back(a[i][j]);
        sort(col.begin(), col.end(), greater<int>());
        for (int i = 0; i < n; i++)
            a[i][j] = col[i];
    }

    // Output result
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cout << a[i][j] << " ";
        cout << "\n";
    }
    return 0;
}
