#include <iostream>

using namespace std;

enum STATUS {FAILURE, SUCCESS};

typedef struct Node {
    int data;
    struct Node* next;
} Node;

class Stack {
    private:
      Node* head;
      int sz;

    public:
      Stack();
      ~Stack();
      STATUS push(int val);
      STATUS pop();
      int size();
      bool empty();
      int top();

};