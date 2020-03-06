#include "Subject.h"



void Subject::notify() {
	for (Observer* current : this->observers)
		current->update();
}
