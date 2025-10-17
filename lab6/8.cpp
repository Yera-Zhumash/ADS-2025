#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<char> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    char x;
    cin >> x;

    for (char c : arr) {
        if (c > x) {
            cout << c;
            return 0;
        }
    }

    cout << arr[0];
    return 0;
}
