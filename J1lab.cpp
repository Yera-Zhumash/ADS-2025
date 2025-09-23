#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    deque<long long> dq;      // наша двусторонняя очередь
    char cmd;
    long long x;

    while (cin >> cmd) {      // читаем по одному символу команды
        if (cmd == '!') break;                 // конец
        else if (cmd == '+') { cin >> x; dq.push_front(x); }  // в начало
        else if (cmd == '-') { cin >> x; dq.push_back(x); }   // в конец
        else if (cmd == '*') {
            if (dq.empty()) cout << "error\n";               // пусто
            else if (dq.size() == 1) {                       // одна карта
                cout << dq.front() * 2 << "\n";
                dq.pop_front();
            } else {
                long long sum = dq.front() + dq.back();
                cout << sum << "\n";
                dq.pop_front();
                dq.pop_back();
            }
        }
    }
    return 0;
}
