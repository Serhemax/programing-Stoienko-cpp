#include <iostream>
#include <algorithm>

template <typename T>
class List {
private:
    T* array;
    size_t size;
    size_t capacity;

public:
    List() : array(nullptr), size(0), capacity(0) {}

    ~List() {
        delete[] array;
    }

    void print() const {
        for (size_t i = 0; i < size; i++) {
            std::cout << array[i] << " ";
        }
        std::cout << std::endl;
    }

    int findIndex(const T& element) const {
        for (size_t i = 0; i < size; i++) {
            if (array[i] == element) {
                return static_cast<int>(i);
            }
        }
        return -1;
    }

    void sort() {
        std::sort(array, array + size);
    }

    T getMin() const {
        if (size == 0) {
            throw std::logic_error("Array is empty");
        }
        T minElement = array[0];
        for (size_t i = 1; i < size; i++) {
            if (array[i] < minElement) {
                minElement = array[i];
            }
        }
        return minElement;
    }

    void append(const T& element) {
        if (size == capacity) {
            resizeArray();
        }
        array[size] = element;
        size++;
    }

    void removeAt(size_t index) {
        if (index >= size) {
            throw std::out_of_range("Invalid index");
        }
        for (size_t i = index; i < size - 1; i++) {
            array[i] = array[i + 1];
        }
        size--;
    }

private:
    void resizeArray() {
        if (capacity == 0) {
            capacity = 1;
        }
        else {
            capacity *= 2;
        }

        T* newArray = new T[capacity];
        for (size_t i = 0; i < size; i++) {
            newArray[i] = array[i];
        }
        delete[] array;
        array = newArray;
    }
};
