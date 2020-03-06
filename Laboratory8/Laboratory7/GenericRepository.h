#pragma once

#include <vector>

#include "Models.h"



class GenericRepository {


protected:

	std::vector<AnomalousFragment> fragments;


public:

	GenericRepository() {
		this->fragments = std::vector<AnomalousFragment>{};
	};

	virtual bool add(AnomalousFragment* new_fragment) = 0;

	virtual bool update(char* id, AnomalousFragment* new_fragment) = 0;

	virtual bool remove(char* id) = 0;

	virtual int getSize() = 0;

	virtual AnomalousFragment* getElement(int position) = 0;


};