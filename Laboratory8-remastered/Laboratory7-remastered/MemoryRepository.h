#pragma once

#include "GenericRepository.h"

#include <algorithm>



class MemoryRepository : public Repository {


public:

	//Create a repository
	MemoryRepository();

	//Add a new fragment to the repository
	//Arguments - (AnomalousFragment) new_fragment
	//Throws - ElementAlreadyExists, if a stored fragment already has the id of the input
	void add(const AnomalousFragment& new_fragment) override;

	//Change the data of a fragment
	//Arguments - (AnomalousFragment) new_data
	//Throws - ElementNotFound, if the id of the input was not found
	void update(const AnomalousFragment& new_fragment) override;

	//Remove a fragment by its id
	//Arguments - (string) id - the id of the fragment to remove
	//Throws - ElementNotFound, if the given id was not found
	void remove(const std::string& id) override;

	//Get the number of elements in the reposiotry
	int getSize() const override;

	//Get an element from a given position
	//Arguments - (int) position
	AnomalousFragment getElement(const int& position) const override;

	//Get all of the elements stored
	//Arguments - None
	std::vector<AnomalousFragment> getAllElements() const override { return this->fragments; }


};