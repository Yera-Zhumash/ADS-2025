#include <bits/stdc++.h>
using namespace std;

struct Node {
    string word;
    Node* next;
    Node(string w) : word(w), next(nullptr) {}
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    Node *head = nullptr, *tail = nullptr;

    for (int i = 0; i < n; ++i) {
        string w; cin >> w;
        Node* node = new Node(w);
        if (!head) head = tail = node;
        else { tail->next = node; tail = node; }
    }

    k %= n;                       
    if (k == 0) {                  
        Node* cur = head;
        while (cur) { cout << cur->word << " "; cur = cur->next; }
        cout << "\n";
        return 0;
    }

    
    Node* prev = head;
    for (int i = 1; i < k; ++i) prev = prev->next;

    Node* newHead = prev->next;    
    prev->next = nullptr;          

    
    Node* cur = newHead;
    while (cur->next) cur = cur->next;
    cur->next = head;              

    
    cur = newHead;
    while (cur) { cout << cur->word << " "; cur = cur->next; }
    cout << "\n";
    return 0;
}
