#include <iostream>
#include "my_vector.h"

using namespace containers;

namespace product {

class Product {
public:
    Product(char* name, int quantity, double price) : name_(name), quantity_(quantity), price_(price) {}
    Product(const Product & p) : name_(p.name_), quantity_(p.quantity_), price_(p.price_) {}

    friend std::ostream & operator<<(std::ostream & stream, const Product & p);

private:
    char * name_;  // Указатель владеет C-style строкой, на которую указывает.
    int quantity_;
    double price_;
};

std::ostream & operator<<(std::ostream & stream, const Product & p) {
    stream << p.name_ << " " << p.quantity_ << " " << p.price_;
    return stream;
}

void print(const containers::my_vector<product::Product>& v) {
    std::cout << v << std::endl;
}

}  // namespace product

template <typename T>
void test_my_vector(containers::my_vector<T> test) {
    std::cout << "Current capacity: " << test.capacity() << std::endl;
    std::cout << "Current size: " << test.size() << std::endl;

    std::cout << "Reserving memory for vector" << std::endl;
    int new_size = test.size() + rand() % 10;
    test.reserve(new_size);

    std::cout << "Current capacity: " << test.capacity() << std::endl;
    std::cout << "Current size: " << test.size() << std::endl;

    std::cout << "Popping last value" << std::endl;
    T last = test.pop_back();
    std::cout << last << std::endl;
    std::cout << "Current size: " << test.size() << std::endl;
    std::cout << "Pushing last value" << std::endl;
    test.push_back(last);
    std::cout << "Printing vector" << std::endl;
    std::cout << test << std::endl;
    std::cout << "Current size: " << test.size() << std::endl;
    for (int i = 0; i < test.size(); i++) {
        std::cout << "(id=" << i << ",value=" << test[i] << ")" << std::endl;
    }
    std::cout << "Is vector empty? " << test.empty() << std::endl;
    std::cout << "Clearing vector" << std::endl;
    test.clear();
    std::cout << "Is vector empty? " << test.empty() << std::endl;
}

template <typename T>
void test_my_vector_default_constructible() {
    int new_size = rand() % 10;
    std::cout << "Creating vector with default constructor " << std::endl;
    containers::my_vector<T> test(new_size);
    new_size = rand() % 25;
    std::cout << "Current vector capacity: " << test.capacity() << std::endl;
    std::cout << "Resizing vector to " << new_size << std::endl;
    test.resize(new_size);
    std::cout << "New vector capacity: " << test.capacity() << std::endl;
}

int main() {
    containers::my_vector<int> test1{1, 2, 3};
    test_my_vector(test1);

    containers::my_vector<product::Product> test2{product::Product("test", 1, 2), product::Product("asdf", 5, 1)};
    test_my_vector(test2);

    test_my_vector_default_constructible<int>();

    return 0;
}
