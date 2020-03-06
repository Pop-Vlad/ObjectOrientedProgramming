#pragma once

#include <vector>
#include <algorithm>

#include "Models.h"



class Repository {


protected:

	std::vector<AnomalousFragment*>* fragments;


public:

	Repository();

	virtual ~Repository();

	bool add(AnomalousFragment* new_fragment);

	bool update(char* id, AnomalousFragment* new_fragment);

	bool remove(char* id);

	int getSize();

	AnomalousFragment* getElement(int position);


};
