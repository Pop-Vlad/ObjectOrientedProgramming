#include "Repository.h"



Repository::Repository() {
	this->paintings = std::vector<Painting>{};
}


void Repository::addPainting(const Painting& p) {
	this->paintings.push_back(p);
}


void Repository::removePainting(const Painting& p) {
	for (auto iterator = this->paintings.begin(); iterator != this->paintings.end(); iterator++) {
		auto current = *iterator;
		if (p.getArtist() == current.getArtist() && p.getTitle() == current.getTitle() && p.getYear() == current.getYear()) {
			current = this->paintings.back();
			this->paintings.pop_back();
			return;
		}
	}
}