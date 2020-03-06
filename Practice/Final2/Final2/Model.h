#pragma once

#include <string>

class  Question {

private:

	int id;
	std::string text;
	std::string correct_answer;
	int score;

public:

	Question(int init_id, const std::string& init_text, const std::string& init_answer, int init_score) : id(init_id), text(init_text),
		correct_answer(init_answer), score(init_score) {};

	int getId() { return this->id; }
	std::string getText() { return this->text; }
	std::string getCorrectAnswer() { return this->correct_answer; }
	int getScore() { return this->score; }

	std::string toString() { return std::to_string(this->id) + " " + text + " " + correct_answer + " " + std::to_string(score); }

	std::string toStringParticipant() { return std::to_string(this->id) + " " + text + " " + std::to_string(score); }

};



class Participant {

private:

	std::string name;
	int score;

public:

	Participant(const std::string& init_name, int init_score) : name(init_name), score(init_score) {};

	std::string getName() { return this->name; }
	int getScore() { return this->score; }

	std::string toString() { return this->name + " " + std::to_string(this->score); }

};