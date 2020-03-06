#pragma once

#include "DynamicArray.h"

using namespace std;



class Repository {


private:

	DynamicArray<AnomalousFragment>* fragments;


public:

	Repository();

	~Repository();

	bool add(AnomalousFragment* new_fragment);

	bool update(char* id, AnomalousFragment* new_fragment);

	bool remove(char* id);

	int getSize();

	AnomalousFragment* getElement(int position);


};