#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++) cin >> A[i];

    cin >> m;
    vector<int> B(m);
    for (int i = 0; i < m; i++) cin >> B[i];

    vector<int> merged;
    merged.reserve(n + m);

    int i = 0, j = 0;

    while (i < n && j < m) {
        if (A[i] <= B[j]) {
            merged.push_back(A[i]);
            i++;
        } else {
            merged.push_back(B[j]);
            j++;
        }
    }

    while (i < n) merged.push_back(A[i++]);
    while (j < m) merged.push_back(B[j++]);

    // вывод результата
    for (int x : merged) cout << x << " ";
    cout << endl;

    return 0;
}
