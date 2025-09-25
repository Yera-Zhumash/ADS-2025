#include <bits/stdc++.h>
using namespace std;

struct Node {
    string data;
    Node* prev;
    Node* next;
    Node(string s) : data(s), prev(nullptr), next(nullptr) {}
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Node* head = nullptr;
    Node* tail = nullptr;
    string cmd;

    while (cin >> cmd) {
        if (cmd == "add_front") {
            string name;
            cin >> name;
            Node* node = new Node(name);
            if (!head) {
                head = tail = node;
            } else {
                node->next = head;
                head->prev = node;
                head = node;
            }
            cout << "ok\n";
        }
        else if (cmd == "add_back") {
            string name;
            cin >> name;
            Node* node = new Node(name);
            if (!tail) {
                head = tail = node;
            } else {
                node->prev = tail;
                tail->next = node;
                tail = node;
            }
            cout << "ok\n";
        }
        else if (cmd == "erase_front") {
            if (!head) {
                cout << "error\n";
            } else {
                cout << head->data << "\n";
                Node* tmp = head;
                head = head->next;
                if (head) head->prev = nullptr;
                else tail = nullptr;
                delete tmp;
            }
        }
        else if (cmd == "erase_back") {
            if (!tail) {
                cout << "error\n";
            } else {
                cout << tail->data << "\n";
                Node* tmp = tail;
                tail = tail->prev;
                if (tail) tail->next = nullptr;
                else head = nullptr;
                delete tmp;
            }
        }
        else if (cmd == "front") {
            if (!head) cout << "error\n";
            else cout << head->data << "\n";
        }
        else if (cmd == "back") {
            if (!tail) cout << "error\n";
            else cout << tail->data << "\n";
        }
        else if (cmd == "clear") {
            while (head) {
                Node* tmp = head;
                head = head->next;
                delete tmp;
            }
            tail = nullptr;
            cout << "ok\n";
        }
        else if (cmd == "exit") {
            cout << "goodbye\n";
            break;
        }
    }
    return 0;
}
