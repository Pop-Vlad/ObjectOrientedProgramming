#include "Models.h"

#include <vector>



class Repository {


private:

	std::vector<Tile*>* cleaned_tiles;


public:

	Repository();

	bool addTile(Tile* new_tile);

	std::vector<Tile*> getCleanedTiles();

};