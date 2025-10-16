#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;

    string vowels = "", consonants = "";
    string vowelSet = "aeiou";

    for (char c : s) {
        if (vowelSet.find(c) != string::npos)
            vowels += c;
        else
            consonants += c;
    }

    sort(vowels.begin(), vowels.end());
    sort(consonants.begin(), consonants.end());

    cout << vowels + consonants;
    return 0;
}
