#include "UndoAddOperation.h"



UndoAddOperation::UndoAddOperation(Repository* input_repo, Painting* input_painting) {
	this->paintingsRepo = input_repo;
	this->painting = painting;
}


void UndoAddOperation::executeUndo() {
	this->paintingsRepo->removePainting(*painting);
}