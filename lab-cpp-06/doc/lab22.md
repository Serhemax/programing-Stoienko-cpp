## Лабораторна робота №22
####Тема: Вступ до Стандартної бібліотеки шаблонів STL

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
Поширити реалізацію лабораторної роботи "Поліморфірзм" наступним шляхом:

    замінити масив та CRUD (create/read/update/delete) методи роботи з ним на використання STL
    для предметної галузі з розділу Розрахункове завдання / Iндивідуальні завдання реалізувати/оновити всі методи роботи з колекцією на використання функцій STL
    додати функцію сортування коллекції з використанням функтора
    додати функцію об'єднання двох класів-списків
```
**Основна частина:**

- **Опис роботи основної функції: **

 - Основні функції
entity.cpp / entity.h / list.cpp / list.h / main.cpp

 - Принцип роботи:
1) замінюєм масив birds на <vector> birds
2) Змінюєм CRUD методи відповідно push_back для додавання птиці, erase для видалення, замість циклів for (int i...) будемо використовувати ітерацію кожним елементом вектора.
3) сортування зробив по віку птахів за допомогою функції sort
4)  об'єднання двох класів-списків робимо за допомогою функції insert()
5) Додав функцію getAverageAgeOfNonRingedBirds, перевіряємо чи птах окольцьований, якщо ні, то звишуєм кількість на 1, та додаємо вік птаха до загального віку. Після ітерації по масиву повертаєм середній вік: загальний вік/ кількість неокальцованих птахів

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
    
**Перевіримо чи зчиталась інформація з файлу, та чи записалась в інший файл та чи працює функція сортування**
```
Is ringed: 1
 Type: soroka
 Age: 8 months
 Nest:
  Area: 10sq. cm
  Height: 12cm
  Number of feeders: 2
  Has nest: 1
  Gender: woman

Bird 1:
 Is ringed: 1
 Type: soroka
 Age: 8 months
 Nest:
  Area: 10sq. cm
  Height: 12cm
  Number of feeders: 2
  Has nest: 1
  Gender: woman


Bird 2:
 Is ringed: 0
 Type: vorobej
 Age: 5 months
 Nest:
  Area: 20sq. cm
  Height: 10cm
  Number of feeders: 3
  Has nest: 0
  Gender: man


Bird 3:
 Is ringed: 1
 Type:  Sparrow
 Age: 3 months
 Nest:
  Area: 50sq. cm
  Height: 10cm
  Number of feeders: 2
  Has nest: 1
  Gender:  man


Bird 4:
 Is ringed: 1
 Type: soroka
 Age: 8 months
 Nest:
  Area: 10sq. cm
  Height: 12cm
  Number of feeders: 2
  Has nest: 1
  Gender: woman


Bird 5:
 Is ringed: 1
 Type: soroka
 Age: 8 months
 Nest:
  Area: 10sq. cm
  Height: 12cm
  Number of feeders: 2
  Has nest: 1
  Gender: woman


Bird 1:
 Is ringed: 1
 Type:  Sparrow
 Age: 3 months
 Nest:
  Area: 50sq. cm
  Height: 10cm
  Number of feeders: 2
  Has nest: 1
  Gender:  man


Bird 2:
 Is ringed: 1
 Type:  Sparrow
 Age: 3 months
 Nest:
  Area: 50sq. cm
  Height: 10cm
  Number of feeders: 2
  Has nest: 1
  Gender:  man


Bird 3:
 Is ringed: 1
 Type:  Sparrow
 Age: 3 months
 Nest:
  Area: 50sq. cm
  Height: 10cm
  Number of feeders: 2
  Has nest: 1
  Gender:  man


Bird 4:
 Is ringed: 1
 Type:  Sparrow
 Age: 3 months
 Nest:
  Area: 50sq. cm
  Height: 10cm
  Number of feeders: 2
  Has nest: 1
  Gender:  woman
```
**Як бачимо, результати співпадають, тому функції працюють**.

** Також зробимо тест **

```
LLVM_PROFILE_FILE="dist/test.profraw" ./dist/test.bin
Running main() from ./googletest/src/gtest_main.cc
[==========] Running 10 tests from 1 test suite.
[----------] Global test environment set-up.
[----------] 10 tests from ProgramingLab06
[ RUN      ] ProgramingLab06.AddBird
[       OK ] ProgramingLab06.AddBird (0 ms)
[ RUN      ] ProgramingLab06.DeleteBird
[       OK ] ProgramingLab06.DeleteBird (0 ms)
[ RUN      ] ProgramingLab06.GenderRatio
[       OK ] ProgramingLab06.GenderRatio (0 ms)
[ RUN      ] ProgramingLab06.ReadFromFile
[       OK ] ProgramingLab06.ReadFromFile (1 ms)
[ RUN      ] ProgramingLab06.AssigmentBird
[       OK ] ProgramingLab06.AssigmentBird (0 ms)
[ RUN      ] ProgramingLab06.BirdEqual
[       OK ] ProgramingLab06.BirdEqual (0 ms)
[ RUN      ] ProgramingLab06.BirdNotEQual
[       OK ] ProgramingLab06.BirdNotEQual (0 ms)
[ RUN      ] ProgramingLab06.AverageAgeOfNonRingedBirds
[       OK ] ProgramingLab06.AverageAgeOfNonRingedBirds (0 ms)
[ RUN      ] ProgramingLab06.SortBirds
[       OK ] ProgramingLab06.SortBirds (0 ms)
[ RUN      ] ProgramingLab06.MergeLists
[       OK ] ProgramingLab06.MergeLists (0 ms)
[----------] 10 tests from ProgramingLab06 (2 ms total)

[----------] Global test environment tear-down
[==========] 10 tests from 1 test suite ran. (2 ms total)
[  PASSED  ] 10 tests.
llvm-profdata merge -sparse dist/test.profraw -o dist/test.profdata
llvm-cov report dist/test.bin -instr-profile=dist/test.profdata src/*.cpp
Filename                                                                        Regions    Missed Regions     Cover   Functions  Missed Functions  Executed       Lines      Missed Lines     Cover    Branches   Missed Branches     Cover
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/home/serhii/tnp/tnpp/programing-Stoienko-cpp/lab-cpp-02/src/test.cpp         4                 0   80.00%           4                 0   80.00%          31                 0   80.00%           0                 0         -
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
TOTAL                                                                                 4                 0   85.00%           4                 0   85.00%          31                 0   84.00%           0                 0         -
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
 **Висновки**: при виконанні лабораторної роботи були набуті навички праці з SDL бібліотекою.

 **Код проекту**:

 ** main.cpp : **
```
#include <iostream>
#include <cmath>
#include "entity.h"
#include "list.h"
#include <string>
#include <sstream>

int main()  
{
    Bird a;
    Bird b (false, "vorobej", 5, 20, 10, 3, false, "man");

    std::string line = "1, Sparrow, 3, 50, 10, 2, 1, man";
    
    Bird c = Bird::createBirdFromInputString(line);

    List birds;
    
    birds.addBird(a);
    birds.addBird(b);
    birds.addBird(c);
    birds.addBird(Bird());
    birds.addBird(Bird());

    std::cout << birds.getBird(0).toString();

    std::cout << birds;

    std::ifstream inputFile("input.txt");
    if (inputFile) {
        inputFile >> birds;
        inputFile.close();
    }
    else {
        std::cout << "Error opening input file\n";
    }

    // Виведення у файл
    std::ofstream outputFile("output.txt");
    if (outputFile) {
        outputFile << birds;
        outputFile.close();
    }
    else {
        std::cout << "Error opening output file\n";
    }

    birds.sortBirds();

    std::cout << birds;


    return 0;
}
```

** list.cpp **

```
#include "list.h"
#include <fstream> 
#include <limits>

long unsigned int List::getNum_birds() const {
    return birds.size(); 
}

std::vector<Bird> List::getBirds() const
{
    return birds;
}

const Bird& List::getBird(int idx) const
{
    return birds.at(idx);
}

void List::addBird(const Bird& bird) {
    birds.push_back(bird); 
}

void List::deleteBird(long unsigned int idx) {
    if (idx < birds.size()) {
        birds.erase(birds.begin() + idx); 
    }
}

float List::get_gender_ratio() const {
    int males = 0;
    int females = 0;

    for (const Bird& bird : birds) {
        if (bird.getGender() == "man") {
            males++;
        }
        else if (bird.getGender() == "woman") {
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

float List::getAverageAgeOfNonRingedBirds() const {
    int numNonRingedBirds = 0;
    int totalAge = 0;

    for (const Bird& bird : birds) {
        if (!bird.getIsringed()) {
            numNonRingedBirds++;
            totalAge += bird.getAge();
        }
    }

    if (numNonRingedBirds > 0) {
        return static_cast<float>(totalAge) / static_cast<float>(numNonRingedBirds);
    }
    else {
        return 0.0f;
    }
}

void List::sortBirds() {
    struct BirdComparator {
        bool operator()(const Bird& bird1, const Bird& bird2) {
            return bird1.getAge() < bird2.getAge();
        }
    };

    std::sort(birds.begin(), birds.end(), BirdComparator());
}

// Об'єднання двох класів-списків
void List::mergeLists(const List& otherList) {
    birds.insert(birds.end(), otherList.birds.begin(), otherList.birds.end());
}

void List::clearBirds() {
    birds.clear();
}

std::istream& operator>>(std::istream& is, List& list) {
    list.clearBirds(); // Clear the vector

    int num_birds;
    std::cout << "numBirds:\n";
    is >> num_birds;
    is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::string line;
    for (int i = 0; i < num_birds; i++) {
        std::cout << "Bird " << (i + 1) << ":\n";
        std::cout << "print: Is ringed, Type, Age, in Nest: Area, Height, Number of feeders, Has nest; Gender\n";
        if (getline(is, line)) {
            Bird bird = Bird::createBirdFromInputString(line);
            list.addBird(bird);
        }
    }

    return is;
}

std::ostream& operator<<(std::ostream& os, const List& list) {
    int i = 1;
    for (const Bird& bird : list.getBirds()) {
        os << "Bird " << i++ << ":\n";
        os << bird.toString() << "\n";
    }
    return os;
}

std::ifstream& operator>>(std::ifstream& ifs, List& list) {
    list.clearBirds(); // Clear the vector

    int numBirds;
    ifs >> numBirds;
    ifs.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::string line;
    for (int i = 0; i < numBirds; i++) {
        if (!getline(ifs, line)) {
            break;
        }
        Bird bird = Bird::createBirdFromInputString(line);
        list.addBird(bird);
    }

    return ifs;
}

std::ofstream& operator<<(std::ofstream& ofs, const List& list) {
    int i = 1;
    for (const Bird& bird : list.getBirds()) {
        ofs << "Bird " << i++ << ":\n";
        ofs << "  Is ringed: " << bird.getIsringed() << "\n";
        ofs << "  Type: " << bird.getType() << "\n";
        ofs << "  Age: " << bird.getAge() << "\n";
        ofs << "  Nest:\n";
        ofs << "    Area: " << bird.getArea() << "\n";
        ofs << "    Height: " << bird.getHeight() << "\n";
        ofs << "    Number of feeders: " << bird.getFeeders() << "\n";
        ofs << "    Has nest: " << bird.getHasnest() << "\n";
        ofs << "  Gender: " << bird.getGender() << "\n";
        ofs << "\n";
    }

    return ofs;
}


```

**list.h**

```
#pragma once
#include "entity.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector> 
#include <algorithm>

class List {
private:
    std::vector<Bird> birds; 
public:
    long unsigned int getNum_birds() const;
    std::vector<Bird> getBirds() const;

    void readFromFile(const std::string& filename);
    void writeToFile(const std::string& filename) const;

    void addBird(const Bird& bird);
    void deleteBird(long unsigned int idx);
    void clearBirds();
    const Bird& getBird(int idx) const;

    std::string toString() const;
    float get_gender_ratio() const;
    float getAverageAgeOfNonRingedBirds() const;

    void mergeLists(const List& otherList);
    void sortBirds();

    friend std::istream& operator>>(std::istream& is, List& list);
    friend std::ostream& operator<<(std::ostream& os, const List& list);
    friend std::ifstream& operator>>(std::ifstream& ifs, List& list);
    friend std::ofstream& operator<<(std::ofstream& ofs, const List& list);

};
```
**entity.cpp**
```
#include "entity.h"
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

Bird::Bird(bool is_ringed_in, string type_in, int age_in, int area_in, int height_in,
    int feeders_in, bool has_nest_int, string gender_in) {
    this->is_ringed = is_ringed_in; // Чи окольцьована птаха (так, ні)
    this->type = type_in;    // Назва виду
    this->age = age_in;       // Вік птаха, місяців
    this->area = area_in;  // Площа у кв. см
    this->height = height_in;   // Висота у см
    this->feeders = feeders_in;  // Кількість годівниць
    this->has_nest = has_nest_int; // Наявність гнізда (так, ні)
    this->gender = gender_in;    // Тип домівки птаха
}

Bird::Bird() {
    this->is_ringed = true; // Чи окольцьована птаха (так, ні)
    this->type = "soroka";    // Назва виду
    this->age = 8;       // Вік птаха, місяців
    this->area = 10;  // Площа у кв. см
    this->height = 12;   // Висота у см
    this->feeders = 2;  // Кількість годівниць
    this->has_nest = true; // Наявність гнізда (так, ні)
    this->gender = "woman";    // Тип домівки птаха
}

Bird::Bird(const Bird& copy) {
    this->is_ringed = copy.is_ringed; // Чи окольцьована птаха (так, ні)
    this->type = copy.type;    // Назва виду
    this->age = copy.age;       // Вік птаха, місяців
    this->area = copy.area;  // Площа у кв. см
    this->height = copy.height;   // Висота у см
    this->feeders = copy.feeders;  // Кількість годівниць
    this->has_nest = copy.has_nest; // Наявність гнізда (так, ні)
    this->gender = copy.gender;    // Тип домівки птаха
}

Bird Bird::createBirdFromInputString(const string& line) {
    Bird bird;

    istringstream iss(line);
    string token;

    getline(iss, token, ',');
    bird.setIsringed(stoi(token));

    getline(iss, token, ',');
    bird.setType(token);

    getline(iss, token, ',');
    bird.setAge(stoi(token));

    getline(iss, token, ',');
    bird.setArea(stoi(token));

    getline(iss, token, ',');
    bird.setHeight(stoi(token));

    getline(iss, token, ',');
    bird.setFeeders(stoi(token));

    getline(iss, token, ',');
    bird.setHasnest(stoi(token));

    getline(iss, token, '\n');
    bird.setGender(token);

    return bird;
}

string Bird::toString() const{
    stringstream ss;
    ss << " Is ringed: " << is_ringed << endl;
    ss << " Type: " << type << endl;
    ss << " Age: " << age << " months" << endl;
    ss << " Nest:" << endl;
    ss << "  Area: " << area << "sq. cm" << endl;
    ss << "  Height: " << height << "cm" << endl;
    ss << "  Number of feeders: " << feeders << endl;
    ss << "  Has nest: " << has_nest << endl;
    ss << "  Gender: " << gender << "\n" << endl;

    const string result = ss.str();

    return result;

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

Bird& Bird::operator=(const Bird& other) {
    if (this == &other) {
        return *this;
    }

    is_ringed = other.is_ringed;
    type = other.type;
    age = other.age;
    area = other.area;
    height = other.height;
    feeders = other.feeders;
    has_nest = other.has_nest;
    gender = other.gender;

    return *this;
}


bool Bird::operator==(const Bird& other) const {
    return (is_ringed == other.is_ringed &&
        this->type == other.type &&
        this->age == other.age &&
        this->area == other.area &&
        this->height == other.height &&
        this->feeders == other.feeders &&
        this->has_nest == other.has_nest &&
        this->gender == other.gender);
}

bool Bird::operator!=(const Bird& other) const {
    return !(*this == other);
}


std::istream& operator>>(std::istream& is, Bird& bird) {
    // Читання властивостей птаха з потоку введення
    cout << "\n";
    cout << " Is ringed (0 - no, 1 - yes): ";
    is >> bird.is_ringed;
    cout << "\n";

    cout << " Type: ";
    is >> bird.type;
    cout << "\n";
    cout << " Age: ";
    is >> bird.age;
    cout << "\n";
    cin.ignore();

    cout << " Nest:\n";
    cout << "  Area: ";
    is >> bird.area;
    cout << "\n";
    cout << "  Height: ";
    is >> bird.height;
    cout << "\n";
    cout << "  Number of feeders: ";
    is >> bird.feeders;
    cout << "\n";
    cout << "  Has nest (0 - no, 1 - yes): ";
    is >> bird.has_nest;;
    cout << "\n";
    cout << "  Gender: ";
    is >> bird.gender;
    cout << "\n";

    return is;
}

std::ostream& operator<<(std::ostream& os, const Bird& bird) {
    os << "  Is ringed: " << bird.getIsringed() << "\n";
    os << "  Type: " << bird.getType() << "\n";
    os << "  Age: " << bird.getAge() << "\n";
    os << "  Nest:\n";
    os << "    Area: " << bird.getArea() << "\n";
    os << "    Height: " << bird.getHeight() << "\n";
    os << "    Number of feeders: " << bird.getFeeders() << "\n";
    os << "    Has nest: " << bird.getHasnest() << "\n";
    os << "  Gender: " << bird.getGender() << "\n";

    return os;
}
```

**entity.h**
```
#ifndef ENTITY_H
#define ENTITY_H
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <sstream>
using std::endl;

class Bird {
private:
        bool is_ringed; // Чи окольцьована птаха (так, ні)
        std::string type;    // Назва виду
        int age;       // Вік птаха, місяців
        
        int area;     // Площа у кв. см
        int height;   // Висота у см
        int feeders;  // Кількість годівниць
        bool has_nest; // Наявність гнізда (так, ні)
               // Тип домівки птаха
        std::string gender;
public:

    Bird();

    Bird(bool is_ringed_in, std::string type_in, int age_in, int area_in, int height_in,
        int feeders_in, bool has_nest_int, std::string gender);

    Bird(const Bird& copy);

    static Bird createBirdFromInputString(const std::string& line);

     bool getIsringed() const;
    void setIsringed(bool isringed_);

    std::string getType() const;
    void setType(std::string type_);

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

    std::string getGender() const;
    void setGender(std::string gender_);

    /// Функція для виведення масиву птахів на екран
    std::string toString() const;

    Bird& operator=(const Bird& other);
    bool operator==(const Bird& other) const;
    bool operator!=(const Bird& other) const;

    friend std::istream& operator>>(std::istream& is, Bird& bird);
    friend std::ostream& operator<<(std::ostream& os, const Bird& bird);

    ~Bird() {};
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
#include "entity.h"
#include <fstream>
#include <sstream>

#include <gtest/gtest.h>

using namespace std;

TEST(ProgramingLab06, AddBird) {
  List list;
  Bird bird1(true, "Sparrow", 12, 100, 20, 2, true, "man");
  Bird bird2(false, "Robin", 8, 80, 18, 1, false, "woman");

  list.addBird(bird1);
  list.addBird(bird2);

  ASSERT_EQ(list.getNum_birds(), 2);
}

TEST(ProgramingLab06, DeleteBird) {
  List list;
  Bird bird1(true, "Sparrow", 12, 100, 20, 2, true, "man");
  Bird bird2(false, "Robin", 8, 80, 18, 1, false, "woman");

  list.addBird(bird1);
  list.addBird(bird2);

  list.deleteBird(0);

  ASSERT_EQ(list.getNum_birds(), 1);
  ASSERT_EQ(list.getBird(0).getType(), bird2.getType());
}

TEST(ProgramingLab06, GenderRatio) {
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

// Helper function to compare the contents of two files
bool compareFiles(const std::string& filename1, const std::string& filename2) {
  std::ifstream file1(filename1);
  std::ifstream file2(filename2);

  if (!file1.is_open() || !file2.is_open()) {
    return false;
  }

  std::string line1, line2;

  while (std::getline(file1, line1) && std::getline(file2, line2)) {
    if (line1 != line2) {
      return false;
    }
  }

  return file1.eof() && file2.eof();
}

  string createTempFile(const std::string& content) {
  ostringstream oss;
  oss << "temp_file_" << testing::UnitTest::GetInstance()->random_seed() << ".txt";
  string filename = oss.str();

  ofstream file(filename);
  file << content;
  file.close();

  return filename;
}

TEST(ProgramingLab06, ReadFromFile) {
  // Create a list and add some birds
  List list;
  Bird bird1(1, "Sparrow", 3, 50, 10, 2, 1, "man");
  Bird bird2(1, "Sparrow", 3, 50, 10, 2, 1, "man");
  list.addBird(bird1);
  list.addBird(bird2);

  // Create a temporary file for writing
  std::string filename = createTempFile("");

  // Write the list to the file
  std::ofstream outputFile(filename);
  outputFile << list;  // Using the overloaded operator<< for List
  outputFile.close();

  // Read the contents of the written file
  std::ifstream inputFile(filename);
  std::stringstream buffer;
  buffer << inputFile.rdbuf();
  std::string fileContents = buffer.str();
  inputFile.close();

  // Define the expected content
  std::string expectedContent = "Bird 1:\n";
  expectedContent += "  Is ringed: 1\n";
  expectedContent += "  Type: Sparrow\n";
  expectedContent += "  Age: 3\n";
  expectedContent += "  Nest:\n";
  expectedContent += "    Area: 50\n";
  expectedContent += "    Height: 10\n";
  expectedContent += "    Number of feeders: 2\n";
  expectedContent += "    Has nest: 1\n";
  expectedContent += "  Gender: man\n\n";
  expectedContent += "Bird 2:\n";
  expectedContent += "  Is ringed: 1\n";
  expectedContent += "  Type: Sparrow\n";
  expectedContent += "  Age: 3\n";
  expectedContent += "  Nest:\n";
  expectedContent += "    Area: 50\n";
  expectedContent += "    Height: 10\n";
  expectedContent += "    Number of feeders: 2\n";
  expectedContent += "    Has nest: 1\n";
  expectedContent += "  Gender: man\n\n";

  // Perform assertions on the file contents
  ASSERT_EQ(fileContents, expectedContent);

  // Delete the temporary file
  remove(filename.c_str());
}

TEST(ProgramingLab06, AssigmentBird) {
  Bird bird1(true, "Sparrow", 12, 100, 20, 2, true, "man");
  Bird bird2 = bird1;

  ASSERT_EQ(bird1, bird2);
}

TEST(ProgramingLab06, BirdEqual) {
  Bird bird1(1, "Sparrow", 3, 50, 10, 2, 1, "man");
  Bird bird2(1, "Sparrow", 3, 50, 10, 2, 1, "man");

  ASSERT_EQ(bird1, bird2);
}

TEST(ProgramingLab06, BirdNotEQual) {
  Bird bird1(1, "Sparrow", 3, 50, 10, 2, 1, "man");
  Bird bird2(0, "Sparrow", 3, 50, 10, 2, 1, "man");

  ASSERT_NE(bird1, bird2);
}

TEST(ProgramingLab06, AverageAgeOfNonRingedBirds) {
    List list;
    Bird bird1(0, "Sparrow", 5, 50, 10, 2, 1, "man");
    Bird bird2(1, "Sparrow", 3, 50, 10, 2, 1, "man");
    Bird bird3(0, "Sparrow", 2, 50, 10, 2, 1, "man");
    list.addBird(bird1);
    list.addBird(bird2);
    list.addBird(bird3);
    float averageAge = list.getAverageAgeOfNonRingedBirds();
    ASSERT_FLOAT_EQ(averageAge, 3.5);
}

// Test case for sorting the birds based on age
TEST(ProgramingLab06, SortBirds) {
    List list;
    Bird bird1(0, "Sparrow", 5, 50, 10, 2, 1, "man");
    Bird bird2(1, "Sparrow", 3, 50, 10, 2, 1, "man");
    Bird bird3(0, "Sparrow", 2, 50, 10, 2, 1, "man");
    list.addBird(bird1);
    list.addBird(bird2);
    list.addBird(bird3);
    list.sortBirds();
    // Check that the birds are sorted in ascending order of age
    ASSERT_EQ(list.getBird(0).getAge(), 2);
    ASSERT_EQ(list.getBird(1).getAge(), 3);
    ASSERT_EQ(list.getBird(2).getAge(), 5);
}

// Test case for merging two lists
TEST(ProgramingLab06, MergeLists) {
    List list1;
    List list2;
    Bird bird1(0, "Sparrow", 5, 50, 10, 2, 1, "man");
    Bird bird2(1, "Sparrow", 3, 50, 10, 2, 1, "man");
    Bird bird3(0, "Sparrow", 2, 50, 10, 2, 1, "man");
    list1.addBird(bird1);
    list2.addBird(bird2);
    list2.addBird(bird3);
    list1.mergeLists(list2);
    // Check that the birds from list2 are added to list1
    ASSERT_EQ(list1.getNum_birds(), 3);
}


```