#include "Controller.h"



Controller::Controller(Repository input_repoAll, Repository input_repoSpecialStorage) {
	this->repoAll = input_repoAll;
	this->repoSpecialStorage = input_repoSpecialStorage;
}


void Controller::addPainting(const std::string& input_title, const std::string& input_artist, const int& input_year) {
	Painting new_painting = Painting{ input_title, input_artist, input_year };
	this->repoAll.addPainting(new_painting);
	UndoOperation* op = new  UndoAddOperation{ &this->repoAll, &new_painting };
	this->undos.push_back(op);
}


void Controller::movePainting(const std::string& input_title, const std::string& input_artist, const int& input_year) {
	std::vector<Painting> all_paintings = this->repoAll.getAll();
	for (auto iterator = all_paintings.begin(); iterator != all_paintings.end(); iterator++) {
		auto current = *iterator;
		if (input_artist == current.getArtist() && input_title == current.getTitle() && input_year == current.getYear()) {
			current = *iterator;
			this->repoSpecialStorage.addPainting(current);
			return;
		}
	}
	//UndoOperation* op = new  UndoAddOperation{ &this->repoAll, &this->repoSpecialStorage, &new_painting };
	//this->undos.push_back(op);
}


std::vector<Painting> Controller::getAll() const {
	return this->repoAll.getAll();
}


std::vector<Painting> Controller::getAllSpecialStorage() const {
	return this->repoSpecialStorage.getAll();
}


void Controller::undo() {
	UndoOperation* current = this->undos.back();
	current->executeUndo();
	this->undos.pop_back();
}