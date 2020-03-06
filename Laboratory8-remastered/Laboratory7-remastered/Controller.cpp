#include "Controller.h"



Controller::Controller(Repository* repository) {
	this->repository = repository;
	this->mode = NULL;
	this->user_list = MemoryRepository{};
	this->current_fragment_index = -1;
}


void Controller::setMode(const char& new_mode) {
	if (new_mode == 'a' || new_mode == 'A') {
		this->mode = 'A';
		return;
	}
	if (new_mode == 'b' || new_mode == 'B') {
		this->mode = 'B';
		return;
	}
	throw ModeError{ "Cannot change mode: mode must be A or B" };
}


char Controller::getMode() {
	return this->mode;
}


void Controller::add(const AnomalousFragment& new_fragment) {
	if (this->mode != 'A') {
		throw PermissionDenied{ "Permssion denied" };
	}
	this->repository->add(new_fragment);
}


void Controller::update(const AnomalousFragment& new_fragment) {
	if (this->mode != 'A') {
		throw PermissionDenied{ "Permssion denied" };
	}
	this->repository->update(new_fragment);
}


void Controller::remove(const std::string& id) {
	if (this->mode != 'A') {
		throw PermissionDenied{ "Permssion denied" };
	}
	this->repository->remove(id);
}


std::vector<AnomalousFragment> Controller:: listAll() const {
	if (this->mode != 'A') {
		throw PermissionDenied{ "Permssion denied" };
	}
	return this->repository->getAllElements();
}


AnomalousFragment Controller::nextFragment() {
	if (this->mode != 'B') {
		throw PermissionDenied{ "Permssion denied" };
	}
	if (this->repository->getSize() == 0) {
		throw EmptyRepository{ "No fragments found" };
	}
	if (this->current_fragment_index >= this->repository->getSize() - 1) {
		this->current_fragment_index = -1;
	}
	this->current_fragment_index += 1;
	return this->repository->getElement(this->current_fragment_index);
}


void Controller::saveFragment(const std::string& check_id) {
	if (this->mode != 'B') {
		throw PermissionDenied{ "Permssion denied" };
	}
	std::vector<AnomalousFragment> all_fragments = this->repository->getAllElements();
	std::vector<AnomalousFragment>::iterator iterator = std::find_if(all_fragments.begin(), all_fragments.end(),
		[check_id](AnomalousFragment fragment) { return fragment.getId() == check_id; });
	if (iterator != all_fragments.end()) {
		this->user_list.add(*iterator);
	}
	else {
		throw ElementNotFound{ "Element with given id does not exist." };
	}
}


std::vector<AnomalousFragment> Controller::listFiltered(const std::string& size_to_compare, const int& microfragments_to_compare) {
	if (this->mode != 'B') {
		throw PermissionDenied{ "Permssion denied" };
	}
	std::vector<AnomalousFragment> all_fragments = this->repository->getAllElements();
	std::vector<AnomalousFragment> filtered_fragments(this->repository->getSize());
	std::vector<AnomalousFragment>::iterator iterator = std::copy_if(all_fragments.begin(), all_fragments.end(), filtered_fragments.begin(),
		[size_to_compare, microfragments_to_compare](AnomalousFragment current_fragment)
	{return current_fragment.getSize() == size_to_compare && current_fragment.getMicrofragments() == microfragments_to_compare; });
	filtered_fragments.erase(iterator, filtered_fragments.end());
	return filtered_fragments;
}


std::vector<AnomalousFragment> Controller::showUserList() {
	if (this->mode != 'B') {
		throw PermissionDenied{ "Permssion denied" };
	}
	return this->user_list.getAllElements();
}


void Controller::changeFile(const std::string& new_file_location) {
	FileRepository* file_repository = dynamic_cast<FileRepository*>(this->repository);
	if (file_repository != nullptr) {
		file_repository->setPath(new_file_location);
	}
}