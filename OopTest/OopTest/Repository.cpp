#include "Repository.h"



Repository::Repository() {
	this->cleaned_tiles = new std::vector<Tile*>;
}


bool Repository::addTile(Tile* new_tile) {
	for (auto iterator = this->cleaned_tiles->begin(); iterator != this->cleaned_tiles->end(); iterator++) {
		if (((Tile*)*iterator)->x_position == new_tile->x_position && ((Tile*)*iterator)->y_position == new_tile->y_position) {
			return false;
		}
	}
	this->cleaned_tiles->push_back(new_tile);
	return true;
}


std::vector<Tile*> Repository::getCleanedTiles() {
	return *this->cleaned_tiles;
}