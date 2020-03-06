#include <fstream>

#include "FileRepository.h"



FileRepository::FileRepository() {
	strcpy(this->file_path, "\0");
	this->fragments = new std::vector<AnomalousFragment*>;
}


FileRepository::~FileRepository() {
	this->save();
	delete this->fragments;
}


void FileRepository::setPath(char new_file_path[]) {
	if (strcmp(this->file_path, "\0") != 0) {
		this->save();
	}
	strcpy(this->file_path, new_file_path);
	this->load();
}


void FileRepository::load() {
	int number_of_fragments;
	this->fragments->clear();
	std::ifstream data_file;
	data_file.open(this->file_path);
	data_file >> number_of_fragments;

	AnomalousFragment* current_fragment = new AnomalousFragment();
	for (int i = 0; i < number_of_fragments; i++) {
		data_file >> current_fragment;
		this->fragments->push_back(current_fragment);
	}

	data_file.close();
}


void FileRepository::save() {
	std::ofstream data_file;
	data_file.open(this->file_path);
	data_file << this->fragments->size() << "\n";

	for (int i = 0; i < this->fragments->size(); i++) {
		data_file << this->fragments->at(i) << "\n";
	}

	data_file.close();
}