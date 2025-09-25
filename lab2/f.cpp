#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
};


Node* insertNode(Node* head, int val, int pos) {
    Node* newNode = new Node(val);

    if (pos == 0) {
        newNode->next = head;
        return newNode;
    }

    Node* cur = head;
    for (int i = 0; i < pos - 1 && cur != nullptr; i++) {
        cur = cur->next;
    }

    if (cur != nullptr) {
        newNode->next = cur->next;
        cur->next = newNode;
    }
    return head;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    Node* head = nullptr;
    Node* tail = nullptr;

    
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        Node* temp = new Node(x);
        if (!head) head = tail = temp;
        else {
            tail->next = temp;
            tail = temp;
        }
    }

    int val, pos;
    cin >> val >> pos;

    head = insertNode(head, val, pos);

    
    for (Node* cur = head; cur; cur = cur->next)
        cout << cur->data << " ";

    return 0;
}
