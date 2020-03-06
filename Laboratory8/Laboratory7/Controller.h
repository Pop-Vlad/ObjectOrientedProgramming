#pragma once

#include <cstdlib>
#include <exception>

#include "MemoryRepository.h"



class Controller {


private:

	Repository* repository;

	char mode;

	Repository* user_list;
	int current_fragment_index;


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

	void changeFile(char new_file_path[]);


};


class PermisiisionError : std::exception {

};


class SynataxError : std::exception {

};