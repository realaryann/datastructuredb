using namespace std;

enum STATUS {FAILURE, SUCCESS};

class Vector {
    private:
    int* data; // array to hold info
    int size; // active size of the array
    int capacity; // current max capacity

    public:
    Vector();
    STATUS print();
    STATUS push_back(int x);
    STATUS pop_back();
    int get_size();
    int get_capacity();
    STATUS shrink_to_fit();
    ~Vector();
};