## Лабораторна робота №19
####Тема: Перевантаження операторів

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
Поширити попередню лабораторну роботу (потоковий i/o при роботі зі класами) таким чином:

    у базовому класі (прикладної галузі) перевантажити:
        оператор присвоювання;
        оператор порівняння (на вибір 2 протележних оператора: == , != ; < , >= ; > , <= );
        оператори введення / виведення;
    у класі-списку перевантажити:
        оператор індексування ( [ ] );
        оператори введення / виведення з акцентом роботи, у тому числі і з файлами

```
**Основна частина:**

- **Опис роботи основної функції: **

 - Основні функції
entity.cpp / entity.h / list.cpp / list.h / main.cpp

 - Принцип роботи:
1) Перевантажуємо оператор порівняння та присвоєння, порівнюючи та присвоюючи всі елементи птаха. Якщо якийсь з елементів не рівний, тоді птахи не рівні
2) Замінюємо toString на оператор виведення та функцію з main для виведення на оператор виведення
3) перевантажуємо оператор інддексування, щоб він визивав птаха на цбому індексі(замість getBird)
4) перевантажуємо оператори введення / виведення з акцентом роботи, у тому числі і з файлами

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

•	**Перевіримо чи працюють всі функції за допомогою присвоєння та порівняння та функції cout <<:**
```
serhii@mojavirtualka:~/tnp/tnpp/programing-Stoienko-cpp/lab-cpp-03$ make all
rm -rf dist
mkdir dist
g++  -fsanitize=address -std=c++11 -g -Wall -Wextra -Werror -Wformat-security -Wfloat-equal -Wshadow -Wconversion -Wlogical-not-parentheses -Wnull-dereference -Wno-unused-variable -Werror=vla -I./src src/list.cpp src/entity.cpp src/main.cpp -o ./dist/main.bin
g++  -fsanitize=address -std=c++11 -g -Wall -Wextra -Werror -Wformat-security -Wfloat-equal -Wshadow -Wconversion -Wlogical-not-parentheses -Wnull-dereference -Wno-unused-variable -Werror=vla -I./src src/list.cpp src/entity.cpp test/test.cpp  -fprofile-generate -fprofile-arcs -o ./dist/test.bin -lgtest -lgtest_main
./dist/main.bin
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


  Is ringed: 0
  Type: vorobej
  Age: 5
  Nest:
    Area: 20
    Height: 10
    Number of feeders: 3
    Has nest: 0
  Gender: man
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
  Gender:  man
```
**Як бачимо, результати співпадають, тому функції працюють**.

** Також зробимо тест **

```
[==========] Running 8 tests from 2 test suites.
[----------] Global test environment set-up.
[----------] 6 tests from ProgramingLab03
[ RUN      ] ProgramingLab03.AddBird
[       OK ] ProgramingLab03.AddBird (0 ms)
[ RUN      ] ProgramingLab03.DeleteBird
[       OK ] ProgramingLab03.DeleteBird (0 ms)
[ RUN      ] ProgramingLab03.GenderRatio
[       OK ] ProgramingLab03.GenderRatio (0 ms)
[ RUN      ] ProgramingLab03.ReadFromFile
[       OK ] ProgramingLab03.ReadFromFile (7 ms)
[ RUN      ] ProgramingLab03.WriteToFile
[       OK ] ProgramingLab03.WriteToFile (3 ms)
[ RUN      ] ProgramingLab03.AssigmentBird
[       OK ] ProgramingLab03.AssigmentBird (0 ms)
[----------] 6 tests from ProgramingLab03 (11 ms total)

[----------] 2 tests from BirdTest
[ RUN      ] BirdTest.BirdEqual
[       OK ] BirdTest.BirdEqual (0 ms)
[ RUN      ] BirdTest.BirdNotEQual
[       OK ] BirdTest.BirdNotEQual (0 ms)
[----------] 2 tests from BirdTest (0 ms total)

[----------] Global test environment tear-down
[==========] 8 tests from 2 test suites ran. (12 ms total)
[  PASSED  ] 8 tests.

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
 **Висновки**: при виконанні лабораторної роботи були набуті навички праці з перевантаженням операторів.

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
    
    std::cout << birds;
    
    Bird d = b;
    if(d == b){
     std::cout << d;
    }

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

    std::cout << birds;

    return 0;
}
```

** list.cpp **

```
#include "list.h"
#include <limits>
 
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

Bird& List::operator[](int index) const {
    return *birds[index];
}

std::string List::toString() const {
    std::stringstream ss;
     ss << "\n///////////////////\n";
    for (int i = 0; i < num_birds; i++)
    {
        
        ss << "Bird: " << i + 1 << "\n";
        ss << birds[i]->toString();
    }

     ss << "\n///////////////////\n";
    const std::string result = ss.str();

    return result;
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


std::istream& operator>>(std::istream& is, List& list) {
    // Очистити попередні дані списку
    for (int i = 0; i < list.num_birds; i++) {
        delete list.birds[i];
    }
    delete[] list.birds;
    list.birds = nullptr;
    list.num_birds = 0;

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
            Bird* newBird = new Bird(bird);

            // Розширення масиву
            Bird** temp = new Bird * [list.num_birds + 1];
            for (int j = 0; j < list.num_birds; j++) {
                temp[j] = list.birds[j];
            }
            temp[list.num_birds] = newBird;
            delete[] list.birds;
            list.birds = temp;
            list.num_birds++;
        }
    }

    return is;
}

Bird& List::getBird(int idx) const{
    return *birds[idx];
}


std::ostream& operator<<(std::ostream& os, const List& list) {
    for (int i = 0; i < list.num_birds; i++) {
    	os <<  "Bird " << (i + 1) << ":\n";
        os << list.birds[i]->toString() << "\n";
    }
    return os;
}

std::ifstream& operator>>(std::ifstream& ifs, List& list) {
    // Очищення попередніх даних списку
    for (int i = 0; i < list.num_birds; i++) {
        delete list.birds[i];
    }
    delete[] list.birds;
    list.birds = nullptr;
    list.num_birds = 0;

    // Зчитування кількості птахів
    int numBirds;
    ifs >> numBirds;
    ifs.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // Зчитування даних птахів з файлу
    std::string line;
    for (int i = 0; i < numBirds; i++) {
        if (!getline(ifs, line)) {
            break;
        }
        Bird bird = Bird::createBirdFromInputString(line);
        Bird* newBird = new Bird(bird);

        // Розширення масиву
        Bird** temp = new Bird * [list.num_birds + 1];
        for (int j = 0; j < list.num_birds; j++) {
            temp[j] = list.birds[j];
        }
        temp[list.num_birds] = newBird;
        delete[] list.birds;
        list.birds = temp;
        list.num_birds++;
    }

    return ifs;
}

std::ofstream& operator<<(std::ofstream& ofs, const List& list) {
    // Виведення даних птахів у файл
    for (int i = 0; i < list.num_birds; i++) {
        ofs << "Bird " << (i + 1) << ":\n";
        ofs << "  Is ringed: " << list.birds[i]->getIsringed() << "\n";
        ofs << "  Type: " << list.birds[i]->getType() << "\n";
        ofs << "  Age: " << list.birds[i]->getAge() << "\n";
        ofs << "  Nest:\n";
        ofs << "    Area: " << list.birds[i]->getArea() << "\n";
        ofs << "    Height: " << list.birds[i]->getHeight() << "\n";
        ofs << "    Number of feeders: " << list.birds[i]->getFeeders() << "\n";
        ofs << "    Has nest: " << list.birds[i]->getHasnest() << "\n";
        ofs << "  Gender: " << list.birds[i]->getGender() << "\n";
        ofs << "\n";
    }

    return ofs;
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
#include <iostream>
#include <sstream>
#include <fstream>

class List {
private:
	Bird** birds = NULL;
	int num_birds = 0;;
public:
    	int getNum_birds() const;

	void addBird(const Bird &bird);
	void deleteBird(int idx);
	Bird& getBird(int idx) const;

	std::string toString() const;
	float get_gender_ratio() const;

	Bird& operator[](int index) const;

	friend std::istream& operator>>(std::istream& is, List& list);
	friend std::ostream& operator<<(std::ostream& os, const List& list);

	friend std::ifstream& operator>>(std::ifstream& ifs, List& list);
	friend std::ofstream& operator<<(std::ofstream& ofs, const List& list);
	
	List();
       ~List();
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

string Bird::toString() {
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
    std::string toString();

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

TEST(ProgramingLab03, AddBird) {
  List list;
  Bird bird1(true, "Sparrow", 12, 100, 20, 2, true, "man");
  Bird bird2(false, "Robin", 8, 80, 18, 1, false, "woman");

  list.addBird(bird1);
  list.addBird(bird2);

  ASSERT_EQ(list.getNum_birds(), 2);
}

TEST(ProgramingLab03, DeleteBird) {
  List list;
  Bird bird1(true, "Sparrow", 12, 100, 20, 2, true, "man");
  Bird bird2(false, "Robin", 8, 80, 18, 1, false, "woman");

  list.addBird(bird1);
  list.addBird(bird2);

  list.deleteBird(0);

  ASSERT_EQ(list.getNum_birds(), 1);
  ASSERT_EQ(list.getBird(0).getType(), bird2.getType());
}

TEST(ProgramingLab03, GenderRatio) {
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

TEST(ProgramingLab03, ReadFromFile) {
  string content = "3\n1 soroka 8 10 12 2 1 woman\n";
  content += "0 vorobej 5 20 10 3 0 man\n";
  content += "1 Sparrow 3 50 10 2 1 man\n";
  std::string filename = createTempFile(content);
  
  List birds;
  
  std::ifstream inputFile(filename);
  inputFile >> birds;
  inputFile.close();

  ASSERT_EQ(birds.getNum_birds(), 3);
  
  remove(filename.c_str());
}

TEST(ProgramingLab03, WriteToFile) {
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

TEST(ProgramingLab03, AssigmentBird) {
  Bird bird1(true, "Sparrow", 12, 100, 20, 2, true, "man");
  Bird bird2 = bird1;

  ASSERT_EQ(bird1, bird2);
}

TEST(BirdTest, BirdEqual) {
  Bird bird1(1, "Sparrow", 3, 50, 10, 2, 1, "man");
  Bird bird2(1, "Sparrow", 3, 50, 10, 2, 1, "man");

  ASSERT_EQ(bird1, bird2);
}

TEST(BirdTest, BirdNotEQual) {
  Bird bird1(1, "Sparrow", 3, 50, 10, 2, 1, "man");
  Bird bird2(0, "Sparrow", 3, 50, 10, 2, 1, "man");

  ASSERT_NE(bird1, bird2);
}

```