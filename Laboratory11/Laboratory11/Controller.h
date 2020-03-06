#pragma once

#include "MemoryRepository.h"
#include "FileRepository.h"
//#include "SqlRepository.h"
#include "CSVRepository.h"
#include "HTMLRepository.h"



class Controller {


private:

	Repository* repository;
	std::string file_type;
	char mode;

	Repository* user_list;
	int current_fragment_index;
	std::string user_list_type;

public:

	//Create a controller
	//Arguments - (repository) the repository with which the controller works
	Controller(Repository* repository, Repository* user_list);

	//Set a new mode for the user
	//Arguments - (char) the new mode
	void setMode(const char& new_mode);

	//Get the mode of the user
	//Arguments - None
	char getMode();

	void add(const AnomalousFragment& new_fragment);

	void update(const AnomalousFragment& new_fragment);

	void remove(const std::string& id);

	std::vector<AnomalousFragment> listAll() const;

	AnomalousFragment getFragment(const int& index) const { return this->repository->getElement(index); }

	AnomalousFragment nextFragment();

	void saveFragment(const std::string& id);

	std::vector<AnomalousFragment> listFiltered(const std::string& size_to_compare, const int& microfragments_to_compare);

	std::vector<AnomalousFragment> showUserList();

	void changeFile(const std::string& new_file_location);

	void changeMyList(const std::string& new_mylist_location);

};


typedef GenericException PermissionDenied;

typedef GenericException ModeError;

typedef GenericException EmptyRepository;