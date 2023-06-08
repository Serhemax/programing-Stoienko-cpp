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
