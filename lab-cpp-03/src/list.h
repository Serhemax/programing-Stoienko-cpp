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
