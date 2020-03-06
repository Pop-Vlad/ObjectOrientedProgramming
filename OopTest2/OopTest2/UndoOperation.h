#pragma once

#include "Repository.h"



class UndoOperation {


public:

	UndoOperation() {};
	
	virtual void executeUndo() = 0;


};

