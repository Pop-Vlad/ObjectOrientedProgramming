#pragma once

#include "Models.h"
#include "GenericException.h"

#include <vector>



class Repository {


protected:

	std::vector<AnomalousFragment> fragments;


public:

	Repository() {
		this->fragments = std::vector<AnomalousFragment>{};
	};

	virtual void add(const AnomalousFragment& new_fragment) = 0;

	virtual void update(const AnomalousFragment& new_fragment) = 0;

	virtual void remove(const std::string& id) = 0;

	virtual int getSize() const = 0;

	virtual AnomalousFragment getElement(const int& position) const = 0;

	virtual std::vector<AnomalousFragment> getAllElements() const = 0;


};


typedef GenericException ElementAlreadyExists;

typedef GenericException ElementNotFound;