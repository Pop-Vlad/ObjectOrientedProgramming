#pragma once

#include "UndoOperation.h"



class UndoAddOperation : public UndoOperation {


private:

	Repository* paintingsRepo;

	Painting* painting;


public:

	UndoAddOperation(Repository* input_repo, Painting* input_painting);

	void executeUndo() override;
	

};

