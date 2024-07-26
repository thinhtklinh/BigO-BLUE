#include <iostream>
using namespace std;

// find the kth node (from the last node) in a single linked list
class LinkedListNode {
public:
    int value;
    LinkedListNode* next;

    LinkedListNode(int val) : value(val), next(nullptr) {}
};

void sol1(int k, LinkedListNode* head) {
    LinkedListNode* tmp = head;
    int size = 0;
    while (tmp != nullptr) {
        size++;
        tmp = tmp->next;
    }

    k = size - k;
    while (k != 0) {
        head = head->next;
        k--;
    }
    cout << head->value;
}

void sol2(int k, LinkedListNode* head) {
    LinkedListNode* leftN = head;
    LinkedListNode* rightN = head;

    for (int i = 0; i<k-1; ++i) {
        if (rightN->next == nullptr) {
            return;
        }
        rightN = rightN->next; 
    }

    while (rightN->next) {
        leftN = leftN->next;
        rightN = rightN->next;
    }

    cout << leftN->value;
}


int main() {
    LinkedListNode* a = new LinkedListNode(1);
    LinkedListNode* b = new LinkedListNode(2);
    LinkedListNode* c = new LinkedListNode(3);
    LinkedListNode* d = new LinkedListNode(4);
    LinkedListNode* e = new LinkedListNode(5);

    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;

    // sol1(2, a);
    sol2(2, a);
    return 0;
}