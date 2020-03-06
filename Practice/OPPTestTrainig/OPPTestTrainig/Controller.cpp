#include "Controller.h"



Controller::Controller(Repository* repository) {
	this->repository = repository;
}

bool Controller::add(char* name, char* country) {
	Team* new_team = new Team;
	strcpy(new_team->name, name);
	strcpy(new_team->country, country);
	new_team->score = 0;
	return this->repository->add(new_team);
}

std::vector<Team*> Controller::listAll() {
	return this->repository->getAll();
}

bool Controller::pair(char* team_1, char* team_2, char* winner) {
	return false;
}