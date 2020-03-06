#pragma once

#include <string>

class Writer {

private: 

	std::string name;
	std::string expertise;

public:

	Writer(std::string init_name, std::string init_expertise) : name{ init_name }, expertise{ init_expertise }{};

	std::string getName() { return this->name; }
	std::string getExpertise() { return this->expertise; }


};

class Idea {

private:

	std::string description;
	std::string status;
	std::string creator;
	int act;

public:

	Idea(std::string init_descr, std::string init_status, std::string init_creator, int init_act) : description{ init_descr },
		status(init_status), creator(init_creator), act(init_act) {};

	std::string getDescription() { return this->description; }
	std::string getStatus() { return this->status; }
	std::string getCreator() { return this->creator; }
	int getAct() { return this->act; }

	std::string toString() { return this->description + " " + this->status + " " + this->creator + " " + std::to_string(this->act); }

	void setCreator(std::string new_creator) { this->creator = new_creator; }
	void setStatus(std::string new_status) { this->status = new_status; }

};