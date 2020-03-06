#pragma once

#include "Observer.h"
#include <vector>


class Subject {

private:

	std::vector<Observer*> observers;
public:

	Subject() {};

	void registerObserver(Observer* obs);

	void notify();

};

