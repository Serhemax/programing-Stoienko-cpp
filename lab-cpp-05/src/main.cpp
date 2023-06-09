#include <iostream>
#include "list.hpp"

int main() {
    List<int> list;

    list.append(5);
    list.append(3);
    list.append(8);
    list.append(1);

    std::cout << "Array elements: ";
    list.print();

    int index = list.findIndex(3);
    if (index != -1) {
        std::cout << "Index of element 3: " << index << std::endl;
    }
    else {
        std::cout << "Element 3 not found" << std::endl;
    }

    list.sort();
    std::cout << "Sorted array: ";
    list.print();

    int minValue = list.getMin();
    std::cout << "Minimum value: " << minValue << std::endl;

    list.append(10);
    std::cout << "Array after appending 10: ";
    list.print();

    list.removeAt(2);
    std::cout << "Array after removing element at index 2: ";
    list.print();

    return 0;
}
