#include "Repository.h"

#include <exception>



class Controller {


private:

	Repository* repository;

	Tile* robot_position;


public:

	Controller(Repository* repository, Tile* start_position);

	Tile* moveBot(char direction);

	std::vector<Tile*> getCleanedTiles();

	double getCleanedPercentage();


};


class MoveError : std::exception {

};