#pragma once

#include "Repository.h"
#include "UndoAddOperation.h"
#include "UndoMoveOperation.h"



class Controller {


private:

	Repository repoAll;

	Repository repoSpecialStorage;

	std::vector<UndoOperation*> undos;


public:

	Controller(Repository input_repoAll, Repository input_repoSpecialStorage);

	void addPainting(const std::string& input_title, const std::string& input_artist, const int& input_year);

	void movePainting(const std::string& input_title, const std::string& input_artist, const int& input_year);

	std::vector<Painting> getAll() const;

	std::vector<Painting> getAllSpecialStorage() const;

	void undo();

	
};

