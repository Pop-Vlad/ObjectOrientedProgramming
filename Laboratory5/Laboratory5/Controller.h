#pragma once

#include <cstdlib>
#include <exception>

#include "Repository.h"

using namespace std;



class Controller {


private:

	Repository* repository;

	char mode;

	AnomalousFragment** user_list;
	int user_list_capacity;
	int user_list_size;
	int current_fragment_index;

	void resizeUserList();


public:

	Controller(Repository* repository);

	~Controller();

	bool changeMode(char* new_mode);

	char getMode();

	bool add(AnomalousFragment* new_fragment);

	bool update(AnomalousFragment* new_fragment);

	bool remove(char* input_id);

	void listAll(AnomalousFragment** list_of_fragments, int& size);

	AnomalousFragment* nextFragment();

	bool saveFragment(char* input_id);

	void listSize(AnomalousFragment** list_of_fragments, int& size, AnomalousFragment* fragment_to_compare);

	void showUserList(AnomalousFragment** list_of_fragments, int& size);


};


class PermisiisionError : std::exception {

};


class SynataxError : std::exception {

};