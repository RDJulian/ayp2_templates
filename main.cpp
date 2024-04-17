#include <iostream>
#include <vector>
#include "selection.hpp"

int main() {
    std::vector<int> vector = {3, 5, 7, 10, 9, 2, 1};
    selection<int>::sort(vector);
    std::cout << "Vector ordenado: ";
    for (auto iter = vector.begin(); iter != vector.end(); iter++) {
        if (iter == vector.end() - 1) {
            std::cout << *iter << "." << std::endl;
        } else {
            std::cout << *iter << ", ";
        }
    }
    return 0;
}
