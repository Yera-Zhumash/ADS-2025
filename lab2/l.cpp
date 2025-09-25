#include <bits/stdc++.h>
using namespace std;

struct Node {
    long long data;
    Node* next;
    Node(long long x) : data(x), next(nullptr) {}
};

long long findMaxSum(Node* head) {
    if (!head) return 0; 
    long long cur = head->data;
    long long best = head->data;
    Node* p = head->next;
    while (p) {
        cur = max(p->data, cur + p->data);
        best = max(best, cur);
        p = p->next;
    }
    return best;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;
    Node* head = nullptr;
    Node* tail = nullptr;
    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        Node* node = new Node(x);
        if (!head) head = tail = node;
        else {
            tail->next = node;
            tail = node;
        }
    }
    cout << findMaxSum(head) << "\n";
    return 0;
}
