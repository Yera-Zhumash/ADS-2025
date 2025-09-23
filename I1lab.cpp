#include <iostream>
#include <queue>

using namespace std;

int main(){
    int n;
    cin >> n;

    string text;
    cin >> text;

    // for(int i = 0; i < n; i++){
    //     cin >> v[i];
    // }

    queue<int> qS;
    queue<int> qK;

    for(int i = 0; i < n; i++){
        if(text[i] == 'S'){
            qS.push(i);
        }
        if(text[i] == 'K'){
            qK.push(i);
        }
    }

    while (!qS.empty() && !qK.empty()) {
        int s = qS.front(); qS.pop();
        int k = qK.front(); qK.pop();

        if (s < k) {
            // S ходит раньше → выкидывает K
            qS.push(s + n);
        } else {
            // K ходит раньше → выкидывает S
            qK.push(k + n);
        }
    }

    if(!qS.empty()){
        cout << "SAKAYANAGI";
    }
    else if (!qK.empty()){
        cout << "KATSURAGI";
    }
}

