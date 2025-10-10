#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    priority_queue<long long> pq;
    for (int i = 0; i < n; ++i) {
        long long val;
        cin >> val;
        pq.push(val);
    }

    long long total = 0;
    while (k-- && !pq.empty()) {
        long long topVal = pq.top();
        pq.pop();
        total += topVal;
        if (topVal > 0) pq.push(topVal - 1);
    }

    cout << total;
    return 0;
}
