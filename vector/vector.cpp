#include <iostream>
#include "vector.hpp"

int Vector::get_size() {
    return size;
}

int Vector::get_capacity() {
    return capacity;
}

STATUS Vector::shrink_to_fit() {
    try {
        int* temp = new int[this->size];
        for (int i = 0; i<this->size; i++) {
            temp[i] = this->data[i];
        }
        delete[]  this->data;
        this->data=temp;
        this->capacity = this->size;
        return SUCCESS;
    }
    catch(const std::bad_alloc& e) {
        return FAILURE;
    }
}

STATUS Vector::pop_back() {
    if (this->size > 0) {
        this->size--;
        return SUCCESS;
    }
    return FAILURE;
}

STATUS Vector::print() {
    for (int i = 0; i<this->size; i++) {
        cout << this->data[i] << " ";
    }
    return SUCCESS;
}

STATUS Vector::push_back(int x) {
    // Check if need to resize
    if (this->size >= this->capacity) {
        int* temp = new int[this->capacity*2];
        for (int i = 0; i < this->size; i++) {
            temp[i] = this->data[i];
        }
        this->capacity = this->capacity*2;
        delete[] this->data;
        this->data = temp;
    } 
    // Resize done, just append the element
    this->data[this->size] = x;
    this->size++;
    return SUCCESS;
}

Vector::Vector() {
    this->size = 0;
    this->capacity = 10;
    this->data = new int[this->capacity];
}

Vector::~Vector() {
    delete[] this->data;
    this->data = nullptr;
}


int main(int argc, char* argv[]) {
    Vector vec = Vector();
    for (int i = 0; i<12; i++) {
        vec.push_back(i);
    }
    cout << vec.get_capacity() << endl;
    vec.shrink_to_fit();
    cout << vec.get_capacity() << endl;
    vec.push_back(12);
    vec.print();
    return 0;
}