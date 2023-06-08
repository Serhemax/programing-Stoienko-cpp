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
