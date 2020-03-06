#include "Controller.h"



Controller::Controller(Repository* repository, Tile* start_position) {
	this->repository = repository;
	this->robot_position = new Tile;
	this->robot_position->x_position = start_position->x_position;
	this->robot_position->y_position = start_position->y_position;
	this->repository->addTile(robot_position);
}

Tile* Controller::moveBot(char direction) {
	/*
	Funtion that moves the robot.
	input - (char) direction, must be in {'u', 'd', 'r', 'l'}
	output - (Tile*) the new position of the robot
	throws - MoveError, if input is not one of the set {'u', 'd', 'r', 'l'}
	       - MoveError, the robot would move into the wall
	*/
	if (direction == 'u') {
		if (this->robot_position->y_position >= 10) {
			throw MoveError();
		}
		Tile* new_position = new Tile;
		new_position->x_position = this->robot_position->x_position;
		new_position->y_position = this->robot_position->y_position + 1;
		if (this->repository->addTile(new_position)) {
			this->robot_position = new_position;
		}
		else {
			throw MoveError();
		}
		return new_position;
	}
	else if (direction == 'r') {
		if (this->robot_position->x_position >= 10) {
			throw MoveError();
		}
		Tile* new_position = new Tile;
		new_position->x_position = this->robot_position->x_position + 1;
		new_position->y_position = this->robot_position->y_position;
		if (this->repository->addTile(new_position)) {
			this->robot_position = new_position;
		}
		else {
			throw MoveError();
		}
		return new_position;
	}
	else if (direction == 'd') {
		if (this->robot_position->y_position <= 0) {
			throw MoveError();
		}
		Tile* new_position = new Tile;
		new_position->x_position = this->robot_position->x_position;
		new_position->y_position = this->robot_position->y_position - 1;
		if (this->repository->addTile(new_position)) {
			this->robot_position = new_position;
		}
		else {
			throw MoveError();
		}
		return new_position;
	}
	else if (direction == 'l') {
		if (this->robot_position->x_position <= 0) {
			throw MoveError();
		}
		Tile* new_position = new Tile;
		new_position->x_position = this->robot_position->x_position - 1;
		new_position->y_position = this->robot_position->y_position;
		if (this->repository->addTile(new_position)) {
			this->robot_position = new_position;
		}
		else {
			throw MoveError();
		}
		return new_position;
	}
	throw MoveError();
}

std::vector<Tile*> Controller::getCleanedTiles() {
	return this->repository->getCleanedTiles();
}


double Controller::getCleanedPercentage() {
	int count;
	auto all_tiles = this->repository->getCleanedTiles();
	for (auto iterator = all_tiles.begin(); iterator != all_tiles.end(); iterator++) {
		count++;
	}
	return (double)count;
}