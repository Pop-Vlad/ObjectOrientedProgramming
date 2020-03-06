#include "Models.h"



AnomalousFragment::AnomalousFragment(char* id, triple size, double infection_leve, int microfragments, char* photograph) {
	this->id = new char[strlen(id) + 1];
	strcpy(this->id, id);
	this->size = size;
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
	strcat(buffer, to_string(this->size.length).c_str());
	strcat(buffer, "X");
	strcat(buffer, to_string(this->size.width).c_str());
	strcat(buffer, "X");
	strcat(buffer, to_string(this->size.height).c_str());
	strcat(buffer, " ");
	strcat(buffer, to_string(this->infection_level).c_str());
	strcat(buffer, " ");
	strcat(buffer, to_string(this->microfragments).c_str());
	strcat(buffer, " ");
	strcat(buffer, this->photograph);
	strcat(buffer, "\n");
}