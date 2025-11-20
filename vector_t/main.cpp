#include "vector.hpp"

int main() {
    Vector<int> vec;
    vec.Append(1);
    vec.Append(2);
    Vector<int> v2 = vec;
    v2.Pop();
    std::cout<<v2;
    return 0;
}