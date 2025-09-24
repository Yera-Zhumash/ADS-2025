#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int v) : val(v), next(nullptr) {}
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    Node *head = nullptr, *tail = nullptr;

    
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        Node* node = new Node(x);
        if (!head) head = tail = node;
        else { tail->next = node; tail = node; }
    }

   
    Node* cur = head;
    while (cur && cur->next) {
        Node* toDel = cur->next;
        cur->next = toDel->next;   
        delete toDel;             
        cur = cur->next;           
    }

 
    for (Node* p = head; p; p = p->next)
        cout << p->val << ' ';
    cout << '\n';


    while (head) {
        Node* tmp = head;
        head = head->next;
        delete tmp;
    }

    return 0;
}
