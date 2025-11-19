#include "vector.hpp"

int main() {
    Vector<int> vec;
    vec.Append(1);
    vec.Append(2);
    std::cout << vec;
    return 0;
}