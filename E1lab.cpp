#include <bits/stdc++.h>
using namespace std;

int main() {
    queue<int> boris, nursik;
    for (int i = 0; i < 5; i++) {
        int x; cin >> x;
        boris.push(x);
    }
    for (int i = 0; i < 5; i++) {
        int x; cin >> x;
        nursik.push(x);
    }

    int moves = 0;
    while (!boris.empty() && !nursik.empty() && moves < 1000000) {
        moves++;
        int b = boris.front(); boris.pop();
        int n = nursik.front(); nursik.pop();

        if ((b == 0 && n == 9) || (b > n && !(b == 9 && n == 0))) {
            boris.push(b);
            boris.push(n);
        } else {
            nursik.push(b);
            nursik.push(n);
        }
    }

    if (moves >= 1000000)
        cout << "botva" << endl;
    else if (boris.empty())
        cout << "Nursik " << moves << endl;
    else
        cout << "Boris " << moves << endl;
}