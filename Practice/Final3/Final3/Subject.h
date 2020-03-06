#pragma once

#include "Observer.h"
#include <vector>

class Subject {

private:

	std::vector<Observer*> observers;

public:

	Subject() {};

	void registerObserver(Observer* new_obs){ this->observers.push_back(new_obs); }

	void notify();
};

