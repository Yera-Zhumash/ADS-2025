#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore(); 

    for (int i = 0; i < n; i++) {
        string line;
        getline(cin, line);

        stringstream ss(line);
        vector<string> words;
        string word;

        while (ss >> word) {
            words.push_back(word);
        }

        
        stable_sort(words.begin(), words.end(), [](const string &a, const string &b) {
            return a.size() < b.size();
        });

        for (const string &w : words) {
            cout << w << " ";
        }
        cout << endl;
    }

    return 0;
}
