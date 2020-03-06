#include "Models.h"



AnomalousFragment::AnomalousFragment() {
	this->id = new char[1];
	strcpy(this->id, "");
	this->size = new char[1];
	strcpy(this->size, "");
	this->infection_level = 0;
	this->microfragments = 0;
	this->photograph = new char[1];
	strcpy(this->photograph, "0");
}


AnomalousFragment::AnomalousFragment(char* id, char* size, double infection_leve, int microfragments, char* photograph) {
	this->id = new char[strlen(id) + 1];
	strcpy(this->id, id);
	this->size = new char[strlen(size) + 1];
	strcpy(this->size, size);
	this->infection_level = infection_leve;
	this->microfragments = microfragments;
	this->photograph = new char[strlen(photograph) + 1];
	strcpy(this->photograph, photograph);
}


AnomalousFragment::~AnomalousFragment() {
	delete[] this->id;
	delete[] this->photograph;
}


void AnomalousFragment::toString(char* buffer) {
	strcpy(buffer, "");
	strcat(buffer, this->id);
	strcat(buffer, " ");
	strcat(buffer, this->size);
	strcat(buffer, " ");
	strcat(buffer, std::to_string(this->infection_level).c_str());
	strcat(buffer, " ");
	strcat(buffer, std::to_string(this->microfragments).c_str());
	strcat(buffer, " ");
	strcat(buffer, this->photograph);
	strcat(buffer, "\n");
}


std::istream& operator>>(std::istream& stream, AnomalousFragment* &fragment) {
	AnomalousFragment* new_fragment = new AnomalousFragment();
	stream >> new_fragment->id >> new_fragment->size >> new_fragment->infection_level >>
		new_fragment->microfragments >> new_fragment->photograph;
	fragment = new_fragment;
	return stream;
}


std::ostream& operator<<(std::ostream& stream, AnomalousFragment* fragment) {
	stream << fragment->id << " " << fragment->size << " " << fragment->infection_level << " " <<
		fragment->microfragments << " " << fragment->photograph;
	return stream;
}