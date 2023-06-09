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

