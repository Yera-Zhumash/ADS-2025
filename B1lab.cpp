#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> ages(n);
    for (int i = 0; i < n; i++) cin >> ages[i];

    vector<int> ans(n);
    stack<int> st;

    for (int i = 0; i < n; i++) {
        while (!st.empty() && st.top() > ages[i])
            st.pop();
        if (st.empty()) ans[i] = -1;
        else ans[i] = st.top();
        st.push(ages[i]);
    }

    for (int i = 0; i < n; i++)
        cout << ans[i] << (i == n-1 ? "\n" : " ");
}