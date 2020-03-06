#include "Repository.h"



Repository::Repository() {
	this->teams = new std::vector<Team*>;
}


Repository::~Repository() {
	for (auto iterator = this->teams->begin(); iterator != this->teams->end(); iterator++) {
		delete *iterator;
	}
	delete this->teams;
}


bool Repository::add(Team* new_team) {
	for (auto iterator = this->teams->begin(); iterator != this->teams->end(); iterator++) {
		if (((Team*)*iterator)->name == new_team->name) {
			return false;
		}
	}
	this->teams->push_back(new_team);
	return true;
}


bool Repository::update(Team* new_team) {
	for (auto iterator = this->teams->begin(); iterator != this->teams->end(); iterator++) {
		if (((Team*)*iterator)->name == new_team->name) {
			*iterator = new_team;
			return true;
		}
	}
	return false;
}


std::vector<Team*> Repository::getAll() {  
	return *this->teams;
}