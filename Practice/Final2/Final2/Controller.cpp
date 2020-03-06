#include "Controller.h"



void Controller::addQuestion(Question new_q) {
	if (new_q.getText() == "")
		throw std::exception{ "No text" };
	this->repository->add(new_q);
}