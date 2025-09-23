#include <bits/stdc++.h>
using namespace std;

bool isPrime(int x) {
    if (x < 2) return false;
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0) return false;
    return true;
}

int main() {
    int n;
    cin >> n;
    vector<int> primes;
    int num = 2;
    
    while ((int)primes.size() < 2000) {
        if (isPrime(num))
            primes.push_back(num);
        num++;
    }
    
    vector<int> superprimes;
    for (int i = 0; i < (int)primes.size(); i++) {
        int index = i + 1; 
        if (isPrime(index))
            superprimes.push_back(primes[i]);
        if ((int)superprimes.size() == n) break;
    }

    cout << superprimes[n-1] << endl;
}