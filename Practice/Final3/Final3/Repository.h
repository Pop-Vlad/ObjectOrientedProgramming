#pragma once

#include "Model.h"
#include <vector>
#include <fstream>
#include <sstream>


class Repository {

private:

	std::string programmers_file;
	std::string sources_file;
	std::vector<Programmer> programmers;
	std::vector<SourceFile> files;

	void load();
	void save();

public:

	Repository(std::string programmers, std::string sources);

	std::vector<Programmer> getAllProgrammers() { return this->programmers; }
	std::vector<SourceFile> getAllFiles() { return this->files; }

	int getRevised(const std::string& name);
	int getTotal(const std::string& name);

	void reviseFile(std::string file, std::string programmer);
	
};

