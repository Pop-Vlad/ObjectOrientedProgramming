#pragma once

#include <vector>
#include <fstream>
#include <sstream>

#include "Model.h"


class Repository {

private:

	std::string p_file;
	std::string q_file;

	std::vector<Participant> participants;
	std::vector<Question> questions;

	void load();
	void save();

public:

	Repository(std::string participants_file, std::string questions_file) : p_file(participants_file), q_file(questions_file) { this->load(); }
	~Repository() { this->save(); }

	std::vector<Participant> getAllParticipants() { return this->participants; }
	std::vector<Question> getAllQuestions() { return this->questions; }

	void add(Question new_q);

};

