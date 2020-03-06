#pragma once

#include "UndoOperation.h"



class UndoMoveOperation : public UndoOperation {


private:

	Repository* paintingsRepo;

	Repository* specialPainingsRepo;

	Painting* painting;


public:

	UndoMoveOperation(Repository* input_repo, Repository* input_repo_special, Painting* input_painting);

	void executeUndo() override;


};
