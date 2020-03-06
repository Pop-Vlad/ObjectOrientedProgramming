#pragma once

#include "Repository.h"



class Controller {

private:

	Repository* repository;


public:

	Controller( Repository* repo) : repository(repo) {};
	
	std::vector<Participant> getParticipants() { return this->repository->getAllParticipants(); }
	std::vector<Question> getQuestions() { return this->repository->getAllQuestions(); }

	// Adds a new question to the repository
	// Input: new_q (Question) - the questin to be added
	// Output: none
	// Throws an exception if the question has no text or if the id is already taken
	void addQuestion(Question new_q);

};

