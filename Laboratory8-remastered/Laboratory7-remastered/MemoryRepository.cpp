#include "MemoryRepository.h"



MemoryRepository::MemoryRepository() {
	this->fragments = std::vector<AnomalousFragment>{};
}


void MemoryRepository::add(const AnomalousFragment& new_fragment) {
	std::string check_id = new_fragment.getId();
	std::vector<AnomalousFragment>::iterator iterator = std::find_if(this->fragments.begin(), this->fragments.end(),
		[check_id](AnomalousFragment fragment) { return fragment.getId() == check_id; });
	if (iterator != this->fragments.end()) {
		throw ElementAlreadyExists{ "An object whit this id already exists" };
	}
	this->fragments.push_back(new_fragment);
}


void MemoryRepository::update(const AnomalousFragment& new_fragment) {
	std::string check_id = new_fragment.getId();
	std::vector<AnomalousFragment>::iterator iterator = std::find_if(this->fragments.begin(), this->fragments.end(),
		[check_id](AnomalousFragment fragment) { return fragment.getId() == check_id; });
	if (iterator != this->fragments.end()) {
		*iterator = new_fragment;
	}
	else {
		throw ElementNotFound{ "No object with this id was found" };
	}
}


void MemoryRepository::remove(const std::string& check_id) {
	std::vector<AnomalousFragment>::iterator iterator = std::find_if(this->fragments.begin(), this->fragments.end(),
		[check_id](AnomalousFragment fragment) { return fragment.getId() == check_id; });
	if (iterator != this->fragments.end()) {
		*iterator = this->fragments.back();
		this->fragments.pop_back();
	}
	else {
		throw ElementNotFound{ "No object with this id was found" };
	}
}


int MemoryRepository::getSize() const {
	return this->fragments.size();
}


AnomalousFragment MemoryRepository::getElement(const int& position) const {
	return this->fragments[position];
}