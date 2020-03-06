
#include <string>



class User {

private:

	std::string name;
	std::string type;

public:

	User(const std::string& init_n, const std::string& init_t) : name(init_n), type(init_t) {};

	std::string getName() { return this->name; }
	std::string getType() { return this->type; }
	std::string toString() { return this->name + " " + this->type; }

};


class Issue {

private:

	std::string description;
	std::string status;
	std::string reporter;
	std::string solver;

public:

	Issue(std::string init_d, std::string init_st, std::string init_r, std::string init_so) : description(init_d), status(init_st),
		reporter(init_r), solver(init_so) {}

	std::string getDescription() { return this->description; }
	std::string getStatus() { return this->status; }
	std::string getReporter() { return this->reporter; }
	std::string getSolver() { return this->solver; }
	std::string toString() { return this->description + " " + this->status + " " + this->reporter + " " + this->solver; }

	void setStatus(std::string new_status) { this->status = new_status; }
	void setSolver(std::string new_solver) { this->solver = new_solver; }

};