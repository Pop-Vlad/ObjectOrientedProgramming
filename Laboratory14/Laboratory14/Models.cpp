#include "Models.h"



std::string AnomalousFragment::toString() const {
	return this->id + " " + this->size + " " + std::to_string(this->infection) + " " + std::to_string(this->microfragments) + " " + this->photograph;
}


std::istream& operator>>(std::istream& stream, AnomalousFragment& fragment) {
	std::string new_id;
	std::string new_size;
	double new_infection;
	int new_microfragments;
	std::string new_photograph;
	
	stream >> new_id;
	stream >> new_size;
	stream >> new_infection;
	stream >> new_microfragments;
	stream >> new_photograph;

	fragment = AnomalousFragment{ new_id, new_size, new_infection, new_microfragments, new_photograph };
	return stream;
}


std::ostream& operator<<(std::ostream& stream, const AnomalousFragment& fragment) {
	stream << fragment.toString();
	return stream;
}