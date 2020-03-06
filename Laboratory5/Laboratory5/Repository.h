#pragma once

#include "Models.h"

using namespace std;



class Repository {


private:

	AnomalousFragment** fragments;
	int capacity;
	int size;

	void resize();


public:

	Repository();

	~Repository();

	bool add(AnomalousFragment* new_fragment);

	bool update(char* id, AnomalousFragment* new_fragment);

	bool remove(char* id);

	int getSize();

	AnomalousFragment* getElement(int position);


};