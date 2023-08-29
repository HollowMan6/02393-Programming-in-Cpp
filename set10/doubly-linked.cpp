#include "doubly-linked.h"

using namespace std;

List::List(void) : first(nullptr) {}

List::~List(void) {
    while (first != nullptr) {
        Node *temp = first;
        first = first->next;
        delete temp;
    }
}

void List::insert(int n) {
    Node *newNode = new Node;
    newNode->val = n;
    newNode->next = nullptr;

    if (first == nullptr) {
        first = newNode;
    } else {
        Node *current = first;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void List::reverse(void) {
    Node *prev = nullptr;
    Node *current = first;
    Node *next = nullptr;

    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    first = prev;
}

void List::print(void) {
    Node *current = first;
    while (current != nullptr) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
}
