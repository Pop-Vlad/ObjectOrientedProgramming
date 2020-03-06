#pragma once

#include <fstream>
#include <sstream>

#include "Model.h"



class Repository {

private:

	std::vector<Document> elements;
	std::string file;

	void load();

public:

	Repository(std::string init_file) : file(init_file) { this->load(); }

	std::vector<Document> getElements() const { return this->elements; }

	std::vector<Document> search(std::string text) const;

	//Function that finds the best mathching docment by name, basen on a text
	//Input: (string) text
	//Return: (Document) the document which best matchs the searched text
	//If no document matches the text, returns an empty document
	Document bestMatch(std::string text) const;


};