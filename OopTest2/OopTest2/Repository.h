#pragma once

#include "Painting.h"

#include <vector>


class Repository {


private:

	std::vector<Painting> paintings;


public:

	Repository();

	void addPainting(const Painting& p);

	void removePainting(const Painting& p);

	std::vector<Painting> getAll()const { return this->paintings; }
	
};

