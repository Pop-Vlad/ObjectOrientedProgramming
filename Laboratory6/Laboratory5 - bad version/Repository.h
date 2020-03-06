#pragma once

#include "Models.h"

using namespace std;



template <typename GenericElement>
class Repository {


private:

	GenericElement** fragments;
	int capacity;
	int size;

	void resize();


public:

	Repository();

	~Repository();

	bool add(GenericElement* new_fragment);

	bool update(char* id, GenericElement* new_fragment);

	bool remove(char* id);

	int getSize();

	GenericElement* getElement(int position);


};