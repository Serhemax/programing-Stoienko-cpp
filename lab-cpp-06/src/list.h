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
