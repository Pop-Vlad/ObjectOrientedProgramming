#include "FileRepository.h"



FileRepository::FileRepository(const  std::string& file_location) {
	this->fragments = std::vector<AnomalousFragment>{};
	this->file_location = file_location;
	if (this->file_location != "\0") {
		this->load();
	}
}


void FileRepository::load() {
	int number_of_fragments;
	this->fragments.clear();
	std::ifstream data_file;
	data_file.open(this->file_location);
	if (!data_file.is_open()) {
		std::ofstream data_file_out;
		data_file_out.open(this->file_location);
		data_file_out << "0\n";
		data_file_out.close();
		data_file.open(this->file_location);
		//throw FileOpenError{ "File not found" };
	}
	data_file >> number_of_fragments;

	AnomalousFragment current_fragment;
	for (int i = 0; i < number_of_fragments; i++) {
		data_file >> current_fragment;
		this->fragments.push_back(current_fragment);
	}

	data_file.close();
}


void FileRepository::save() const {
	std::ofstream data_file;
	data_file.open(this->file_location);
	data_file << this->fragments.size() << "\n";

	for (int i = 0; i < this->fragments.size(); i++) {
		data_file << this->fragments[i] << "\n";
	}

	data_file.close();
}


void FileRepository::add(const AnomalousFragment& new_fragment) {
	std::string check_id = new_fragment.getId();
	std::vector<AnomalousFragment>::iterator iterator = std::find_if(this->fragments.begin(), this->fragments.end(),
		[check_id](AnomalousFragment fragment) { return fragment.getId() == check_id; });
	if (iterator != this->fragments.end()) {
		throw ElementAlreadyExists{ "An object whit this id already exists" };
	}
	this->fragments.push_back(new_fragment);
	this->save();
}


void FileRepository::update(const AnomalousFragment& new_fragment) {
	std::string check_id = new_fragment.getId();
	std::vector<AnomalousFragment>::iterator iterator = std::find_if(this->fragments.begin(), this->fragments.end(),
		[check_id](AnomalousFragment fragment) { return fragment.getId() == check_id; });
	if (iterator != this->fragments.end()) {
		*iterator = new_fragment;
		this->save();
	}
	else {
		throw ElementNotFound{ "No object with this id was found" };
	}
}


void FileRepository::remove(const std::string& check_id) {
	std::vector<AnomalousFragment>::iterator iterator = std::find_if(this->fragments.begin(), this->fragments.end(),
		[check_id](AnomalousFragment fragment) { return fragment.getId() == check_id; });
	if (iterator != this->fragments.end()) {
		*iterator = this->fragments.back();
		this->fragments.pop_back();
		this->save();
	}
	else {
		throw ElementNotFound{ "No object with this id was found" };
	}
}


int FileRepository::getSize() const {
	return this->fragments.size();
}


AnomalousFragment FileRepository::getElement(const int& position) const {
	return this->fragments[position];
}