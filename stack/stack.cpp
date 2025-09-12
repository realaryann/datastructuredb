#include "stack.hpp"

Stack::Stack(): sz(0) {
    this->head = nullptr;
}

int Stack::top() {
    if (head) {
        return head->data;
    } else {
        return FAILURE;
    }
}

int Stack::size() {
    return sz;
}

STATUS Stack::pop() {
    if (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
        sz--;
        return SUCCESS;
    } else {
        return FAILURE;
    }

}

bool Stack::empty() {
    return true?(sz == 0):false;
}

STATUS Stack::push(int val) {
    try {
        Node* temp = new Node;
        temp->data = val;
        temp->next = head;
        head = temp;
        sz++;
        return SUCCESS;
    } catch (const std::bad_alloc& e) {
        return FAILURE;
    }
}

Stack::~Stack() {
    Node* mover = head;
    while (head) {
        mover=head;
        head=head->next;
        delete mover;
    }
}

int main(int argc, char* argv[]) {
    Stack stk = Stack();
    cout << stk.empty();
    for (int i = 0; i<10; i++) {
        stk.push(i);
    }
    cout << stk.empty();
    return 0;
}
