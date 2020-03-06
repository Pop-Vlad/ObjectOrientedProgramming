#pragma once

#include <cstdlib>
#include <exception>

#include "Repository.h"

using namespace std;



class Controller {


private:

	Repository<AnomalousFragment>* repository;

	char mode;

	AnomalousFragment** user_list;
	int user_list_capacity;
	int user_list_size;
	int current_fragment_index;

	void resizeUserList();


public:

	Controller(Repository<AnomalousFragment>* repository);

	~Controller();

	bool changeMode(char* new_mode);

	char getMode();

	bool add(char* input_id, char* input_size, char* input_infection_level, char* input_microfragments, char* input_photograph);

	bool update(char* input_id, char* input_new_size, char* input_new_infection_level, char* input_new_microfragments, char* input_new_photograph);

	bool remove(char* input_id);

	void listAll(char* buffer);

	void nextFragment(char* buffer);

	bool saveFragment(char* input_id);

	void listSize(char* buffer, char* input_size, char* input_minimum_microfragments);

	void showUserList(char* buffer);


};


class PermisiisionError : std::exception {

};


class SynataxError : std::exception {

};