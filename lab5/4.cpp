#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long target;
    cin >> n >> target;

    priority_queue<long long, vector<long long>, greater<long long>> pq;
    for (int i = 0; i < n; ++i) {
        long long val;
        cin >> val;
        pq.push(val);
    }

    int operations = 0;
    while (pq.size() > 1 && pq.top() < target) {
        long long first = pq.top(); pq.pop();
        long long second = pq.top(); pq.pop();
        pq.push(first + 2 * second);
        ++operations;
    }

    cout << (pq.top() < target ? -1 : operations);
    return 0;
}
