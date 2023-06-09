## Лабораторна робота №21
####Тема: Шаблонні функції та класи

Виконав:
Стоєнко Сергій Максимович
Група виконавця: КН-922Б

**Завдання:**
```

    Зробити шаблоний клас-список (на базі динамічного масиву), що має шаблоноване поле масиву (для будь-якого існуючого типу даних)
    Створити наступні методи:
        вивод вмісту масиву на екран;
        визначити індекс переданого елемента в заданому масиві;
        відсортувати елементи масиву;
        визначити значення мінімального елемента масиву;
        додати елемент до кінця масиву;
        видалити елемент з масиву за індексом.

```
**Основна частина:**

- **Опис роботи основної функції: **

 - Основні функції
list.hpp / main.cpp

 - Принцип роботи:
1) Створюємо клас List із шаблонним масивом
2) Робимо функцію виводу вмісту масиву на екран
3) Робимо функцію знаходження індекса елемента, проходимось по масиву і порівнюємо значення елемента зі значаеннями масива
4) Робимо функцію сортування, сортуєм масив
5) Робимо функцію знаходження мінімального масиву, проходимось по всім елементам масива та знаходимо мінімальний, порівнюючи їх
6) Робимо функцію додавання елементу до кінця масиву. Збільшуємо масив та додаємо елемент на кінець цього масиву
7) Робимо функцію видалення елементу з масиву за індексом. Замінюємо всі елементи масиву починаючи з індекса на наступний.

- **Перелік вхідних даних:**

тільки дефолтний конструктор з розміром, кількістю зберігання та маисвом.
- **Дослідження результатів роботи програми**

```
Array elements: 5 3 8 1
Index of element 3: 1
Sorted array: 1 3 5 8
Minimum value: 1
Array after appending 10: 1 3 5 8 10
Array after removing element at index 2: 1 3 8 10
```
**Як бачимо, результати співпадають, тому функції працюють**.

** Також зробимо тест **

```
Array elements: 5 3 8 1 
Index of element 3: 1
Sorted array: 1 3 5 8 
Minimum value: 1
Array after appending 10: 1 3 5 8 10 
Array after removing element at index 2: 1 3 8 10

llvm-profdata merge -sparse dist/test.profraw -o dist/test.profdata
llvm-cov report dist/test.bin -instr-profile=dist/test.profdata src/*.cpp
Filename                                                                        Regions    Missed Regions     Cover   Functions  Missed Functions  Executed       Lines      Missed Lines     Cover    Branches   Missed Branches     Cover
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/home/serhii/tnp/tnpp/programing-Stoienko-cpp/lab-cpp-02/src/test.cpp         4                 0   100.00%           100                 0   100.00%          31                 0   100.00%           0                 0         -
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
TOTAL                                                                                 4                 0   100.00%           4                 0   100.00%          31                 0   100.00%           0                 0         -
```



**Структура проекту лабораторної роботи**:

.
├── a.out
├── dist
│   ├── main.bin
│   ├── test.bin
│   └── test.bin-test.gcda
├── doc
├── Doxyfile
├── leaks_suppr.txt
├── Makefile
├── README.md
├── src
│   ├── list.hpp
│   └── main.cpp
└── test
    └── test.cpp
 **Висновки**: при виконанні лабораторної роботи були набуті навички створення шаблонних функцій та классів.

 **Код проекту**:

 ** main.cpp : **
```
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
```

** list. hpp **

```
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
```

**test.cpp**
```
#include "list.hpp"

#include <gtest/gtest.h>

TEST(ProgramingLab05, PrintTest) {
    List<int> list;
    list.append(5);
    list.append(3);
    list.append(8);

    // Перенаправлення виводу cout для перевірки вмісту масиву
    testing::internal::CaptureStdout();
    list.print();
    std::string output = testing::internal::GetCapturedStdout();

    ASSERT_EQ(output, "5 3 8 \n");
}

TEST(ProgramingLab05, FindIndexTest) {
    List<std::string> list;
    list.append("apple");
    list.append("banana");
    list.append("orange");

    int index = list.findIndex("banana");

    ASSERT_EQ(index, 1);
}

TEST(ProgramingLab05, SortTest) {
    List<double> list;
    list.append(5.7);
    list.append(2.1);
    list.append(8.9);
    list.append(1.5);

    list.sort();

    ASSERT_DOUBLE_EQ(list.getMin(), 1.5);
}

TEST(ProgramingLab05, AppendTest) {
    List<int> list;
    list.append(5);
    list.append(3);

    // Перевірка, чи правильно додано елементи
    ASSERT_EQ(list.findIndex(5), 0);
    ASSERT_EQ(list.findIndex(3), 1);
}

TEST(ProgramingLab05, RemoveAtTest) {
    List<char> list;
    list.append('a');
    list.append('b');
    list.append('c');

    list.removeAt(1);

    // Перевірка, чи правильно видалено елемент
    ASSERT_EQ(list.findIndex('a'), 0);
    ASSERT_EQ(list.findIndex('c'), 1);
}


```