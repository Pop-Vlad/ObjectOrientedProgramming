#pragma once

#include "MemoryRepository.h"
#include "FileRepository.h"



class Controller {


private:

	Repository* repository;

	char mode;

	MemoryRepository user_list;

	int current_fragment_index;


public:

	//Create a controller
	//Arguments - (repository) the repository with which the controller works
	Controller(Repository* repository);

	//Set a new mode for the user
	//Arguments - (char) the new mode
	void setMode(const char& new_mode);

	//Get the mode of the user
	//Arguments - None
	char getMode();

	//Add a new fragment
	//Arguments - (AnomalousFragment) new_fragment
	void add(const AnomalousFragment& new_fragment);

	//Update the data of a fragment
	//Arguments - (AnomalousFragment) new_data
	void update(const AnomalousFragment& new_data);

	//Remove a fragment
	//Arguments - (string) id = the id of the fragment to be removed
	void remove(const std::string& id);

	//Get all the fragments in the repository
	//Arguments - None
	std::vector<AnomalousFragment> listAll() const;

	//Iterate through all the data
	//Arguments - None
	//Each call returns a new object from the repository
	AnomalousFragment nextFragment();

	//Save a fragment in the user list based on its id
	//Arguments - (string) id
	void saveFragment(const std::string& id);

	//Get all the elements that have a given size a given number of microfragments
	//Arguments - (string) size_to_compare
	//			- (string) nr_of_microfragments_to_compare
	std::vector<AnomalousFragment> listFiltered(const std::string& size_to_compare, const int& microfragments_to_compare);

	//Show the fragments stored in the user list
	//Arguments - None
	std::vector<AnomalousFragment> showUserList();

	//Change the file in which all the fragments are stored
	//Arguments - (string) new_file_location
	void changeFile(const std::string& new_file_location);


};


typedef GenericException PermissionDenied;

typedef GenericException ModeError;

typedef GenericException EmptyRepository;