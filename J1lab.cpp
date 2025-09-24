#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    deque<long long> dq;     
    char cmd;
    long long x;

    while (cin >> cmd) {      
        if (cmd == '!') break;                 
        else if (cmd == '+') { cin >> x; dq.push_front(x); }  
        else if (cmd == '-') { cin >> x; dq.push_back(x); }   
        else if (cmd == '*') {
            if (dq.empty()) cout << "error\n";             
            else if (dq.size() == 1) {                       
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

