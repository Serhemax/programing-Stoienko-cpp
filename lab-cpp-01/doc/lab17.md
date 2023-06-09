## Лабораторна робота №17
####Тема: Вступ до ООП

Виконав:
Стоєнко Сергій Максимович
Група виконавця: КН-922Б

**Завдання:**
```
23. Птахи

У відділі орнітології почався перепис усіх зареєстрованих птахів. Вчені збирають наступну інформацію щодо птахів:

    Поля базового класу:
        Чи окольцьована птаха (наприклад: так, ні)
        Назва виду (наприклад: журавель, гусак)
        Вік птаха, місяців (наприклад: 2, 6, 8)
        Тип домівки птаха (структура, що містить площу у кв.см, висоту у см домівки птаха, а також кількість годівниць та наявність гнізда)
        Стать птаха (один з переліку: чоловіча, жіноча)
    Спадкоємець 1 - Перелітні птахи. Додаткові поля:
        Місяць відльоту у вирій (один з переліку: січень, лютий, березень, … , грудень)
        Місяць прильоту з вирію (один з переліку: січень, лютий, березень, … , грудень)
    Спадкоємець 2 - Екзотичні птахи. Додаткові поля:
        Мінімальна комфортна для життя температура, градусів Цельсію (наприклад: -5, +10, +15)
        Максимальна комфортна для життя температура, градусів Цельсію (наприклад: +5, +20, +40)
    Методи для роботи з колекцією:
        Знайти відсоткове відношення самок до самців у відділі
```
```
Для предметної галузі з розділу Розрахункове завдання / Iндивідуальні завдання розробити два класи:

    клас, що відображає сутність "базового класу", у тому числі:
        конструктор за замовчуванням, копіювання та конструктор з аргументами (реалізація конструкторів повинна бути продемонстрована за допомогою списків ініціалізацій);
        деструктор;
        гетери та сетери на поля класу;
        метод виводу об'єкта на екран:

void Phone::print();

    клас, що має у собі динамічний масив об’єктів базового класу та має в собі методи додавання, видалення елемента, отримання елемента по індексу (або ідентифікатору), вивід усіх елементів на екран. Рекомендовані сигнатури методів:
        додавання:

void List::addPhone(const Phone& phone, size_t pos = 0);

    видалення:

void List::removePhone(size_t index);

    отримання по індексу:

Phone& List::getPhone(size_t index);

    виведення усіх елементів:

void List::print(); 

    метод 1 обходу колекції. Приклад сигнатури такого методу (У наведеному прикладі реалізоване завдання пошуку самого дешевого телефону з заданою діагоналлю (повертається один телефон):

const Phone& List::findCheapestPhone(unsigned float diagonal);
```
**Основна частина:**

- **Опис роботи основної функції: **

 - Основні функції
entity.cpp / entity.h / list.cpp / list.h / main.cpp

 - Принцип роботи:
1) Створюємо клас птаха з потрібними параметрами параметрами та робимо для них геттери та сеттери
2) робимо конструктор зі всіма параметрами та дефолтний конструктор.
3) робимо функцію виводу інформації про птаха та копіювання птаха
4) створюємо список птахів, його параметри це масив птахів та розмір цього масиву
3)  реалізуємо функцію додавання птаха: створюємо масив розміром на 1 більше ніж наш попередній і копіюємо старий в новий масив та додаємо нову птицюб звищуємо параметр розміру масиву на 1
4) реалізовуєємо функцію видалення птаха: звільняємо пам'ять для птаха за заданним індексом, потім ідемо від цбого індекса до кінця масива та присвоюємо значення наступних елементів, до теперішнього знижуємо параметр розміру масиву на 1
5) робимо функцію випису масиву
6) реалізуєм функцію повернення птаха з індексу
7) реалізуєм функцію знаходження відсотка жіночої статті: підраховуємо кількість птахів жіночої та чоловічої статі та знаходимо відсоток жіночої статі

- **Перелік вхідних даних:**

 Для класу птиці:
        bool is_ringed - Чи окольцьована птаха (наприклад: так, ні)
        string type - Назва виду (наприклад: журавель, гусак)
        int age - Вік птаха, місяців (наприклад: 2, 6, 8)
        int area - площа домівки
        int height - висота домівки
        int feeders - кількість годівниць
        bool has_nest - наявність гнізда

        string gender - Стать птаха (один з переліку: чоловіча, жіноча)
для класу списку птиць лише дефолтний конструктор 

- **Дослідження результатів роботи програми**

   	Створили декілька птць та додали до масиву птиць

•	**Перевіримо чи зчиталась інформація за допомогою функції print_birds() та чи працює функція знаходження відсотка жіночої статті за допомогою функції printf():**
```
	Is ringed: 1
 Species name: soroka
 Age: 8 months
 Nest:
 Area: 10 sq. cm
 Height: 12 cm
 Number of feeders: 2
 Nest availability: 1
 Gender: woman

Bird 1:
 Is ringed: 1
 Type: soroka
 Age: 8 months
 Nest:
 Area: 10 sq. cm
 Height: 12 cm
 Number of feeders: 2
 Has nest: 1
 Gender: woman

Bird 2:
 Is ringed: 0
 Type: vorobej
 Age: 5 months
 Nest:
 Area: 20 sq. cm
 Height: 10 cm
 Number of feeders: 3
 Has nest: 0
 Gender: man

Bird 3:
 Is ringed: 1
 Type: soroka
 Age: 8 months
 Nest:
 Area: 10 sq. cm
 Height: 12 cm
 Number of feeders: 2
 Has nest: 1
 Gender: woman

Bird 4:
 Is ringed: 1
 Type: soroka
 Age: 8 months
 Nest:
 Area: 10 sq. cm
 Height: 12 cm
 Number of feeders: 2
 Has nest: 1
 Gender: woman

Ratio of Women: 75.000000
```
**Як бачимо, результати співпадають, тому функції працюють**.

** Також зробимо тест **

```
[==========] Running 3 tests from 1 test suite.
[----------] Global test environment set-up.
[----------] 3 tests from ProgramingLab01
[ RUN      ] ProgramingLab01.AddBird
[       OK ] ProgramingLab01.AddBird (0 ms)
[ RUN      ] ProgramingLab01.DeleteBird
[       OK ] ProgramingLab01.DeleteBird (0 ms)
[ RUN      ] ProgramingLab01.GenderRatio
[       OK ] ProgramingLab01.GenderRatio (0 ms)
[----------] 3 tests from ProgramingLab01 (0 ms total)

[----------] Global test environment tear-down
[==========] 3 tests from 1 test suite ran. (0 ms total)
[  PASSED  ] 3 tests.

llvm-profdata merge -sparse dist/test.profraw -o dist/test.profdata
llvm-cov report dist/test.bin -instr-profile=dist/test.profdata src/*.cpp
Filename                                                                        Regions    Missed Regions     Cover   Functions  Missed Functions  Executed       Lines      Missed Lines     Cover    Branches   Missed Branches     Cover
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/home/serhii/tnp/tnpp/programing-Stoienko-cpp/lab-cpp-02/src/test.cpp         4                 0   80.00%           4                 0   80.00%          31                 0   80.00%           0                 0         -
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
TOTAL                                                                                 4                 0   80.00%           4                 0   80.00%          31                 0   80.00%           0                 0         -
```



**Структура проекту лабораторної роботи**:

├── a.out
├── CMakeLists.txt
├── dist
│   ├── main.bin
│   ├── test.bin
├── doc
├── Doxyfile
├── leaks_suppr.txt
├── Makefile
├── README.md
├── src
│   ├── entity.cpp
│   ├── entity.h
│   ├── list.cpp
│   ├── list.h
│   └── main.cpp
└── test
    └── test.cpp
 **Висновки**: при виконанні лабораторної роботи опанував основи ООП.

 **Код проекту**:

 ** main.cpp : **
```
#include <iostream>
#include <cmath>
#include "entity.h"
#include "list.h"
using namespace std;

int main()
{
    Bird a;
    a.print_bird();
    Bird b (false, "vorobej", 5, 20, 10, 3, false, "man");

    List birds;
    birds.addBird(a);
    birds.addBird(b);
    birds.addBird(Bird());
    birds.addBird(Bird());

    printf("Ratio of Women: %f ", birds.get_gender_ratio());


    return 0;
}
```

** list.cpp **

```
#include "list.h"
#include "entity.h"
 
int List::getNum_birds() const
{
    return num_birds;
}

void List::addBird(const Bird& bird) {
    Bird** temp = new Bird * [num_birds + 1];
    for (int i = 0; i < num_birds; i++) {
        temp[i] = birds[i];
    }
    temp[num_birds] = new Bird(bird);
    delete[] birds;
    birds = temp;
    num_birds++;
}

void List::deleteBird(int idx) {
    if (idx >= 0 && idx < num_birds) {
        delete birds[idx];
        for (int i = idx; i < num_birds - 1; i++) {
            birds[i] = birds[i + 1];
        }
        num_birds--;
    }
}

Bird& List::getBird(int idx) const{
    return *birds[idx];
}

void List::print_birds() const{
    for (int i = 0; i < num_birds; i++)
    {
        printf("Bird %d:\n", i + 1);
        printf(" Is ringed: %d\n", birds[i]->getIsringed());
        printf(" Type: %s\n", birds[i]->getType().c_str());
        printf(" Age: %d months\n", birds[i]->getAge());
        printf(" Nest:\n");
        printf(" Area: %d sq. cm\n", birds[i]->getArea());
        printf(" Height: %d cm\n", birds[i]->getHeight());
        printf(" Number of feeders: %d\n", birds[i]->getFeeders());
        printf(" Has nest: %d\n", birds[i]->getHasnest());
        printf(" Gender: %s\n", birds[i]->getGender().c_str());
        printf("\n");
    }
}

float List::get_gender_ratio() const{
    int males = 0;
    int females = 0;

    for (int i = 0; i < num_birds; i++) {
        if (birds[i]->getGender() == "man") {
            males++;
        }
        else if (birds[i]->getGender() == "woman") {
            females++;
        }
    }

    if (males + females > 0) {
        return static_cast<float>(females) / static_cast<float>(males + females) * 100.0f;
    }
    else {
        return 0.0f;
    }
}

List::List() {
    birds = nullptr;
    num_birds = 0;
}

List::~List() {
    if (birds != nullptr) {
        for (int i = 0; i < num_birds; i++) {
            delete birds[i];
        }
        delete[] birds;
    }
}
```

**list.h**

```
#pragma once
#include "entity.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

class List {
private:
	Bird** birds = NULL;
	int num_birds;
public:
    	int getNum_birds() const;

	void addBird(const Bird &bird);
	void deleteBird(int idx);
	Bird& getBird(int idx) const;

	void print_birds() const;
	float get_gender_ratio() const;

	 List();
    	~List();
};
```
**entity.cpp**
```
#include "entity.h"
using namespace std;

Bird::Bird(bool is_ringed_in, string type_in, int age_in, int area_in, int height_in,
    int feeders_in, bool has_nest_int, string gender_in) {
    this->is_ringed = is_ringed_in; // ×è îêîëüöüîâàíà ïòàõà (òàê, í³)
    this->type = type_in;    // Íàçâà âèäó
    this->age = age_in;       // Â³ê ïòàõà, ì³ñÿö³â
    this->area = area_in;  // Ïëîùà ó êâ. ñì
    this->height = height_in;   // Âèñîòà ó ñì
    this->feeders = feeders_in;  // Ê³ëüê³ñòü ãîä³âíèöü
    this->has_nest = has_nest_int; // Íàÿâí³ñòü ãí³çäà (òàê, í³)
    this->gender = gender_in;    // Òèï äîì³âêè ïòàõà
}

Bird::Bird() {
    this->is_ringed = true; // ×è îêîëüöüîâàíà ïòàõà (òàê, í³)
    this->type = "soroka";    // Íàçâà âèäó
    this->age = 8;       // Â³ê ïòàõà, ì³ñÿö³â
    this->area = 10;  // Ïëîùà ó êâ. ñì
    this->height = 12;   // Âèñîòà ó ñì
    this->feeders = 2;  // Ê³ëüê³ñòü ãîä³âíèöü
    this->has_nest = true; // Íàÿâí³ñòü ãí³çäà (òàê, í³)
    this->gender = "woman";    // Òèï äîì³âêè ïòàõà
}

Bird::Bird(const Bird& copy) {
    this->is_ringed = copy.is_ringed; // ×è îêîëüöüîâàíà ïòàõà (òàê, í³)
    this->type = copy.type;    // Íàçâà âèäó
    this->age = copy.age;       // Â³ê ïòàõà, ì³ñÿö³â
    this->area = copy.area;  // Ïëîùà ó êâ. ñì
    this->height = copy.height;   // Âèñîòà ó ñì
    this->feeders = copy.feeders;  // Ê³ëüê³ñòü ãîä³âíèöü
    this->has_nest = copy.has_nest; // Íàÿâí³ñòü ãí³çäà (òàê, í³)
    this->gender = copy.gender;    // Òèï äîì³âêè ïòàõà
}

// Ôóíêö³ÿ äëÿ âèâåäåííÿ ìàñèâó ïòàõ³â íà åêðàí
void Bird::print_bird() const{
    printf(" Is ringed: %d\n", is_ringed);
    printf(" Species name: %s\n", type.c_str());
    printf(" Age: %d months\n", age);
    printf(" Nest:\n");
    printf(" Area: %d sq. cm\n", area);
    printf(" Height: %d cm\n", height);
    printf(" Number of feeders: %d\n", feeders);
    printf(" Nest availability: %d\n", has_nest);
    printf(" Gender: %s\n", gender.c_str());
    printf("\n");
}

bool Bird::getIsringed() const
{
    return is_ringed;
}

void Bird::setIsringed(bool isringed_)
{
    is_ringed = isringed_;
}

string Bird::getType() const
{
    return type;
}

void Bird::setType(string type_)
{
    this->type = type_;
}

int Bird::getAge() const
{
    return age;
}

void Bird::setAge(int age_)
{
    this->age = age_;
}

int Bird::getArea() const
{
    return area;
}

void Bird::setArea(int area_)
{
    this->area = area_;
}

int Bird::getHeight() const
{
    return height;
}

void Bird::setHeight(int height_)
{
    this->height = height_;
}

int Bird::getFeeders() const
{
    return feeders;
}

void Bird::setFeeders(int feeders_)
{
    this->feeders = feeders_;
}

bool Bird::getHasnest() const
{
    return has_nest;
}

void Bird::setHasnest(bool hasnest_)
{
    has_nest = hasnest_;
}

string Bird::getGender() const
{
    return gender;
}

void Bird::setGender(string gender_)
{
    this->gender = gender_;
}
```

**entity.h**
```
#include <string>
#include <stdio.h>
#include <stdlib.h>

#ifndef ENTITY_H
#define ENTITY_H
using namespace std;

class Bird {
private:
        bool is_ringed;
        string type;  
        int age;    
        
        int area;    
        int height;   
        int feeders;  
        bool has_nest; 

        string gender;
public:

    Bird();

    Bird(bool is_ringed_in, string type_in, int age_in, int area_in, int height_in,
        int feeders_in, bool has_nest_int, string gender);

    Bird(const Bird& copy);

    ~Bird() {};

    bool getIsringed() const;
    void setIsringed(bool isringed_);

    string getType() const;
    void setType(string type_);

    int getAge() const;
    void setAge(int age_);

    int getArea() const;
    void setArea(int area_);

    int getHeight() const;
    void setHeight(int height_);

    int getFeeders() const;
    void setFeeders(int feeders_);

    bool getHasnest() const;
    void setHasnest(bool hasnest_);

    string getGender() const;
    void setGender(string gender_);

    void print_bird() const;

};
#endif
```

**test.cpp**
```
/**
 * @file test.cpp
 * @brief 
 *
 * @author Davydov V.
 * @date 30-jul-2022
 * @version 1.0
 */

#include "list.h"

#include <gtest/gtest.h>

TEST(ProgramingLab01, AddBird) {
  List list;
  Bird bird1(true, "Sparrow", 12, 100, 20, 2, true, "man");
  Bird bird2(false, "Robin", 8, 80, 18, 1, false, "woman");

  list.addBird(bird1);
  list.addBird(bird2);

  ASSERT_EQ(list.getNum_birds(), 2);
}

TEST(ProgramingLab01, DeleteBird) {
  List list;
  Bird bird1(true, "Sparrow", 12, 100, 20, 2, true, "man");
  Bird bird2(false, "Robin", 8, 80, 18, 1, false, "woman");

  list.addBird(bird1);
  list.addBird(bird2);

  list.deleteBird(0);

  ASSERT_EQ(list.getNum_birds(), 1);
  ASSERT_EQ(list.getBird(0).getType(), bird2.getType());
}

TEST(ProgramingLab01, GenderRatio) {
  List list;
  Bird bird1(true, "Sparrow", 12, 100, 20, 2, true, "man");
  Bird bird2(false, "Robin", 8, 80, 18, 1, false, "woman");
  Bird bird3(true, "Finch", 10, 90, 15, 3, true, "woman");

  list.addBird(bird1);
  list.addBird(bird2);
  list.addBird(bird3);

  float genderRatio = list.get_gender_ratio();

  ASSERT_FLOAT_EQ(genderRatio, 66.66666f);
}

```