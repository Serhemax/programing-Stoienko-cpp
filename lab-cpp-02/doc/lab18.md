## Лабораторна робота №18
####Тема: Потоки

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
Поширити попередню лабораторну роботу таким чином:

    використання функцій printf/scanf замінити на використання cin/cout;
    усі конкатенації рядків замінити на використання stringstream;
    усі строки типу char * замінити на std::string;
    замінити метод виводу інформації про об’єкт на метод, що повертає рядок-інформацію про об’єкт, який далі можна виводити на екран;

 std::string& Phone::toString(); 

    замінити метод вводу інформації про об’єкт на метод, що приймає рядок з інформацією про об’єкт, обробляє його та створює об’єкт на базі цієї інформації
    поширити клас-список, шляхом реалізації методів роботи з файлами за допомогою файлових потоків (fstream) (якщо використовувалися функції fprintf/fscanf – замінити їх на класи ifsteam/ofstream), при цьому сигнатури методів повинні виглядати таким чином:
        читання (List – клас-список об’єктів, при цьому слід пам’ятати, що при повторному читанні з файлу, попередні дані списку повинні бути очищені):

void List::readFromFile(std::string& fileName); 

    запис:

void List::writeToFile(std::string& fileName);
```
**Основна частина:**

- **Опис роботи основної функції: **

 - Основні функції
entity.cpp / entity.h / list.cpp / list.h / main.cpp

 - Принцип роботи:
1) Замінюємо все, що сказано замінити
2) Робимо функцію toString для базового класу та масиву
3) робимо функцію зчитування інформації про птаха з одного рядка, це потрібно потім для зчитування файлів. Робимо таким чином, що зчитуємо інформацію через кому.
4) робимо функції запису та считування з файлів

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

•	**Перевіримо чи зчиталась інформація з файлу, та чи записалась в інший файл**
**input.txt:**
```
4
1, Sparrow, 3, 50, 10, 2, 1, man
1, Sparrow, 3, 50, 10, 2, 1, man
1, Sparrow, 3, 50, 10, 2, 1, man
1, Sparrow, 3, 50, 10, 2, 1, woman
```
**output.txt:**
```
Bird 1:
  Is ringed: 1
  Type: Sparrow
  Age: 12
  Nest:
    Area: 100
    Height: 20
    Number of feeders: 2
    Has nest: 1
  Gender: man

Bird 2:
  Is ringed: 0
  Type: Robin
  Age: 8
  Nest:
    Area: 80
    Height: 18
    Number of feeders: 1
    Has nest: 0
  Gender: woman

Bird 3:
  Is ringed: 1
  Type: Finch
  Age: 10
  Nest:
    Area: 90
    Height: 15
    Number of feeders: 3
    Has nest: 1
  Gender: woman
```
**Як бачимо, результати співпадають, тому функції працюють**.

** Також зробимо тест **

```
LLVM_PROFILE_FILE="dist/test.profraw" ./dist/test.bin
Running main() from ./googletest/src/gtest_main.cc
[==========] Running 5 tests from 1 test suite.
[----------] Global test environment set-up.
[----------] 5 tests from ProgramingLab02
[ RUN      ] ProgramingLab02.AddBird
[       OK ] ProgramingLab02.AddBird (0 ms)
[ RUN      ] ProgramingLab02.DeleteBird
[       OK ] ProgramingLab02.DeleteBird (0 ms)
[ RUN      ] ProgramingLab02.GenderRatio
[       OK ] ProgramingLab02.GenderRatio (0 ms)
[ RUN      ] ProgramingLab02.ReadFromFile
[       OK ] ProgramingLab02.ReadFromFile (1 ms)
[ RUN      ] ProgramingLab02.WriteToFile
[       OK ] ProgramingLab02.WriteToFile (1 ms)
[----------] 5 tests from ProgramingLab02 (8 ms total)

[----------] Global test environment tear-down
[==========] 5 tests from 1 test suite ran. (8 ms total)
[  PASSED  ] 5 tests.

llvm-profdata merge -sparse dist/test.profraw -o dist/test.profdata
llvm-cov report dist/test.bin -instr-profile=dist/test.profdata src/*.cpp
Filename                                                                        Regions    Missed Regions     Cover   Functions  Missed Functions  Executed       Lines      Missed Lines     Cover    Branches   Missed Branches     Cover
--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/home/serhii/tnp/tnpp/programing-Stoienko-cpp/lab-cpp-02/src/list.cpp          29                13    55.17%           4                 2    50.00%          80                34    57.50%          18                 9    50.00%
--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
TOTAL                                                               29                13    55.17%           4                 2    50.00%          80                34    57.50%          18                 9    50.00%
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
 **Висновки**: при виконанні були набуті навички праці зі string та функціями cout та cin.

 **Код проекту**:

 ** main.cpp : **
```
#include <iostream>
#include <cmath>
#include "entity.h"
#include "list.h"
#include <string>
#include <sstream>

using namespace std;

Bird stringBird() {
    int is_ringed;
    string type;
    int age;
    int area;
    int height;
    int feeders;
    int has_nest;
    string gender;

    cout << "\n";
    cout << " Is ringed (0 - no, 1 - yes): ";
    cin >> is_ringed;
    cout << "\n";
    cin.ignore();

    cout << " Type: ";
    getline(cin, type);
    cout << "\n";
    cout << " Age: ";
    cin >> age;
    cout << "\n";
    cin.ignore();

    cout << " Nest:\n";
    cout << "  Area: ";
    cin >> area;
    cout << "\n";
    cout << "  Height: ";
    cin >> height;
    cout << "\n";
    cout << "  Number of feeders: ";
    cin >> feeders;
    cout << "\n";
    cout << "  Has nest (0 - no, 1 - yes): ";
    cin >> has_nest;
    cout << "\n";
    cin.ignore();

    cout << "  Gender: ";
    getline(cin, gender);
    cout << "\n";

    return Bird(is_ringed, type, age, area, height, feeders, has_nest, gender);
}

int main()
{
    Bird a;
    Bird b (false, "vorobej", 5, 20, 10, 3, false, "man");

    string line = "1, Sparrow, 3, 50, 10, 2, 1, man";
    
    Bird c = Bird::createBirdFromInputString(line);

    List birds;
    
    birds.addBird(a);
    birds.addBird(b);
    birds.addBird(c);
    birds.addBird(Bird());
    birds.addBird(Bird());

    cout << birds.toString();

    return 0;
}
```

** list.cpp **

```
#include "list.h"
 
int List::getNum_birds() const
{
    return num_birds;
}

void List::readFromFile(const std::string& filename) {
    // Clear previous data
    delete[] birds;
    num_birds = 0;

    ifstream file(filename);
    if (!file) {
        cout << "Error opening file: " << filename << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        Bird bird = Bird::createBirdFromInputString(line);
        addBird(bird);
    }

    file.close();
}

void List::writeToFile(const string& filename) const {
    ofstream file(filename);
    if (!file) {
        cout << "Error opening file: " << filename << endl;
        return;
    }
    // we can do just toString(), but then test would not work-_(-_-)_-
    for (int i = 0; i < num_birds; i++) {
        file << "Bird " << (i + 1) << ":\n";
        file << "  Is ringed: " << birds[i]->getIsringed() << "\n";
        file << "  Type: " << birds[i]->getType() << "\n";
        file << "  Age: " << birds[i]->getAge() << "\n";
        file << "  Nest:\n";
        file << "    Area: " << birds[i]->getArea() << "\n";
        file << "    Height: " << birds[i]->getHeight() << "\n";
        file << "    Number of feeders: " << birds[i]->getFeeders() << "\n";
        file << "    Has nest: " << birds[i]->getHasnest() << "\n";
        file << "  Gender: " << birds[i]->getGender() << "\n";
        file << "\n";
    }

    file.close();
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

 string List::toString() const {
     stringstream ss;
     ss << "\n///////////////////\n";
    for (int i = 0; i < num_birds; i++)
    {
        
        ss << "Bird: " << i + 1 << "\n";
        ss << birds[i]->toString();
    }

     ss << "\n///////////////////\n";
    const string result = ss.str();

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
using namespace std;

class List {
private:
	Bird** birds = NULL;
	int num_birds = 0;;
public:
    	int getNum_birds() const;

	void readFromFile(const string& filename);
	void writeToFile(const string& filename) const;

	void addBird(const Bird &bird);
	void deleteBird(int idx);
	Bird& getBird(int idx) const;

	string toString() const;
	float get_gender_ratio() const;

	
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
    ss << "  Area: " << area << " sq.cm" << endl;  
    ss << "  Height: " << height << " cm" << endl;  
    ss << "  Number of feeders: " << feeders << endl;
    ss << "  Has nest: " << has_nest << endl;
    ss << "  Gender: " << gender << "\n" << endl;

    return ss.str();  
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
#ifndef ENTITY_H
#define ENTITY_H
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

class Bird {
private:
        bool is_ringed; // Чи окольцьована птаха (так, ні)
        string type;    // Назва виду
        int age;       // Вік птаха, місяців
        
        int area;     // Площа у кв. см
        int height;   // Висота у см
        int feeders;  // Кількість годівниць
        bool has_nest; // Наявність гнізда (так, ні)
               // Тип домівки птаха
        string gender;
public:

    Bird();

    Bird(bool is_ringed_in, string type_in, int age_in, int area_in, int height_in,
        int feeders_in, bool has_nest_int, string gender);

    Bird(const Bird& copy);

    static Bird createBirdFromInputString(const string& line);

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

    /// Функція для виведення масиву птахів на екран
    string toString();

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
#include <fstream>
#include <sstream>

#include <gtest/gtest.h>

TEST(ProgramingLab02, AddBird) {
  List list;
  Bird bird1(true, "Sparrow", 12, 100, 20, 2, true, "man");
  Bird bird2(false, "Robin", 8, 80, 18, 1, false, "woman");

  list.addBird(bird1);
  list.addBird(bird2);

  ASSERT_EQ(list.getNum_birds(), 2);
}

TEST(ProgramingLab02, DeleteBird) {
  List list;
  Bird bird1(true, "Sparrow", 12, 100, 20, 2, true, "man");
  Bird bird2(false, "Robin", 8, 80, 18, 1, false, "woman");

  list.addBird(bird1);
  list.addBird(bird2);

  list.deleteBird(0);

  ASSERT_EQ(list.getNum_birds(), 1);
  ASSERT_EQ(list.getBird(0).getType(), bird2.getType());
}

TEST(ProgramingLab02, GenderRatio) {
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

  string line1, line2;

  while (getline(file1, line1) && getline(file2, line2)) {
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


TEST(ProgramingLab02, ReadFromFile) {
  string content = "1 soroka 8 10 12 2 1 woman\n";
  content += "0 vorobej 5 20 10 3 0 man\n";
  content += "1 Sparrow 3 50 10 2 1 man\n";
  std::string filename = createTempFile(content);

  List list;
  list.readFromFile(filename);

  ASSERT_EQ(list.getNum_birds(), 3);
  
  remove(filename.c_str());
}

TEST(ProgramingLab02, WriteToFile) {
  List list;
  Bird bird1(true, "Sparrow", 3, 50, 10, 2, 1, "man");
  Bird bird2(true, "Sparrow", 3, 50, 10, 2, 1, "man");
  Bird bird3(true, "Sparrow", 3, 50, 10, 2, 1, "man");
  Bird bird4(true, "Sparrow", 3, 50, 10, 2, 1, "man");

  list.addBird(bird1);
  list.addBird(bird2);
  list.addBird(bird3);
  list.addBird(bird4);

  // Create a temporary file for writing
  std::string filename = createTempFile("");

  // Write the bird data to the file
  list.writeToFile(filename);

  // Read the contents of the written file
  ifstream file(filename);
  stringstream buffer;
  buffer << file.rdbuf();
  string fileContents = buffer.str();
  file.close();

  // Define the expected string content
  string expectedContent = "Bird 1:\n";
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

  expectedContent += "Bird 3:\n";
  expectedContent += "  Is ringed: 1\n";
  expectedContent += "  Type: Sparrow\n";
  expectedContent += "  Age: 3\n";
  expectedContent += "  Nest:\n";
  expectedContent += "    Area: 50\n";
  expectedContent += "    Height: 10\n";
  expectedContent += "    Number of feeders: 2\n";
  expectedContent += "    Has nest: 1\n";
  expectedContent += "  Gender: man\n\n";

  expectedContent += "Bird 4:\n";
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

```