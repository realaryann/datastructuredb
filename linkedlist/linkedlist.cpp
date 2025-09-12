#include "linkedlist.hpp"

STATUS tail_insert(Node** head, int val) {
    try {
        Node* temp = new Node;
        temp->next = nullptr;
        temp->data = val;
        if (*head == nullptr) {
            *head = temp;
        } else {
            Node* mover = *head;
            while(mover->next) {
                mover=mover->next;
            }
            mover->next = temp;
        }
        return SUCCESS;
    } catch (const std::bad_alloc& e) {
        return FAILURE;
    }
}

STATUS head_insert(Node** head, int val) {
    try {
        Node* temp = new Node;
        temp->data = val;
        temp->next = *head;
        *head = temp;
        return SUCCESS;

    } catch (std::bad_alloc& e) {
        return FAILURE;
    }

}

STATUS head_pop(Node **head) {
    Node* temp = *head;
    (*head) = (*head)->next;
    delete temp;
    return SUCCESS;
}

STATUS pop(Node** head) {
    if ((*head)->next == nullptr) {
        delete *head;
        *head = nullptr;
    } else {
        Node* mover = *head;
        while (mover->next->next) {
            mover=mover->next;
        }
        Node* delnode = mover->next;
        mover->next = nullptr;
        delete delnode;
    }
    return SUCCESS;
}

int size(Node* head) {
    int sz = 0;
    while(head) {
        sz++;
        head=head->next;
    }
    return sz;
}

void print(Node *head) {
    while (head) {
        cout << head->data << " ";
        head=head->next;
    }
    cout << endl;
}

bool contains(Node* head, int val) {
    while(head) {
        if (head->data == val) {
            return true;
        }
        head=head->next;
    }
    return false;
}

int main(int argc, char * argv[]) {
    Node* head = nullptr;
    for(int i = 0; i<5; i++) {
        head_insert(&head, i);
    }
    for(int i = 0; i<3; i++) {
        head_pop(&head);
    }
    cout << (contains(head, 100));

    return 0;
}