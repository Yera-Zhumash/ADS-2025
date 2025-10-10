#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    priority_queue<long long> stones;
    for (int i = 0; i < n; ++i) {
        long long val;
        cin >> val;
        stones.push(val);
    }

    while (stones.size() > 1) {
        long long a = stones.top(); stones.pop();
        long long b = stones.top(); stones.pop();

        if (a != b)
            stones.push(a - b); // разница возвращается в кучу
    }

    cout << (stones.empty() ? 0 : stones.top());
    return 0;
}
