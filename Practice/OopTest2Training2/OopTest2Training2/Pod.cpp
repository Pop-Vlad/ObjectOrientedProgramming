#include "Pod.h"



double Pod::computePrice() {
	double price = 8000;
	if (this->bodyStyle == "Railcar") {
		price += 1000;
	}
	price += this->engine->getPrice();
	return price;
}