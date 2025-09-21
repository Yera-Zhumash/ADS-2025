#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    while (n--) {
        int c; //card
        cin >> c;
        int size = 0;  
        int data[1000];
        for (int j = c; j > 0; j--) {
            for (int i = size; i > 0; i--) {
                data[i] = data[i - 1];
            }
            data[0] = j;
            size++;
            for (int x = 0; x < j; x++) {
                int last = data[size - 1];
                for (int i = size - 1; i > 0; i--) {
                    data[i] = data[i - 1];
                }
                data[0] = last;
            }
        }
        for (int i = 0; i < size; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
    return 0;
}