#pragma once

#include <string>


class Programmer {

private:

	std::string name;
	int revisedFiles;
	int totalFiles;
public:

	Programmer(const std::string& init_name, int init_revised, int init_total) : name(init_name), revisedFiles(init_revised), totalFiles(init_total) {}

	std::string getName() { return this->name; }
	int getRevisedFiles() { return this->revisedFiles; }
	int getTotalFiles() { return this->totalFiles; }

	void setRevisedFiles(int count) { this->revisedFiles = count; }

};


class SourceFile {

private:

	std::string name;
	std::string status;
	std::string creator;
	std::string reviewer;

public:

	SourceFile(std::string name, std::string status, std::string creator, std::string reviewer) : name(name), status(status), creator(creator),
		reviewer(reviewer) {}

	std::string getName() { return this->name; }
	std::string getStatus() { return this->status; }
	std::string getCreator() { return this->creator; }
	std::string getReviewer() { return this->reviewer; }

	void setReviewer(std::string reviewer) { this->reviewer = reviewer; this->status = "revised"; }

	std::string toString() { return this->name + " " + this->status + " " + this->creator + " " + this->reviewer; }

};