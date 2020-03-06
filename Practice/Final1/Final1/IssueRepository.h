#pragma once

#include "Model.h"
#include "Subject.h"

#include <vector>
#include <fstream>
#include <sstream>



class IssueRepository : public Subject {

private:

	std::string users_file;
	std::string issues_file;

	std::vector<User> users;
	std::vector<Issue> issues;

	void loadFiles();
	void saveFile();

public:

	IssueRepository(std::string init_u, std::string init_i);
	~IssueRepository();

	std::vector<User> getAllUsers() { return this->users; }
	std::vector<Issue> getAllIssues() { return this->issues; }

	// Add a new issue
	// Input: description(string); reporter(string)
	// Output: none
	// Raises an error if: an item with description was already found/is empty
	//		or reposter does not exist/is not a tester.
	void add(std::string description, std::string reporter);

	void remove(std::string description);

	//Update the status and the solver of an issue
	// Input: description(string); reporter(string)
	// Output: none
	// Raises an error if: an item with description was not found, the issue is already closed
	//		or reposter does not exist/is not a programmer.
	void resolve(std::string description, std::string solver);

};

