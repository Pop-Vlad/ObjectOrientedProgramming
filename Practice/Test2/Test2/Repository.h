#pragma once

#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>

#include "Model.h"



class Repository {

private:

	std::vector<Task> elements;

	std::string file;

	void load();


public:

	Repository(std::string file_name);

	std::vector<Task> getElements() const {
		std::vector<int> indexes;
		for (int i = 0; i < this->elements.size(); i++)
			indexes.push_back(i);

		std::sort(indexes.begin(), indexes.end(), [this](int first, int second)
		{return this->elements[first].duration < this->elements[second].duration; });
		std::vector<Task> results;
		for (int index : indexes)
			results.push_back(this->elements[index]);

		return results;
	}

	//Function that filters the items with a given priority
	//Arguments: (int) priorty
	//Return: (std::vector<Task>) results - a vector containing all the tasks with the given priority
	//If priority = 0, returns all tasks
	std::vector<Task> getElementsWithPriority(int priority) const;
};