#include "UndoMoveOperation.h"



UndoMoveOperation::UndoMoveOperation(Repository* input_repo, Repository* input_repo_special, Painting* input_painting) {
	this->paintingsRepo = input_repo;
	this->specialPainingsRepo = input_repo_special;
	this->painting = painting;
}


void UndoMoveOperation::executeUndo() {
	this->specialPainingsRepo->removePainting(*painting);
}