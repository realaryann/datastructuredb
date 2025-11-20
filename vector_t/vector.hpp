#include <iostream>

template<class T>
class Vector {
    private:
        T* data;
        int size;
        int capacity;
    public:
        Vector();
        // Rule of 5
        Vector(const Vector<T> &vec);
        ~Vector();
        Vector<T>& operator=(const Vector<T> &vec);
        Vector(Vector<T> &&vec);
        Vector<T>& operator=(Vector<T> &&vec);

        int Size() const;
        int Capacity() const;
        void Append(const T val);
        void Pop();

        //Printing
        template<class U>
        friend std::ostream& operator<<(std::ostream& out, const Vector<U>& vec);
};

template<class T>
Vector<T>::Vector(Vector<T> &&vec) {
    size = vec.size;
    capacity = vec.capacity;
    data = vec.data;
    vec.data = nullptr;
}

template<class T>
Vector<T>& Vector<T>::operator=(Vector<T> &&vec) {
    if (this != vec) {
        delete[] this->data;
        this->size = vec.size;
        this->capacity = vec.capacity;
        this->data = vec.data;
        vec.data = nullptr;
    }
    return *this;
}

template<class T>
Vector<T>& Vector<T>::operator=(const Vector<T> &vec) {
    if (this != &vec) {
        T* new_data = new T[vec.capacity];
        for (int i = 0; i<vec.size; i++) {
            new_data[i] = vec.data[i];
        }
        delete[] this->data;
        this->data = new_data;
        this->capacity = vec.capacity;
        this->size = vec.size;
    }
    return *this;
}

template<class T>
Vector<T>::Vector() {
    size = 0;
    capacity=20;
    data = new T[capacity];
}

template<class T>
Vector<T>::Vector(const Vector<T> &vec): size(vec.size), capacity(vec.capacity), data(new T[capacity]) {
    for (int i = 0; i<vec.size; i++) {
        data[i] = vec.data[i];
    }
}

template<class T>
Vector<T>::~Vector() {
    delete[] data;
    data = nullptr;
}

template<class T>
int Vector<T>::Size() const {
    return size;
}

template<class T>
int Vector<T>::Capacity() const {
    return capacity;
}

template<class T>
void Vector<T>::Append(const T val) {
    if (size >= capacity) {
        T* temp = new T[capacity*2];
        for (int i = 0; i<size; i++) {
            temp[i] = data[i];
        }
        delete[] data;
        data = temp;
        capacity *= 2;
    }
    data[size] = val;
    size++;
}

template<class T>
void Vector<T>::Pop() {
    if (size > 0) {
        size--; 
    }
}

template<class U>
std::ostream& operator<<(std::ostream& out, const Vector<U>& vec) {
    for (int i = 0; i<vec.size; i++) {
        out << vec.data[i] << " ";
    }
    return out;
}
