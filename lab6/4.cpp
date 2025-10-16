#include <bits/stdc++.h>
using namespace std;

struct Date {
    int day, month, year;
    string original;
};

int main() {
    int n;
    cin >> n;
    vector<Date> dates(n);

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        dates[i].original = s;
        dates[i].day = stoi(s.substr(0, 2));
        dates[i].month = stoi(s.substr(3, 2));
        dates[i].year = stoi(s.substr(6, 4));
    }

    sort(dates.begin(), dates.end(), [](const Date &a, const Date &b) {
        if (a.year != b.year) return a.year < b.year;
        if (a.month != b.month) return a.month < b.month;
        return a.day < b.day;
    });

    for (auto &d : dates)
        cout << d.original << "\n";

    return 0;
}
