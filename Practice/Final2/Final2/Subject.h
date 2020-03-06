#pragma once

#include "Observer.h"
#include <vector>

class Subject {

private:

	std::vector<Observer*> observers;


public:

	Subject() {};

	void registerObserver(Observer* new_observer) { this->observers.push_back(new_observer); }

	void notify() {
		for (auto obs : observers)
			obs->update();
	}
	
};

