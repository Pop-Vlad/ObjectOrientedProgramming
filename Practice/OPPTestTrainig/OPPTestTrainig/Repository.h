# include "Models.h"

#include <vector>



class Repository {


private:

	std::vector<Team*>* teams;


public:

	Repository();

	~Repository();

	bool add(Team* new_team);

	bool update(Team* new_team);

	std::vector<Team*> getAll();
	

};