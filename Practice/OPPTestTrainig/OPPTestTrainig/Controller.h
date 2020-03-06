#include "Repository.h"

#include <string>


class Controller {


private:

	Repository* repository;


public:

	Controller(Repository* repository);

	bool add(char name[], char country[]);

	std::vector<Team*> listAll();

	bool pair(char* team_1, char* team_2, char* winner);

}