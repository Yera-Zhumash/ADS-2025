#include <bits/stdc++.h>
using namespace std;

struct Row {
    vector<int> elements; // используем vector вместо массива
    int sum = 0;
};

bool cmp(const Row& a, const Row& b) {
    if (a.sum != b.sum)
        return a.sum > b.sum; // сортировка по сумме (по убыванию)

    return a.elements < b.elements; // при равных суммах — лексикографически
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<Row> rows(n);

    for (int i = 0; i < n; ++i) {
        rows[i].elements.resize(m);
        for (int j = 0; j < m; ++j) {
            cin >> rows[i].elements[j];
            rows[i].sum += rows[i].elements[j];
        }
    }

    sort(rows.begin(), rows.end(), cmp);

    for (const auto& r : rows) {
        for (int val : r.elements)
            cout << val << ' ';
        cout << '\n';
    }

    return 0;
}
