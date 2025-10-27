#include <bits/stdc++.h>
using namespace std;

struct Student {
    string surname;
    string name;
    double gpa;
};

bool cmp(const Student &a, const Student &b) {
    if (fabs(a.gpa - b.gpa) > 1e-9) return a.gpa < b.gpa;
    if (a.surname != b.surname) return a.surname < b.surname;
    return a.name < b.name;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    map<string, double> gradeValue = {
        {"A+", 4.0}, {"A", 3.75}, {"B+", 3.5}, {"B", 3.0},
        {"C+", 2.5}, {"C", 2.0}, {"D+", 1.5}, {"D", 1.0}, {"F", 0.0}
    };

    vector<Student> students(n);

    for (int i = 0; i < n; i++) {
        int m;
        cin >> students[i].surname >> students[i].name >> m;

        double totalPoints = 0;
        int totalCredits = 0;

        for (int j = 0; j < m; j++) {
            string grade;
            int credits;
            cin >> grade >> credits;

            totalPoints += gradeValue[grade] * credits;
            totalCredits += credits;
        }

        students[i].gpa = totalPoints / totalCredits;
    }

    sort(students.begin(), students.end(), cmp);

    cout << fixed << setprecision(3);
    for (auto &st : students)
        cout << st.surname << ' ' << st.name << ' ' << st.gpa << '\n';

    return 0;
}