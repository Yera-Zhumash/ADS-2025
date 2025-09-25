#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x): data(x), next(nullptr) {}
};


Node* insertNode(Node* head, int x, int p) {
    Node* newNode = new Node(x);
    if (p == 0) {
        newNode->next = head;
        return newNode;
    }
    Node* cur = head;
    for (int i = 0; i < p - 1 && cur; i++)
        cur = cur->next;
    if (cur) {
        newNode->next = cur->next;
        cur->next = newNode;
    }
    return head;
}


Node* removeNode(Node* head, int p) {
    if (!head) return head;
    if (p == 0) {
        Node* tmp = head->next;
        delete head;
        return tmp;
    }
    Node* cur = head;
    for (int i = 0; i < p - 1 && cur; i++)
        cur = cur->next;
    if (cur && cur->next) {
        Node* del = cur->next;
        cur->next = del->next;
        delete del;
    }
    return head;
}


void printList(Node* head) {
    if (!head) {
        cout << -1 << "\n";
        return;
    }
    for (Node* cur = head; cur; cur = cur->next)
        cout << cur->data << (cur->next ? ' ' : '\n');
}

Node* replaceNode(Node* head, int p1, int p2) {
    if (!head || p1 == p2) return head;

    Node* removed = nullptr;
    if (p1 == 0) {
        removed = head;
        head = head->next;
    } else {
        Node* cur = head;
        for (int i = 0; i < p1 - 1; i++) cur = cur->next;
        removed = cur->next;
        cur->next = removed->next;
    }

    removed->next = nullptr;

    if (p2 == 0) {
        removed->next = head;
        return removed;
    } else {
        Node* cur = head;
        for (int i = 0; i < p2 - 1; i++) cur = cur->next;
        removed->next = cur->next;
        cur->next = removed;
        return head;
    }
}


Node* reverseList(Node* head) {
    Node* prev = nullptr;
    Node* cur = head;
    while (cur) {
        Node* nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
    }
    return prev;
}


Node* cyclicLeft(Node* head, int x) {
    if (!head || x == 0) return head;
    int len = 0;
    Node* tail = head;
    while (tail->next) {
        tail = tail->next;
        len++;
    }
    len++;
    x %= len;
    if (x == 0) return head;

    Node* cur = head;
    for (int i = 0; i < x - 1; i++) cur = cur->next;
    Node* newHead = cur->next;
    cur->next = nullptr;
    tail->next = head;
    return newHead;
}


Node* cyclicRight(Node* head, int x) {
    if (!head || x == 0) return head;
    int len = 0;
    Node* tail = head;
    while (tail->next) {
        tail = tail->next;
        len++;
    }
    len++;
    x %= len;
    if (x == 0) return head;
    
    return cyclicLeft(head, len - x);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Node* head = nullptr;
    int cmd;
    while (cin >> cmd) {
        if (cmd == 0) break;

        if (cmd == 1) { 
            int x, p;
            cin >> x >> p;
            head = insertNode(head, x, p);
        }
        else if (cmd == 2) { 
            int p;
            cin >> p;
            head = removeNode(head, p);
        }
        else if (cmd == 3) { 
            printList(head);
        }
        else if (cmd == 4) { 
            int p1, p2;
            cin >> p1 >> p2;
            head = replaceNode(head, p1, p2);
        }
        else if (cmd == 5) { 
            head = reverseList(head);
        }
        else if (cmd == 6) { 
            int x;
            cin >> x;
            head = cyclicLeft(head, x);
        }
        else if (cmd == 7) { 
            int x;
            cin >> x;
            head = cyclicRight(head, x);
        }
    }
    return 0;
}
