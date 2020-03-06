#include "Controller.h"



Engine* Controller::createEngine(const std::string& engineType, const std::string& fuelType, const int& autonomy) {
	if (engineType == "Electric") {
		ElectricEngine* new_engine = new ElectricEngine{ fuelType, autonomy };
		return new_engine;
	}
	TurboEngine* new_engine = new TurboEngine{ fuelType };
	return new_engine;
}


void Controller::addCar(const std::string& engineType, const std::string& fuelType, const int& autonomy) {

}


std::vector<Pod> Controller::getCarsWithMaxPrice(const double& max_price) {
	return std::vector<Pod> {};
}

void Controller::writeToFile(const std::string& filename, const int& max_cost) {

}