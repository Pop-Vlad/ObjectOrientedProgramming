#pragma once

#include "Models.h"
#include<vector>
#include <fstream>
#include <sstream>

class Repository {
	
private:

	std::string writersFile;
	std::string ideasFile;

	std::vector<Writer> writers;
	std::vector<Idea> ideas;

	void load();

public:

	Repository(std::string writers_file, std::string ideas_file) : writersFile(writers_file), ideasFile(ideas_file) { this->load(); }

	std::vector<Writer> getWriters() { return this->writers; }
	std::vector<Idea> getIdeas() { return this->ideas; }

	// Adds a new idea to the repository
	// Arguments: new_idea(Idea)
	// Output: none
	// Throws an error if an idea with the same description and act already exists
	//		and new_idea will not be added
	void addIdea(Idea new_idea);

	// Updates the status of an idea
	// Arguments: idea_to_update(Idea)
	//			  new_status(string)
	// Output: none
	void updateStatus(Idea idea_to_update, std::string new_status);
	
};

