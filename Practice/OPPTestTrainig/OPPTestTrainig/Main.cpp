#include "Console.h"



int main() {
	Repository* repository = new Repository();
	Team* team_1 = new Team;
	strcpy(team_1->name, "aaa");
	strcpy(team_1->country, "bbb");
	team_1->score = 0;
	repository->add(team_1);
	Controller* controller = new Controller(repository);
	Console* console = new Console(controller);
	console->run(); 
	delete console;
	delete controller;
	delete repository;
	return 0;
}