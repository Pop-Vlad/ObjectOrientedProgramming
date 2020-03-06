#include "Subject.h"

void Subject::notify() {
	for (Observer* obs : this->observers)
		obs->update();
}
