#pragma once
#include <iostream>

using namespace std;

enum STATUS {FAILURE, SUCCESS};

struct Node {
    int data;
    Node* next;
};

STATUS tail_insert(Node** head, int val);
STATUS head_insert(Node** head, int val);
STATUS head_pop(Node **head);
STATUS pop(Node** head);
void print(Node* head);
int size(Node* head);
bool contains(Node* head, int val);
